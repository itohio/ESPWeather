/**
*  Copyright (C) 2018  foxis (Andrius Mikonis <andrius.mikonis@gmail.com>)
*
*  This program is free software: you can redistribute it and/or modify
*  it under the terms of the GNU General Public License as published by
*  the Free Software Foundation, either version 3 of the License, or
*  (at your option) any later version.
*
*  This program is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU General Public License for more details.
*
*  You should have received a copy of the GNU General Public License
*  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 **/
#ifndef MY_MQTT_H
#define MY_MQTT_H

#include "Config.h"
#include <PubSubClient.h>

class MQTT
{
	WiFiClient espClient;
	PubSubClient client;
	ConfigurationBase& config;
	bool announced;
	std::vector<String> listening;

public:
	static MQTT* instance;

	MQTT(ConfigurationBase& config) : config(config), client(espClient) {
		instance = this;
		announced = false;
	}

	void begin() {
		// Setup MqttClient
		client.setServer(MQTT_URL, MQTT_PORT);
		client.setCallback([](char* topic, byte* payload, unsigned int length) {
			// This will receive MQTT configuration messages
			char str[128] = "";

			memcpy(str, payload, min(sizeof(str) - 1, length));

			if (strcmp(topic, MQTT::instance->config.myName.c_str()) == 0){
				if (strcmp(str, "PING") == 0)
					MQTT::instance->client.publish("announce", MQTT::instance->config.myName.c_str());
				else if (strcmp(str, "NOSLEEP") == 0)
					MQTT::instance->config.can_sleep = false;
				else if (strcmp(str, "SLEEP") == 0)
				 MQTT::instance->config.deepsleep();
			 else if (strcmp(str, "RESTART") == 0)
		 		 MQTT::instance->config.restart();
			} else if (strcmp(topic, (MQTT::instance->config.myName + "/name").c_str()) == 0) {
				char name[128] = "";
				char *src = str;
				char *dst = name;
				while (*src)
				{
					*dst = *(src++);
					if ((*dst == ',' || *dst == ' ' || *src == '\0') && dst > name) {
						if (*src == '\0') dst++;
						*dst = '\0';
						dst = name;
						MQTT::instance->listening.push_back(name);
					} else
						dst++;
				}

				MQTT::instance->config.setMyName(MQTT::instance->listening[0]);
				MQTT::instance->listening.erase(MQTT::instance->listening.begin());
#if defined(ESP_WEATHER_VARIANT_EPAPER)
				std::vector<String>::iterator I = MQTT::instance->listening.begin();
				while (I != MQTT::instance->listening.end()) {
					MQTT::instance->client.subscribe((*I + "/temperature").c_str());
					MQTT::instance->client.subscribe((*I + "/pressure").c_str());
					MQTT::instance->client.subscribe((*I + "/humidity").c_str());
					MQTT::instance->client.subscribe((*I + "/battery").c_str());
					I++;
				}
#endif
			} else if (strcmp(topic, (MQTT::instance->config.myName + "/apadd").c_str()) == 0) {
				char ssid[128] = "";
				char passw[128] = "";
				sscanf("%s %s", ssid, passw);
				MQTT::instance->config.addAP(ssid, passw);
			} else if (strcmp(topic, (MQTT::instance->config.myName + "/apremove").c_str()) == 0) {
				MQTT::instance->config.removeAP(str);
			} else
				MQTT::instance->handle_listen_stations(topic, str);
		});
	}

	void handle_listen_stations(const char * topic, const char * data) {
		std::vector<String>::iterator I = listening.begin();
		while (I != listening.end())
		{
			if (strcmp(topic, (*I + "/temperature").c_str()) == 0)
				config.display.publish_telemetry(*I, 0, atof(data), 0, 0);
			else if (strcmp(topic, (*I + "/battery").c_str()) == 0)
				config.display.publish_telemetry(*I, atof(data), 0, 0, 0);
			else if (strcmp(topic, (*I + "/pressure").c_str()) == 0)
				config.display.publish_telemetry(*I, 0, 0, 0, atof(data));
			else if (strcmp(topic, (*I + "/humidity").c_str()) == 0)
				config.display.publish_telemetry(*I, 0, 0, atof(data), 0);
			I++;
		}
	}

	void loop(unsigned long now) {
		client.loop();

		if (config.OTA.state() == EasyOTA::EOS_STA)
		{
			if (!client.connected())
				reconnect();
			else {
				if (config.telemetry._send){
					if (!announced)
					{
						client.publish("announce", config.myName.c_str());
						config.display.publish_name(config.myName);
						announced = true;
					}
					publish_telemetry();
					config.display.publish_status(config.myName);
					config.display.publish_telemetry(config.myName, config.telemetry._battery, config.telemetry._temperature, config.telemetry._humidity, config.telemetry._pressure);
					config.telemetry._send = false;
				}
			}
		} else {
			if (config.telemetry._send) {
				config.display.publish_status("No Wifi");
				config.display.publish_telemetry(config.myName, config.telemetry._battery, config.telemetry._temperature, config.telemetry._humidity, config.telemetry._pressure);
				config.telemetry._send = false;
			}
		}
	}

	void reconnect() {
		String clientName = ARDUINO_HOSTNAME + String("-") + config.myName;
		if (client.connect(clientName.c_str(), MQTT_ID, MQTT_PASSW)) {
			// Once connected, subscribe to config topics
			client.subscribe((config.myName + "/apadd").c_str());
			client.subscribe((config.myName + "/apremove").c_str());
			client.subscribe((config.myName + "/name").c_str());
			client.subscribe((config.myName).c_str());
		} else {
			config.display.publish_status("No MQTT");
			if (config.telemetry._send) {
				config.display.publish_telemetry(config.myName, config.telemetry._battery, config.telemetry._temperature, config.telemetry._humidity, config.telemetry._pressure);
				config.telemetry._send = false;
			}
		}
	}

	void disconnect(){
		if (client.connected())
			client.disconnect();
	}

	void publish_telemetry() {
    // Publish telemetry data...
		client.publish((config.myName + "/temperature").c_str(), String(config.telemetry._temperature).c_str(), true);
		client.publish((config.myName + "/battery").c_str(), String(config.telemetry._battery).c_str(), true);
		client.publish((config.myName + "/pressure").c_str(), String(config.telemetry._pressure).c_str(), true);
    client.publish((config.myName + "/humidity").c_str(), String(config.telemetry._humidity).c_str(), true);
	}
};

MQTT* MQTT::instance = NULL;

#endif

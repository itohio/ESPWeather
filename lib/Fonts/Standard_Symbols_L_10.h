// Created by http://oleddisplay.squix.ch/ Consider a donation
// In case of problems make sure that you are using the font file with the correct version!
const uint8_t Standard_Symbols_L_10Bitmaps[] PROGMEM = {

	// Bitmap Data:
	0x00, // ' '
	0xF9, // '!'
	0x00, // '"'
	0x02,0xBE,0xAF,0xB1,0x80, // '#'
	0x00, // '$'
	0x64,0xD8,0x98,0xBF,0xF9,0x31,0x52,0x5C, // '%'
	0x18,0x50,0xA1,0xB5,0x53,0x22,0x7B, // '&'
	0x00, // '''
	0x52,0x49,0x22,0x00, // '('
	0x88,0x92,0x4A,0x00, // ')'
	0x00, // '*'
	0x21,0x3E,0x42,0x00, // '+'
	0xC0, // ','
	0x00, // '-'
	0x80, // '.'
	0x49,0x29,0x24, // '/'
	0x74,0x63,0x18,0xC6,0x2E, // '0'
	0x49,0x24,0x97, // '1'
	0x64,0x84,0x42,0x27,0xC0, // '2'
	0x71,0x27,0x11,0xE0, // '3'
	0x11,0x94,0xA9,0x7C,0x42, // '4'
	0x78,0xE1,0x11,0xE0, // '5'
	0x3B,0x11,0xE8,0xC6,0x2E, // '6'
	0x79,0x12,0x22,0x00, // '7'
	0x74,0x62,0xE5,0x46,0x2E, // '8'
	0x74,0x63,0x17,0x88,0xD8, // '9'
	0x88, // ':'
	0x88, // ';'
	0x09,0xB0,0xC1,0x80, // '<'
	0xF8,0x3E, // '='
	0xC1,0x82,0x6C,0x00, // '>'
	0xF6,0x94,0x82, // '?'
	0x00, // '@'
	0x00, // 'A'
	0x00, // 'B'
	0x00, // 'C'
	0x00, // 'D'
	0x00, // 'E'
	0x00, // 'F'
	0x00, // 'G'
	0x00, // 'H'
	0x00, // 'I'
	0x00, // 'J'
	0x00, // 'K'
	0x00, // 'L'
	0x00, // 'M'
	0x00, // 'N'
	0x00, // 'O'
	0x00, // 'P'
	0x00, // 'Q'
	0x00, // 'R'
	0x00, // 'S'
	0x00, // 'T'
	0x00, // 'U'
	0x00, // 'V'
	0x00, // 'W'
	0x00, // 'X'
	0x00, // 'Y'
	0x00, // 'Z'
	0xEA,0xAA,0xC0, // '['
	0x00, // '\'
	0xD5,0x55,0xC0, // ']'
	0x00, // '^'
	0xF8, // '_'
	0x00, // '`'
	0x00, // 'a'
	0x00, // 'b'
	0x00, // 'c'
	0x00, // 'd'
	0x00, // 'e'
	0x00, // 'f'
	0x00, // 'g'
	0x00, // 'h'
	0x00, // 'i'
	0x00, // 'j'
	0x00, // 'k'
	0x00, // 'l'
	0x00, // 'm'
	0x00, // 'n'
	0x00, // 'o'
	0x00, // 'p'
	0x00, // 'q'
	0x00, // 'r'
	0x00, // 's'
	0x00, // 't'
	0x00, // 'u'
	0x00, // 'v'
	0x00, // 'w'
	0x00, // 'x'
	0x00, // 'y'
	0x00, // 'z'
	0x69,0x28,0x92,0x40, // '{'
	0xFF, // '|'
	0xC9,0x22,0x92,0x40 // '}'
};
const GFXglyph Standard_Symbols_L_10Glyphs[] PROGMEM = {
// bitmapOffset, width, height, xAdvance, xOffset, yOffset
	  {     0,   1,   1,   4,    0,    0 }, // ' '
	  {     1,   1,   8,   4,    1,   -8 }, // '!'
	  {     2,   1,   1,   4,    0,    0 }, // '"'
	  {     3,   5,   7,   6,    0,   -7 }, // '#'
	  {     8,   1,   1,   4,    0,    0 }, // '$'
	  {     9,   8,   8,   9,    1,   -8 }, // '%'
	  {    17,   7,   8,   9,    0,   -8 }, // '&'
	  {    24,   1,   1,   4,    0,    0 }, // '''
	  {    25,   3,   9,   4,    0,   -8 }, // '('
	  {    29,   3,   9,   4,    0,   -8 }, // ')'
	  {    33,   1,   1,   4,    0,    0 }, // '*'
	  {    34,   5,   5,   6,    0,   -5 }, // '+'
	  {    38,   1,   2,   4,    1,   -1 }, // ','
	  {    39,   1,   1,   4,    0,    0 }, // '-'
	  {    40,   1,   1,   4,    1,   -1 }, // '.'
	  {    41,   3,   8,   4,    0,   -8 }, // '/'
	  {    44,   5,   8,   6,    0,   -8 }, // '0'
	  {    49,   3,   8,   6,    1,   -8 }, // '1'
	  {    52,   5,   7,   6,    0,   -7 }, // '2'
	  {    57,   4,   7,   6,    0,   -7 }, // '3'
	  {    61,   5,   8,   6,    0,   -8 }, // '4'
	  {    66,   4,   7,   6,    0,   -7 }, // '5'
	  {    70,   5,   8,   6,    0,   -8 }, // '6'
	  {    75,   4,   7,   6,    0,   -7 }, // '7'
	  {    79,   5,   8,   6,    0,   -8 }, // '8'
	  {    84,   5,   8,   6,    0,   -8 }, // '9'
	  {    89,   1,   5,   4,    1,   -5 }, // ':'
	  {    90,   1,   6,   4,    1,   -5 }, // ';'
	  {    91,   5,   5,   6,    0,   -5 }, // '<'
	  {    95,   5,   3,   6,    0,   -4 }, // '='
	  {    97,   5,   5,   6,    0,   -5 }, // '>'
	  {   101,   3,   8,   5,    1,   -8 }, // '?'
	  {   104,   1,   1,   4,    0,    0 }, // '@'
	  {   105,   1,   1,   4,    0,    0 }, // 'A'
	  {   106,   1,   1,   4,    0,    0 }, // 'B'
	  {   107,   1,   1,   4,    0,    0 }, // 'C'
	  {   108,   1,   1,   4,    0,    0 }, // 'D'
	  {   109,   1,   1,   4,    0,    0 }, // 'E'
	  {   110,   1,   1,   4,    0,    0 }, // 'F'
	  {   111,   1,   1,   4,    0,    0 }, // 'G'
	  {   112,   1,   1,   4,    0,    0 }, // 'H'
	  {   113,   1,   1,   4,    0,    0 }, // 'I'
	  {   114,   1,   1,   4,    0,    0 }, // 'J'
	  {   115,   1,   1,   4,    0,    0 }, // 'K'
	  {   116,   1,   1,   4,    0,    0 }, // 'L'
	  {   117,   1,   1,   4,    0,    0 }, // 'M'
	  {   118,   1,   1,   4,    0,    0 }, // 'N'
	  {   119,   1,   1,   4,    0,    0 }, // 'O'
	  {   120,   1,   1,   4,    0,    0 }, // 'P'
	  {   121,   1,   1,   4,    0,    0 }, // 'Q'
	  {   122,   1,   1,   4,    0,    0 }, // 'R'
	  {   123,   1,   1,   4,    0,    0 }, // 'S'
	  {   124,   1,   1,   4,    0,    0 }, // 'T'
	  {   125,   1,   1,   4,    0,    0 }, // 'U'
	  {   126,   1,   1,   4,    0,    0 }, // 'V'
	  {   127,   1,   1,   4,    0,    0 }, // 'W'
	  {   128,   1,   1,   4,    0,    0 }, // 'X'
	  {   129,   1,   1,   4,    0,    0 }, // 'Y'
	  {   130,   1,   1,   4,    0,    0 }, // 'Z'
	  {   131,   2,   9,   4,    1,   -8 }, // '['
	  {   134,   1,   1,   4,    0,    0 }, // '\'
	  {   135,   2,   9,   4,    1,   -8 }, // ']'
	  {   138,   1,   1,   4,    0,    0 }, // '^'
	  {   139,   5,   1,   6,    0,    1 }, // '_'
	  {   140,   1,   1,   4,    0,    0 }, // '`'
	  {   141,   1,   1,   4,    0,    0 }, // 'a'
	  {   142,   1,   1,   4,    0,    0 }, // 'b'
	  {   143,   1,   1,   4,    0,    0 }, // 'c'
	  {   144,   1,   1,   4,    0,    0 }, // 'd'
	  {   145,   1,   1,   4,    0,    0 }, // 'e'
	  {   146,   1,   1,   4,    0,    0 }, // 'f'
	  {   147,   1,   1,   4,    0,    0 }, // 'g'
	  {   148,   1,   1,   4,    0,    0 }, // 'h'
	  {   149,   1,   1,   4,    0,    0 }, // 'i'
	  {   150,   1,   1,   4,    0,    0 }, // 'j'
	  {   151,   1,   1,   4,    0,    0 }, // 'k'
	  {   152,   1,   1,   4,    0,    0 }, // 'l'
	  {   153,   1,   1,   4,    0,    0 }, // 'm'
	  {   154,   1,   1,   4,    0,    0 }, // 'n'
	  {   155,   1,   1,   4,    0,    0 }, // 'o'
	  {   156,   1,   1,   4,    0,    0 }, // 'p'
	  {   157,   1,   1,   4,    0,    0 }, // 'q'
	  {   158,   1,   1,   4,    0,    0 }, // 'r'
	  {   159,   1,   1,   4,    0,    0 }, // 's'
	  {   160,   1,   1,   4,    0,    0 }, // 't'
	  {   161,   1,   1,   4,    0,    0 }, // 'u'
	  {   162,   1,   1,   4,    0,    0 }, // 'v'
	  {   163,   1,   1,   4,    0,    0 }, // 'w'
	  {   164,   1,   1,   4,    0,    0 }, // 'x'
	  {   165,   1,   1,   4,    0,    0 }, // 'y'
	  {   166,   1,   1,   4,    0,    0 }, // 'z'
	  {   167,   3,   9,   6,    1,   -8 }, // '{'
	  {   171,   1,   8,   3,    1,   -8 }, // '|'
	  {   172,   3,   9,   6,    1,   -8 } // '}'
};
const GFXfont Standard_Symbols_L_10 PROGMEM = {
(uint8_t  *)Standard_Symbols_L_10Bitmaps,(GFXglyph *)Standard_Symbols_L_10Glyphs,0x20, 0x7E, 14};

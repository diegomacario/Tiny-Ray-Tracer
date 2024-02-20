// Created by http://oleddisplay.squix.ch/ Consider a donation
// In case of problems make sure that you are using the font file with the correct version!
const uint8_t DSEG14_Classic_Regular_28Bitmaps[] PROGMEM = {

	// Bitmap Data:
	0x00, // ' '
	0x00, // '!'
	0x80,0x30,0x0C,0x1F,0x07,0xC1,0xF0,0x7C,0x1F,0x07,0xC1,0xF0,0x7C,0x1F,0x02,0x80,0x00, // '"'
	0xFF,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0xFF, // '#'
	0x7F,0xFE,0x5F,0xFF,0x37,0xFF,0x18,0x38,0x0C,0x1C,0x06,0x0E,0x03,0x07,0x01,0x83,0x80,0xC1,0xC0,0x60,0xE0,0x30,0x70,0x18,0x38,0x0C,0x08,0x05,0xFB,0xF0,0xFD,0xFA,0x01,0x03,0x01,0xC3,0x80,0xE1,0xC0,0x70,0xE0,0x38,0x70,0x1C,0x38,0x0E,0x1C,0x07,0x0E,0x03,0x87,0x01,0xC3,0x8F,0xFE,0xCF,0xFF,0x8F,0xFF,0xC0, // '$'
	0x80,0x00,0x60,0x00,0x34,0x01,0x1A,0x01,0x8D,0x80,0xC6,0xE0,0xE3,0x70,0x71,0x9C,0x70,0xCE,0x38,0x63,0x18,0x31,0x88,0x18,0x00,0x0B,0xF7,0xE1,0xFB,0xF4,0x00,0x06,0x0C,0x47,0x06,0x33,0x87,0x1D,0xC3,0x8E,0xE3,0x83,0xF1,0xC1,0xF8,0xC0,0x7C,0x40,0x3E,0x20,0x0F,0x00,0x01,0x80,0x00,0x00, // '%'
	0xFF,0xFC,0x7F,0xFC,0x3F,0xF8,0x20,0x08,0x20,0x18,0x30,0x18,0x38,0x38,0x38,0x38,0x1C,0x70,0x1C,0x70,0x0C,0x60,0x0C,0x40,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x03,0x0C,0x47,0x0C,0x67,0x1C,0x77,0x1C,0x77,0x38,0x3F,0x38,0x3F,0x30,0x1F,0x20,0x1F,0x20,0x0F,0x3F,0xFB,0x7F,0xFC,0xFF,0xFC, // '&'
	0xFF,0xFF,0xFF,0xE8, // '''
	0x13,0x37,0x7E,0xEC,0x80,0x00,0x08,0xCE,0xE7,0x73,0x31, // '('
	0x88,0xCE,0xE7,0x73,0x30,0x00,0x03,0x37,0x7E,0xEC,0x88, // ')'
	0x23,0x88,0x47,0x30,0xCE,0x61,0xDD,0xC3,0xBB,0x83,0xFE,0x07,0xFC,0x07,0xF0,0x0F,0xC0,0x02,0x01,0xFB,0xF3,0xF7,0xE0,0x10,0x01,0xF8,0x03,0xF8,0x0F,0xF8,0x1F,0xF0,0x77,0x70,0xEE,0xE1,0x9C,0xC2,0x39,0x84,0x71,0x00, // '*'
	0x03,0x80,0x07,0x00,0x0E,0x00,0x1C,0x00,0x38,0x00,0x70,0x00,0xE0,0x01,0xC0,0x03,0x80,0x02,0x01,0xFB,0xF3,0xF7,0xE0,0x10,0x00,0x70,0x00,0xE0,0x01,0xC0,0x03,0x80,0x07,0x00,0x0E,0x00,0x1C,0x00,0x38,0x00,0x70,0x00, // '+'
	0x33,0x77,0xEE,0xC8,0x80, // ','
	0x7E,0xFC,0xFD,0xF8, // '-'
	0xFF,0x60, // '.'
	0x00,0x20,0x0C,0x01,0x80,0x70,0x0E,0x03,0x80,0x70,0x0C,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x0C,0x03,0x80,0x70,0x1C,0x03,0x80,0x60,0x08,0x01,0x00,0x00, // '/'
	0x7F,0xFE,0x5F,0xFF,0x37,0xFF,0x78,0x00,0xFC,0x00,0xFE,0x00,0x7F,0x00,0x7F,0x80,0x3F,0xC0,0x3B,0xE0,0x1D,0xF0,0x0C,0xF8,0x04,0x7C,0x00,0x1C,0x00,0x06,0x00,0x03,0x80,0x03,0xC6,0x03,0xE3,0x01,0xF3,0x80,0xF9,0xC0,0x7D,0xC0,0x3E,0xE0,0x1F,0x60,0x0F,0xA0,0x07,0xD0,0x03,0xEF,0xFE,0xEF,0xFF,0x8F,0xFF,0xC0, // '0'
	0x0F,0xFF,0xFF,0xFF,0xB2,0x5F,0xFF,0xFF,0xFF,0x60, // '1'
	0x7F,0xFE,0x1F,0xFF,0x07,0xFF,0x60,0x00,0x70,0x00,0x38,0x00,0x1C,0x00,0x0E,0x00,0x07,0x00,0x03,0x80,0x01,0xC0,0x00,0xE0,0x00,0x70,0x00,0x19,0xFB,0xF6,0xFD,0xF9,0x80,0x00,0xC0,0x00,0x60,0x00,0x30,0x00,0x18,0x00,0x0C,0x00,0x06,0x00,0x03,0x00,0x01,0x80,0x00,0xC0,0x00,0x6F,0xFE,0x2F,0xFF,0x8F,0xFF,0xC0, // '2'
	0xFF,0xFC,0x7F,0xFC,0x3F,0xFB,0x00,0x07,0x00,0x07,0x00,0x07,0x00,0x07,0x00,0x07,0x00,0x07,0x00,0x07,0x00,0x07,0x00,0x07,0x00,0x03,0x7E,0xFD,0x7E,0xFD,0x00,0x03,0x00,0x07,0x00,0x07,0x00,0x07,0x00,0x07,0x00,0x07,0x00,0x07,0x00,0x07,0x00,0x07,0x00,0x07,0x3F,0xFB,0x7F,0xFC,0xFF,0xFC, // '3'
	0x80,0x00,0x60,0x00,0xF0,0x00,0xF8,0x00,0x7C,0x00,0x3E,0x00,0x1F,0x00,0x0F,0x80,0x07,0xC0,0x03,0xE0,0x01,0xF0,0x00,0xF8,0x00,0x3B,0xF7,0xE9,0xFB,0xF4,0x00,0x06,0x00,0x07,0x00,0x03,0x80,0x01,0xC0,0x00,0xE0,0x00,0x70,0x00,0x38,0x00,0x1C,0x00,0x0E,0x00,0x07,0x00,0x01,0x80,0x00,0x00, // '4'
	0x7F,0xFE,0x5F,0xFF,0x37,0xFF,0x18,0x00,0x0C,0x00,0x06,0x00,0x03,0x00,0x01,0x80,0x00,0xC0,0x00,0x60,0x00,0x30,0x00,0x18,0x00,0x0C,0x00,0x05,0xFB,0xF0,0xFD,0xFA,0x00,0x03,0x00,0x03,0x80,0x01,0xC0,0x00,0xE0,0x00,0x70,0x00,0x38,0x00,0x1C,0x00,0x0E,0x00,0x07,0x00,0x03,0x8F,0xFE,0xCF,0xFF,0x8F,0xFF,0xC0, // '5'
	0x7F,0xFE,0x5F,0xFF,0x37,0xFF,0x18,0x00,0x0C,0x00,0x06,0x00,0x03,0x00,0x01,0x80,0x00,0xC0,0x00,0x60,0x00,0x30,0x00,0x18,0x00,0x0C,0x00,0x05,0xFB,0xF2,0xFD,0xFB,0x80,0x03,0xC0,0x03,0xE0,0x01,0xF0,0x00,0xF8,0x00,0x7C,0x00,0x3E,0x00,0x1F,0x00,0x0F,0x80,0x07,0xC0,0x03,0xEF,0xFE,0xEF,0xFF,0x8F,0xFF,0xC0, // '6'
	0x7F,0xFE,0x5F,0xFF,0x37,0xFF,0x78,0x00,0x7C,0x00,0x3E,0x00,0x1F,0x00,0x0F,0x80,0x07,0xC0,0x03,0xE0,0x01,0xF0,0x00,0xF8,0x00,0x7C,0x00,0x1C,0x00,0x04,0x00,0x02,0x00,0x03,0x00,0x03,0x80,0x01,0xC0,0x00,0xE0,0x00,0x70,0x00,0x38,0x00,0x1C,0x00,0x0E,0x00,0x07,0x00,0x03,0x80,0x00,0xC0,0x00,0x00, // '7'
	0x7F,0xFE,0x5F,0xFF,0x37,0xFF,0x78,0x00,0x7C,0x00,0x3E,0x00,0x1F,0x00,0x0F,0x80,0x07,0xC0,0x03,0xE0,0x01,0xF0,0x00,0xF8,0x00,0x7C,0x00,0x1D,0xFB,0xF6,0xFD,0xFB,0x80,0x03,0xC0,0x03,0xE0,0x01,0xF0,0x00,0xF8,0x00,0x7C,0x00,0x3E,0x00,0x1F,0x00,0x0F,0x80,0x07,0xC0,0x03,0xEF,0xFE,0xEF,0xFF,0x8F,0xFF,0xC0, // '8'
	0x7F,0xFE,0x5F,0xFF,0x37,0xFF,0x78,0x00,0x7C,0x00,0x3E,0x00,0x1F,0x00,0x0F,0x80,0x07,0xC0,0x03,0xE0,0x01,0xF0,0x00,0xF8,0x00,0x7C,0x00,0x1D,0xFB,0xF4,0xFD,0xFA,0x00,0x03,0x00,0x03,0x80,0x01,0xC0,0x00,0xE0,0x00,0x70,0x00,0x38,0x00,0x1C,0x00,0x0E,0x00,0x07,0x00,0x03,0x8F,0xFE,0xCF,0xFF,0x8F,0xFF,0xC0, // '9'
	0xEF,0xE0,0x00,0x00,0x00,0x04,0xEE,0x60, // ':'
	0xFF,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0xFF, // ';'
	0x00,0x08,0x00,0x30,0x00,0x60,0x01,0xC0,0x03,0x80,0x0E,0x00,0x1C,0x00,0x30,0x00,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x03,0x00,0x0E,0x00,0x1C,0x00,0x70,0x00,0xE0,0x01,0x80,0x02,0x00,0x04,0x00,0x0F,0xFE,0x3F,0xFE,0xFF,0xFC, // '<'
	0x7E,0xFC,0xFD,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xFF,0x8F,0xFF,0xBF,0xFF,0x00, // '='
	0x20,0x00,0x40,0x00,0xC0,0x01,0xC0,0x03,0x80,0x03,0x80,0x07,0x00,0x06,0x00,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x18,0x00,0x38,0x00,0x70,0x00,0x70,0x00,0xE0,0x00,0xC0,0x01,0x80,0x01,0x0F,0xFE,0x3F,0xFE,0xFF,0xFC, // '>'
	0x7F,0xFE,0x5F,0xFF,0x37,0xFF,0x78,0x00,0x7C,0x00,0x3E,0x00,0x1F,0x00,0x0F,0x80,0x07,0xC0,0x03,0xE0,0x01,0xF0,0x00,0xF8,0x00,0x7C,0x00,0x1C,0x03,0xF4,0x01,0xF8,0x01,0x00,0x01,0xC0,0x00,0xE0,0x00,0x70,0x00,0x38,0x00,0x1C,0x00,0x0E,0x00,0x07,0x00,0x03,0x80,0x01,0xC0,0x00, // '?'
	0x7F,0xFE,0x5F,0xFF,0x37,0xFF,0x78,0x00,0x7C,0x00,0x3E,0x00,0x1F,0x00,0x0F,0x80,0x07,0xC0,0x03,0xE0,0x01,0xF0,0x00,0xF8,0x00,0x7C,0x00,0x1C,0x03,0xF6,0x01,0xFB,0x81,0x03,0xC1,0xC3,0xE0,0xE1,0xF0,0x70,0xF8,0x38,0x7C,0x1C,0x3E,0x0E,0x1F,0x07,0x0F,0x83,0x87,0xC1,0xC3,0xEF,0xFE,0xEF,0xFF,0x8F,0xFF,0xC0, // '@'
	0x7F,0xFE,0x5F,0xFF,0x37,0xFF,0x78,0x00,0x7C,0x00,0x3E,0x00,0x1F,0x00,0x0F,0x80,0x07,0xC0,0x03,0xE0,0x01,0xF0,0x00,0xF8,0x00,0x7C,0x00,0x1D,0xFB,0xF6,0xFD,0xFB,0x80,0x03,0xC0,0x03,0xE0,0x01,0xF0,0x00,0xF8,0x00,0x7C,0x00,0x3E,0x00,0x1F,0x00,0x0F,0x80,0x07,0xC0,0x03,0xE0,0x00,0xE0,0x00,0x00, // 'A'
	0xFF,0xFC,0x7F,0xFC,0x3F,0xFB,0x03,0x87,0x03,0x87,0x03,0x87,0x03,0x87,0x03,0x87,0x03,0x87,0x03,0x87,0x03,0x87,0x03,0x87,0x01,0x03,0x00,0xFD,0x00,0xFD,0x01,0x03,0x03,0x87,0x03,0x87,0x03,0x87,0x03,0x87,0x03,0x87,0x03,0x87,0x03,0x87,0x03,0x87,0x03,0x87,0x3F,0xFB,0x7F,0xFC,0xFF,0xFC, // 'B'
	0x7F,0xFE,0xBF,0xFE,0xDF,0xFC,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0x80,0x00,0x80,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xDF,0xFC,0xBF,0xFE,0x7F,0xFE, // 'C'
	0xFF,0xFC,0x7F,0xFC,0x3F,0xFB,0x03,0x87,0x03,0x87,0x03,0x87,0x03,0x87,0x03,0x87,0x03,0x87,0x03,0x87,0x03,0x87,0x03,0x87,0x01,0x03,0x00,0x01,0x00,0x01,0x01,0x03,0x03,0x87,0x03,0x87,0x03,0x87,0x03,0x87,0x03,0x87,0x03,0x87,0x03,0x87,0x03,0x87,0x03,0x87,0x3F,0xFB,0x7F,0xFC,0xFF,0xFC, // 'D'
	0x7F,0xFE,0xBF,0xFE,0xDF,0xFC,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xBF,0x7E,0xBF,0x7E,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xDF,0xFC,0xBF,0xFE,0x7F,0xFE, // 'E'
	0x7F,0xFE,0xBF,0xFE,0xDF,0xFC,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xBF,0x7E,0xBF,0x7E,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0x80,0x00, // 'F'
	0x7F,0xFE,0x5F,0xFF,0x37,0xFF,0x18,0x00,0x0C,0x00,0x06,0x00,0x03,0x00,0x01,0x80,0x00,0xC0,0x00,0x60,0x00,0x30,0x00,0x18,0x00,0x0C,0x00,0x04,0x03,0xF2,0x01,0xFB,0x80,0x03,0xC0,0x03,0xE0,0x01,0xF0,0x00,0xF8,0x00,0x7C,0x00,0x3E,0x00,0x1F,0x00,0x0F,0x80,0x07,0xC0,0x03,0xEF,0xFE,0xEF,0xFF,0x8F,0xFF,0xC0, // 'G'
	0x80,0x00,0x60,0x00,0xF0,0x00,0xF8,0x00,0x7C,0x00,0x3E,0x00,0x1F,0x00,0x0F,0x80,0x07,0xC0,0x03,0xE0,0x01,0xF0,0x00,0xF8,0x00,0x3B,0xF7,0xED,0xFB,0xF7,0x00,0x07,0x80,0x07,0xC0,0x03,0xE0,0x01,0xF0,0x00,0xF8,0x00,0x7C,0x00,0x3E,0x00,0x1F,0x00,0x0F,0x80,0x07,0xC0,0x01,0xC0,0x00,0x00, // 'H'
	0xFF,0xFC,0xFF,0xF8,0xFF,0xE0,0x1C,0x00,0x38,0x00,0x70,0x00,0xE0,0x01,0xC0,0x03,0x80,0x07,0x00,0x0E,0x00,0x1C,0x00,0x10,0x00,0x00,0x00,0x00,0x00,0x80,0x03,0x80,0x07,0x00,0x0E,0x00,0x1C,0x00,0x38,0x00,0x70,0x00,0xE0,0x01,0xC0,0x03,0x80,0x7F,0xF1,0xFF,0xF7,0xFF,0xE0, // 'I'
	0x00,0x00,0x00,0x00,0xC0,0x00,0xE0,0x00,0x70,0x00,0x38,0x00,0x1C,0x00,0x0E,0x00,0x07,0x00,0x03,0x80,0x01,0xC0,0x00,0xE0,0x00,0x30,0x00,0x0C,0x00,0x07,0x00,0x07,0x80,0x07,0xC0,0x03,0xE0,0x01,0xF0,0x00,0xF8,0x00,0x7C,0x00,0x3E,0x00,0x1F,0x00,0x0F,0x80,0x07,0xDF,0xFD,0xDF,0xFF,0x1F,0xFF,0x80, // 'J'
	0x80,0x03,0x00,0x0C,0x00,0x70,0x03,0xC0,0x0F,0x00,0x7C,0x01,0xF0,0x0E,0xC0,0x3B,0x00,0xCC,0x02,0x30,0x00,0xBF,0x02,0xFC,0x0C,0x00,0x30,0x08,0xC0,0x33,0x00,0xEC,0x03,0xB0,0x07,0xC0,0x1F,0x00,0x3C,0x00,0xF0,0x01,0xC0,0x02,0x00,0x00, // 'K'
	0x80,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0x80,0x00,0x80,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xDF,0xFC,0xBF,0xFE,0x7F,0xFE, // 'L'
	0x80,0x00,0x60,0x00,0xF4,0x01,0xFA,0x01,0xFD,0x80,0xFE,0xE0,0xFF,0x70,0x7F,0x9C,0x77,0xCE,0x3B,0xE3,0x19,0xF1,0x88,0xF8,0x00,0x38,0x00,0x0C,0x00,0x07,0x02,0x07,0x83,0x87,0xC1,0xC3,0xE0,0xE1,0xF0,0x70,0xF8,0x38,0x7C,0x1C,0x3E,0x0E,0x1F,0x07,0x0F,0x83,0x87,0xC0,0x01,0xC0,0x00,0x00, // 'M'
	0x80,0x00,0x60,0x00,0xF4,0x00,0xFA,0x00,0x7D,0x80,0x3E,0xE0,0x1F,0x70,0x0F,0x9C,0x07,0xCE,0x03,0xE3,0x01,0xF1,0x80,0xF8,0x00,0x38,0x00,0x0C,0x00,0x07,0x00,0x07,0x80,0x47,0xC0,0x33,0xE0,0x1D,0xF0,0x0E,0xF8,0x03,0xFC,0x01,0xFE,0x00,0x7F,0x00,0x3F,0x80,0x0F,0xC0,0x01,0xC0,0x00,0x00, // 'N'
	0x7F,0xFE,0x5F,0xFF,0x37,0xFF,0x78,0x00,0x7C,0x00,0x3E,0x00,0x1F,0x00,0x0F,0x80,0x07,0xC0,0x03,0xE0,0x01,0xF0,0x00,0xF8,0x00,0x7C,0x00,0x1C,0x00,0x06,0x00,0x03,0x80,0x03,0xC0,0x03,0xE0,0x01,0xF0,0x00,0xF8,0x00,0x7C,0x00,0x3E,0x00,0x1F,0x00,0x0F,0x80,0x07,0xC0,0x03,0xEF,0xFE,0xEF,0xFF,0x8F,0xFF,0xC0, // 'O'
	0x7F,0xFE,0x5F,0xFF,0x37,0xFF,0x78,0x00,0x7C,0x00,0x3E,0x00,0x1F,0x00,0x0F,0x80,0x07,0xC0,0x03,0xE0,0x01,0xF0,0x00,0xF8,0x00,0x7C,0x00,0x1D,0xFB,0xF6,0xFD,0xF9,0x80,0x00,0xC0,0x00,0x60,0x00,0x30,0x00,0x18,0x00,0x0C,0x00,0x06,0x00,0x03,0x00,0x01,0x80,0x00,0xC0,0x00,0x60,0x00,0x20,0x00,0x00, // 'P'
	0x7F,0xFE,0x5F,0xFF,0x37,0xFF,0x78,0x00,0x7C,0x00,0x3E,0x00,0x1F,0x00,0x0F,0x80,0x07,0xC0,0x03,0xE0,0x01,0xF0,0x00,0xF8,0x00,0x7C,0x00,0x1C,0x00,0x06,0x00,0x03,0x80,0x03,0xC0,0x23,0xE0,0x19,0xF0,0x0E,0xF8,0x07,0x7C,0x01,0xFE,0x00,0xFF,0x00,0x3F,0x80,0x1F,0xC0,0x07,0xEF,0xFE,0xEF,0xFF,0x8F,0xFF,0xC0, // 'Q'
	0x7F,0xFE,0x5F,0xFF,0x37,0xFF,0x78,0x00,0x7C,0x00,0x3E,0x00,0x1F,0x00,0x0F,0x80,0x07,0xC0,0x03,0xE0,0x01,0xF0,0x00,0xF8,0x00,0x7C,0x00,0x1D,0xFB,0xF6,0xFD,0xF9,0x80,0x00,0xC0,0x20,0x60,0x18,0x30,0x0E,0x18,0x07,0x0C,0x01,0xC6,0x00,0xE3,0x00,0x31,0x80,0x18,0xC0,0x04,0x60,0x00,0x20,0x00,0x00, // 'R'
	0x7F,0xFE,0x5F,0xFF,0x37,0xFF,0x1A,0x00,0x0D,0x00,0x06,0xC0,0x03,0x70,0x01,0xB8,0x00,0xCE,0x00,0x67,0x00,0x31,0x80,0x18,0xC0,0x0C,0x00,0x05,0xFB,0xF0,0xFD,0xFA,0x00,0x03,0x00,0x23,0x80,0x19,0xC0,0x0E,0xE0,0x07,0x70,0x01,0xF8,0x00,0xFC,0x00,0x3E,0x00,0x1F,0x00,0x07,0x8F,0xFE,0xCF,0xFF,0x8F,0xFF,0xC0, // 'S'
	0xFF,0xFC,0xFF,0xF8,0xFF,0xE0,0x1C,0x00,0x38,0x00,0x70,0x00,0xE0,0x01,0xC0,0x03,0x80,0x07,0x00,0x0E,0x00,0x1C,0x00,0x10,0x00,0x00,0x00,0x00,0x00,0x80,0x03,0x80,0x07,0x00,0x0E,0x00,0x1C,0x00,0x38,0x00,0x70,0x00,0xE0,0x01,0xC0,0x03,0x80, // 'T'
	0x80,0x00,0x60,0x00,0xF0,0x00,0xF8,0x00,0x7C,0x00,0x3E,0x00,0x1F,0x00,0x0F,0x80,0x07,0xC0,0x03,0xE0,0x01,0xF0,0x00,0xF8,0x00,0x38,0x00,0x0C,0x00,0x07,0x00,0x07,0x80,0x07,0xC0,0x03,0xE0,0x01,0xF0,0x00,0xF8,0x00,0x7C,0x00,0x3E,0x00,0x1F,0x00,0x0F,0x80,0x07,0xDF,0xFD,0xDF,0xFF,0x1F,0xFF,0x80, // 'U'
	0x80,0x03,0x00,0x0C,0x00,0x70,0x03,0xC0,0x0F,0x00,0x7C,0x01,0xF0,0x0E,0xC0,0x3B,0x00,0xCC,0x02,0x30,0x00,0x80,0x02,0x00,0x0C,0x00,0x31,0x80,0xC6,0x03,0x38,0x0C,0xE0,0x37,0x00,0xDC,0x03,0x60,0x0D,0x00,0x34,0x00,0xC0,0x02,0x00,0x00, // 'V'
	0x80,0x00,0x60,0x00,0xF0,0x70,0xF8,0x38,0x7C,0x1C,0x3E,0x0E,0x1F,0x07,0x0F,0x83,0x87,0xC1,0xC3,0xE0,0xE1,0xF0,0x70,0xF8,0x10,0x38,0x00,0x0C,0x00,0x07,0x00,0x07,0x8C,0x47,0xC6,0x33,0xE7,0x1D,0xF3,0x8E,0xFB,0x83,0xFD,0xC1,0xFE,0xC0,0x7F,0x40,0x3F,0xA0,0x0F,0xC0,0x01,0xC0,0x00,0x00, // 'W'
	0x80,0x30,0x0F,0x01,0xF0,0x7E,0x0E,0xE3,0x9C,0x71,0x8C,0x31,0x00,0x00,0x00,0x00,0x00,0x00,0x62,0x0C,0x63,0x8E,0x71,0xDC,0x1F,0x83,0xE0,0x38,0x07,0x00,0x40, // 'X'
	0x80,0x30,0x0F,0x01,0xF0,0x7E,0x0E,0xE3,0x9C,0x71,0x8C,0x31,0x00,0x00,0x00,0x00,0x00,0x40,0x1C,0x03,0x80,0x70,0x0E,0x01,0xC0,0x38,0x07,0x00,0xE0,0x1C,0x00, // 'Y'
	0xFF,0xFC,0xFF,0xF8,0xFF,0xE0,0x00,0x40,0x01,0x80,0x03,0x00,0x0E,0x00,0x1C,0x00,0x70,0x00,0xE0,0x01,0x80,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x00,0x18,0x00,0x70,0x00,0xE0,0x03,0x80,0x07,0x00,0x0C,0x00,0x10,0x00,0x20,0x00,0x7F,0xF1,0xFF,0xF7,0xFF,0xE0, // 'Z'
	0xFF,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0xFF, // '['
	0x80,0x10,0x03,0x00,0x70,0x0E,0x00,0xE0,0x1C,0x01,0x80,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x60,0x0E,0x01,0xC0,0x1C,0x03,0x80,0x30,0x06,0x00,0x40, // '\'
	0xFF,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0xFF, // ']'
	0x81,0x83,0x46,0x8D,0x9B,0xB7,0x67,0xCF,0x8F,0x1E,0x08,0x00, // '^'
	0x3F,0xF8,0xFF,0xFB,0xFF,0xF0, // '_'
	0x88,0xCE,0xE7,0x73,0x30, // '`'
	0x7F,0xFE,0x5F,0xFF,0x37,0xFF,0x78,0x00,0x7C,0x00,0x3E,0x00,0x1F,0x00,0x0F,0x80,0x07,0xC0,0x03,0xE0,0x01,0xF0,0x00,0xF8,0x00,0x7C,0x00,0x1D,0xFB,0xF6,0xFD,0xFB,0x80,0x03,0xC0,0x03,0xE0,0x01,0xF0,0x00,0xF8,0x00,0x7C,0x00,0x3E,0x00,0x1F,0x00,0x0F,0x80,0x07,0xC0,0x03,0xE0,0x00,0xE0,0x00,0x00, // 'a'
	0xFF,0xFC,0x7F,0xFC,0x3F,0xFB,0x03,0x87,0x03,0x87,0x03,0x87,0x03,0x87,0x03,0x87,0x03,0x87,0x03,0x87,0x03,0x87,0x03,0x87,0x01,0x03,0x00,0xFD,0x00,0xFD,0x01,0x03,0x03,0x87,0x03,0x87,0x03,0x87,0x03,0x87,0x03,0x87,0x03,0x87,0x03,0x87,0x03,0x87,0x03,0x87,0x3F,0xFB,0x7F,0xFC,0xFF,0xFC, // 'b'
	0x7F,0xFE,0xBF,0xFE,0xDF,0xFC,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0x80,0x00,0x80,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xDF,0xFC,0xBF,0xFE,0x7F,0xFE, // 'c'
	0xFF,0xFC,0x7F,0xFC,0x3F,0xFB,0x03,0x87,0x03,0x87,0x03,0x87,0x03,0x87,0x03,0x87,0x03,0x87,0x03,0x87,0x03,0x87,0x03,0x87,0x01,0x03,0x00,0x01,0x00,0x01,0x01,0x03,0x03,0x87,0x03,0x87,0x03,0x87,0x03,0x87,0x03,0x87,0x03,0x87,0x03,0x87,0x03,0x87,0x03,0x87,0x3F,0xFB,0x7F,0xFC,0xFF,0xFC, // 'd'
	0x7F,0xFE,0xBF,0xFE,0xDF,0xFC,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xBF,0x7E,0xBF,0x7E,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xDF,0xFC,0xBF,0xFE,0x7F,0xFE, // 'e'
	0x7F,0xFE,0xBF,0xFE,0xDF,0xFC,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xBF,0x7E,0xBF,0x7E,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0x80,0x00, // 'f'
	0x7F,0xFE,0x5F,0xFF,0x37,0xFF,0x18,0x00,0x0C,0x00,0x06,0x00,0x03,0x00,0x01,0x80,0x00,0xC0,0x00,0x60,0x00,0x30,0x00,0x18,0x00,0x0C,0x00,0x04,0x03,0xF2,0x01,0xFB,0x80,0x03,0xC0,0x03,0xE0,0x01,0xF0,0x00,0xF8,0x00,0x7C,0x00,0x3E,0x00,0x1F,0x00,0x0F,0x80,0x07,0xC0,0x03,0xEF,0xFE,0xEF,0xFF,0x8F,0xFF,0xC0, // 'g'
	0x80,0x00,0x60,0x00,0xF0,0x00,0xF8,0x00,0x7C,0x00,0x3E,0x00,0x1F,0x00,0x0F,0x80,0x07,0xC0,0x03,0xE0,0x01,0xF0,0x00,0xF8,0x00,0x3B,0xF7,0xED,0xFB,0xF7,0x00,0x07,0x80,0x07,0xC0,0x03,0xE0,0x01,0xF0,0x00,0xF8,0x00,0x7C,0x00,0x3E,0x00,0x1F,0x00,0x0F,0x80,0x07,0xC0,0x01,0xC0,0x00,0x00, // 'h'
	0xFF,0xFC,0xFF,0xF8,0xFF,0xE0,0x1C,0x00,0x38,0x00,0x70,0x00,0xE0,0x01,0xC0,0x03,0x80,0x07,0x00,0x0E,0x00,0x1C,0x00,0x10,0x00,0x00,0x00,0x00,0x00,0x80,0x03,0x80,0x07,0x00,0x0E,0x00,0x1C,0x00,0x38,0x00,0x70,0x00,0xE0,0x01,0xC0,0x03,0x80,0x7F,0xF1,0xFF,0xF7,0xFF,0xE0, // 'i'
	0x00,0x00,0x00,0x00,0xC0,0x00,0xE0,0x00,0x70,0x00,0x38,0x00,0x1C,0x00,0x0E,0x00,0x07,0x00,0x03,0x80,0x01,0xC0,0x00,0xE0,0x00,0x30,0x00,0x0C,0x00,0x07,0x00,0x07,0x80,0x07,0xC0,0x03,0xE0,0x01,0xF0,0x00,0xF8,0x00,0x7C,0x00,0x3E,0x00,0x1F,0x00,0x0F,0x80,0x07,0xDF,0xFD,0xDF,0xFF,0x1F,0xFF,0x80, // 'j'
	0x80,0x03,0x00,0x0C,0x00,0x70,0x03,0xC0,0x0F,0x00,0x7C,0x01,0xF0,0x0E,0xC0,0x3B,0x00,0xCC,0x02,0x30,0x00,0xBF,0x02,0xFC,0x0C,0x00,0x30,0x08,0xC0,0x33,0x00,0xEC,0x03,0xB0,0x07,0xC0,0x1F,0x00,0x3C,0x00,0xF0,0x01,0xC0,0x02,0x00,0x00, // 'k'
	0x80,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0x80,0x00,0x80,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xDF,0xFC,0xBF,0xFE,0x7F,0xFE, // 'l'
	0x80,0x00,0x60,0x00,0xF4,0x01,0xFA,0x01,0xFD,0x80,0xFE,0xE0,0xFF,0x70,0x7F,0x9C,0x77,0xCE,0x3B,0xE3,0x19,0xF1,0x88,0xF8,0x00,0x38,0x00,0x0C,0x00,0x07,0x02,0x07,0x83,0x87,0xC1,0xC3,0xE0,0xE1,0xF0,0x70,0xF8,0x38,0x7C,0x1C,0x3E,0x0E,0x1F,0x07,0x0F,0x83,0x87,0xC0,0x01,0xC0,0x00,0x00, // 'm'
	0x80,0x00,0x60,0x00,0xF4,0x00,0xFA,0x00,0x7D,0x80,0x3E,0xE0,0x1F,0x70,0x0F,0x9C,0x07,0xCE,0x03,0xE3,0x01,0xF1,0x80,0xF8,0x00,0x38,0x00,0x0C,0x00,0x07,0x00,0x07,0x80,0x47,0xC0,0x33,0xE0,0x1D,0xF0,0x0E,0xF8,0x03,0xFC,0x01,0xFE,0x00,0x7F,0x00,0x3F,0x80,0x0F,0xC0,0x01,0xC0,0x00,0x00, // 'n'
	0x7F,0xFE,0x5F,0xFF,0x37,0xFF,0x78,0x00,0x7C,0x00,0x3E,0x00,0x1F,0x00,0x0F,0x80,0x07,0xC0,0x03,0xE0,0x01,0xF0,0x00,0xF8,0x00,0x7C,0x00,0x1C,0x00,0x06,0x00,0x03,0x80,0x03,0xC0,0x03,0xE0,0x01,0xF0,0x00,0xF8,0x00,0x7C,0x00,0x3E,0x00,0x1F,0x00,0x0F,0x80,0x07,0xC0,0x03,0xEF,0xFE,0xEF,0xFF,0x8F,0xFF,0xC0, // 'o'
	0x7F,0xFE,0x5F,0xFF,0x37,0xFF,0x78,0x00,0x7C,0x00,0x3E,0x00,0x1F,0x00,0x0F,0x80,0x07,0xC0,0x03,0xE0,0x01,0xF0,0x00,0xF8,0x00,0x7C,0x00,0x1D,0xFB,0xF6,0xFD,0xF9,0x80,0x00,0xC0,0x00,0x60,0x00,0x30,0x00,0x18,0x00,0x0C,0x00,0x06,0x00,0x03,0x00,0x01,0x80,0x00,0xC0,0x00,0x60,0x00,0x20,0x00,0x00, // 'p'
	0x7F,0xFE,0x5F,0xFF,0x37,0xFF,0x78,0x00,0x7C,0x00,0x3E,0x00,0x1F,0x00,0x0F,0x80,0x07,0xC0,0x03,0xE0,0x01,0xF0,0x00,0xF8,0x00,0x7C,0x00,0x1C,0x00,0x06,0x00,0x03,0x80,0x03,0xC0,0x23,0xE0,0x19,0xF0,0x0E,0xF8,0x07,0x7C,0x01,0xFE,0x00,0xFF,0x00,0x3F,0x80,0x1F,0xC0,0x07,0xEF,0xFE,0xEF,0xFF,0x8F,0xFF,0xC0, // 'q'
	0x7F,0xFE,0x5F,0xFF,0x37,0xFF,0x78,0x00,0x7C,0x00,0x3E,0x00,0x1F,0x00,0x0F,0x80,0x07,0xC0,0x03,0xE0,0x01,0xF0,0x00,0xF8,0x00,0x7C,0x00,0x1D,0xFB,0xF6,0xFD,0xF9,0x80,0x00,0xC0,0x20,0x60,0x18,0x30,0x0E,0x18,0x07,0x0C,0x01,0xC6,0x00,0xE3,0x00,0x31,0x80,0x18,0xC0,0x04,0x60,0x00,0x20,0x00,0x00, // 'r'
	0x7F,0xFE,0x5F,0xFF,0x37,0xFF,0x1A,0x00,0x0D,0x00,0x06,0xC0,0x03,0x70,0x01,0xB8,0x00,0xCE,0x00,0x67,0x00,0x31,0x80,0x18,0xC0,0x0C,0x00,0x05,0xFB,0xF0,0xFD,0xFA,0x00,0x03,0x00,0x23,0x80,0x19,0xC0,0x0E,0xE0,0x07,0x70,0x01,0xF8,0x00,0xFC,0x00,0x3E,0x00,0x1F,0x00,0x07,0x8F,0xFE,0xCF,0xFF,0x8F,0xFF,0xC0, // 's'
	0xFF,0xFC,0xFF,0xF8,0xFF,0xE0,0x1C,0x00,0x38,0x00,0x70,0x00,0xE0,0x01,0xC0,0x03,0x80,0x07,0x00,0x0E,0x00,0x1C,0x00,0x10,0x00,0x00,0x00,0x00,0x00,0x80,0x03,0x80,0x07,0x00,0x0E,0x00,0x1C,0x00,0x38,0x00,0x70,0x00,0xE0,0x01,0xC0,0x03,0x80, // 't'
	0x80,0x00,0x60,0x00,0xF0,0x00,0xF8,0x00,0x7C,0x00,0x3E,0x00,0x1F,0x00,0x0F,0x80,0x07,0xC0,0x03,0xE0,0x01,0xF0,0x00,0xF8,0x00,0x38,0x00,0x0C,0x00,0x07,0x00,0x07,0x80,0x07,0xC0,0x03,0xE0,0x01,0xF0,0x00,0xF8,0x00,0x7C,0x00,0x3E,0x00,0x1F,0x00,0x0F,0x80,0x07,0xDF,0xFD,0xDF,0xFF,0x1F,0xFF,0x80, // 'u'
	0x80,0x03,0x00,0x0C,0x00,0x70,0x03,0xC0,0x0F,0x00,0x7C,0x01,0xF0,0x0E,0xC0,0x3B,0x00,0xCC,0x02,0x30,0x00,0x80,0x02,0x00,0x0C,0x00,0x31,0x80,0xC6,0x03,0x38,0x0C,0xE0,0x37,0x00,0xDC,0x03,0x60,0x0D,0x00,0x34,0x00,0xC0,0x02,0x00,0x00, // 'v'
	0x80,0x00,0x60,0x00,0xF0,0x70,0xF8,0x38,0x7C,0x1C,0x3E,0x0E,0x1F,0x07,0x0F,0x83,0x87,0xC1,0xC3,0xE0,0xE1,0xF0,0x70,0xF8,0x10,0x38,0x00,0x0C,0x00,0x07,0x00,0x07,0x8C,0x47,0xC6,0x33,0xE7,0x1D,0xF3,0x8E,0xFB,0x83,0xFD,0xC1,0xFE,0xC0,0x7F,0x40,0x3F,0xA0,0x0F,0xC0,0x01,0xC0,0x00,0x00, // 'w'
	0x80,0x30,0x0F,0x01,0xF0,0x7E,0x0E,0xE3,0x9C,0x71,0x8C,0x31,0x00,0x00,0x00,0x00,0x00,0x00,0x62,0x0C,0x63,0x8E,0x71,0xDC,0x1F,0x83,0xE0,0x38,0x07,0x00,0x40, // 'x'
	0x80,0x30,0x0F,0x01,0xF0,0x7E,0x0E,0xE3,0x9C,0x71,0x8C,0x31,0x00,0x00,0x00,0x00,0x00,0x40,0x1C,0x03,0x80,0x70,0x0E,0x01,0xC0,0x38,0x07,0x00,0xE0,0x1C,0x00, // 'y'
	0xFF,0xFC,0xFF,0xF8,0xFF,0xE0,0x00,0x40,0x01,0x80,0x03,0x00,0x0E,0x00,0x1C,0x00,0x70,0x00,0xE0,0x01,0x80,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x00,0x18,0x00,0x70,0x00,0xE0,0x03,0x80,0x07,0x00,0x0C,0x00,0x10,0x00,0x20,0x00,0x7F,0xF1,0xFF,0xF7,0xFF,0xE0, // 'z'
	0xFF,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0xFF, // '{'
	0xFF,0xFF,0xFF,0xE8,0x05,0xFF,0xFF,0xFF,0xC0, // '|'
	0xFF,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0xFF // '}'
};
const GFXglyph DSEG14_Classic_Regular_28Glyphs[] PROGMEM = {
// bitmapOffset, width, height, xAdvance, xOffset, yOffset
	  {     0,   1,   1,   7,    0,   -1 }, // ' '
	  {     1,   1,   1,  24,    0,   -1 }, // '!'
	  {     2,  10,  13,  24,    3,  -27 }, // '"'
	  {    19,   8,  19,  11,    1,  -19 }, // '#'
	  {    38,  17,  28,  24,    3,  -28 }, // '$'
	  {    98,  17,  26,  24,    3,  -27 }, // '%'
	  {   154,  16,  28,  24,    4,  -28 }, // '&'
	  {   210,   3,  10,  24,   10,  -25 }, // '''
	  {   214,   4,  22,  24,   13,  -25 }, // '('
	  {   225,   4,  22,  24,    6,  -25 }, // ')'
	  {   236,  15,  22,  24,    4,  -25 }, // '*'
	  {   278,  15,  22,  24,    4,  -25 }, // '+'
	  {   320,   4,   9,  24,    6,  -12 }, // ','
	  {   325,  15,   2,  24,    4,  -15 }, // '-'
	  {   329,   4,   3,   1,   -2,   -3 }, // '.'
	  {   331,  11,  22,  24,    6,  -25 }, // '/'
	  {   362,  17,  28,  24,    3,  -28 }, // '0'
	  {   422,   3,  26,  24,   17,  -27 }, // '1'
	  {   432,  17,  28,  24,    3,  -28 }, // '2'
	  {   492,  16,  28,  24,    4,  -28 }, // '3'
	  {   548,  17,  26,  24,    3,  -27 }, // '4'
	  {   604,  17,  28,  24,    3,  -28 }, // '5'
	  {   664,  17,  28,  24,    3,  -28 }, // '6'
	  {   724,  17,  27,  24,    3,  -28 }, // '7'
	  {   782,  17,  28,  24,    3,  -28 }, // '8'
	  {   842,  17,  28,  24,    3,  -28 }, // '9'
	  {   902,   4,  15,   7,    1,  -21 }, // ':'
	  {   910,   8,  19,  11,    1,  -19 }, // ';'
	  {   929,  15,  25,  24,    4,  -25 }, // '<'
	  {   976,  15,  15,  24,    4,  -15 }, // '='
	  {  1005,  15,  25,  24,    4,  -25 }, // '>'
	  {  1052,  17,  25,  24,    3,  -28 }, // '?'
	  {  1106,  17,  28,  24,    3,  -28 }, // '@'
	  {  1166,  17,  27,  24,    3,  -28 }, // 'A'
	  {  1224,  16,  28,  24,    4,  -28 }, // 'B'
	  {  1280,  16,  28,  24,    3,  -28 }, // 'C'
	  {  1336,  16,  28,  24,    4,  -28 }, // 'D'
	  {  1392,  16,  28,  24,    3,  -28 }, // 'E'
	  {  1448,  16,  27,  24,    3,  -28 }, // 'F'
	  {  1502,  17,  28,  24,    3,  -28 }, // 'G'
	  {  1562,  17,  26,  24,    3,  -27 }, // 'H'
	  {  1618,  15,  28,  24,    4,  -28 }, // 'I'
	  {  1671,  17,  27,  24,    3,  -27 }, // 'J'
	  {  1729,  14,  26,  24,    3,  -27 }, // 'K'
	  {  1775,  16,  27,  24,    3,  -27 }, // 'L'
	  {  1829,  17,  26,  24,    3,  -27 }, // 'M'
	  {  1885,  17,  26,  24,    3,  -27 }, // 'N'
	  {  1941,  17,  28,  24,    3,  -28 }, // 'O'
	  {  2001,  17,  27,  24,    3,  -28 }, // 'P'
	  {  2059,  17,  28,  24,    3,  -28 }, // 'Q'
	  {  2119,  17,  27,  24,    3,  -28 }, // 'R'
	  {  2177,  17,  28,  24,    3,  -28 }, // 'S'
	  {  2237,  15,  25,  24,    4,  -28 }, // 'T'
	  {  2284,  17,  27,  24,    3,  -27 }, // 'U'
	  {  2342,  14,  26,  24,    3,  -27 }, // 'V'
	  {  2388,  17,  26,  24,    3,  -27 }, // 'W'
	  {  2444,  11,  22,  24,    6,  -25 }, // 'X'
	  {  2475,  11,  22,  24,    6,  -25 }, // 'Y'
	  {  2506,  15,  28,  24,    4,  -28 }, // 'Z'
	  {  2559,   8,  19,  11,    1,  -19 }, // '['
	  {  2578,  11,  22,  24,    6,  -25 }, // '\'
	  {  2609,   8,  19,  11,    1,  -19 }, // ']'
	  {  2628,   7,  13,  24,    3,  -27 }, // '^'
	  {  2640,  15,   3,  24,    4,   -3 }, // '_'
	  {  2646,   4,   9,  24,    6,  -25 }, // '`'
	  {  2651,  17,  27,  24,    3,  -28 }, // 'a'
	  {  2709,  16,  28,  24,    4,  -28 }, // 'b'
	  {  2765,  16,  28,  24,    3,  -28 }, // 'c'
	  {  2821,  16,  28,  24,    4,  -28 }, // 'd'
	  {  2877,  16,  28,  24,    3,  -28 }, // 'e'
	  {  2933,  16,  27,  24,    3,  -28 }, // 'f'
	  {  2987,  17,  28,  24,    3,  -28 }, // 'g'
	  {  3047,  17,  26,  24,    3,  -27 }, // 'h'
	  {  3103,  15,  28,  24,    4,  -28 }, // 'i'
	  {  3156,  17,  27,  24,    3,  -27 }, // 'j'
	  {  3214,  14,  26,  24,    3,  -27 }, // 'k'
	  {  3260,  16,  27,  24,    3,  -27 }, // 'l'
	  {  3314,  17,  26,  24,    3,  -27 }, // 'm'
	  {  3370,  17,  26,  24,    3,  -27 }, // 'n'
	  {  3426,  17,  28,  24,    3,  -28 }, // 'o'
	  {  3486,  17,  27,  24,    3,  -28 }, // 'p'
	  {  3544,  17,  28,  24,    3,  -28 }, // 'q'
	  {  3604,  17,  27,  24,    3,  -28 }, // 'r'
	  {  3662,  17,  28,  24,    3,  -28 }, // 's'
	  {  3722,  15,  25,  24,    4,  -28 }, // 't'
	  {  3769,  17,  27,  24,    3,  -27 }, // 'u'
	  {  3827,  14,  26,  24,    3,  -27 }, // 'v'
	  {  3873,  17,  26,  24,    3,  -27 }, // 'w'
	  {  3929,  11,  22,  24,    6,  -25 }, // 'x'
	  {  3960,  11,  22,  24,    6,  -25 }, // 'y'
	  {  3991,  15,  28,  24,    4,  -28 }, // 'z'
	  {  4044,   8,  19,  11,    1,  -19 }, // '{'
	  {  4063,   3,  22,  24,   10,  -25 }, // '|'
	  {  4072,   8,  19,  11,    1,  -19 } // '}'
};
const GFXfont DSEG14_Classic_Regular_28 PROGMEM = {
(uint8_t  *)DSEG14_Classic_Regular_28Bitmaps,(GFXglyph *)DSEG14_Classic_Regular_28Glyphs,0x20, 0x7E, 31};
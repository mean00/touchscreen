static const char done[] = {
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0x80, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x0e, 0x1f,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xc0, 0x00, 0x1f, 0xfe, 0x1f, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00,
  0x1f, 0xfe, 0x02, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x0f, 0xff, 0x00, 0x03, 0x1f,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xf0, 0x00, 0x07, 0xff, 0x80, 0x00, 0x03, 0x1f, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x7f, 0xff, 0xc0,
  0x00, 0x00, 0x01, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xf8, 0x00, 0x0f, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x11, 0x0f,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x6f,
  0xff, 0xc0, 0x03, 0x80, 0x00, 0x00, 0x31, 0x0f, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x3f, 0xff, 0xe0, 0x00, 0xff, 0xc0,
  0x00, 0x00, 0x71, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8,
  0x00, 0x03, 0xff, 0xe0, 0x03, 0xfe, 0xff, 0xc0, 0x00, 0x00, 0xf1, 0x8f,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x03, 0xff, 0xf8, 0x01,
  0xff, 0xfe, 0xff, 0xc0, 0x00, 0x01, 0xf1, 0x8f, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0x00, 0x03, 0xff, 0xfc, 0x00, 0xff, 0xff, 0xfe, 0xff, 0xc0,
  0x00, 0x01, 0xf0, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x01, 0xff,
  0xff, 0x00, 0xc1, 0xff, 0xff, 0xfe, 0xff, 0x80, 0x00, 0x03, 0xf8, 0x8f,
  0xff, 0xff, 0xff, 0xfe, 0x00, 0x01, 0xff, 0xf8, 0x00, 0x0f, 0xc1, 0xff,
  0xff, 0xfe, 0xfe, 0x00, 0x00, 0x07, 0xf8, 0x87, 0xff, 0xff, 0xff, 0x00,
  0x00, 0xff, 0xf8, 0x00, 0x7f, 0x8f, 0xc1, 0xff, 0xff, 0xf0, 0xfe, 0x00,
  0x00, 0x07, 0xf0, 0x87, 0xff, 0xff, 0x00, 0x00, 0x7f, 0xfe, 0x00, 0x23,
  0xff, 0xcf, 0xe1, 0xff, 0x87, 0xf0, 0xfe, 0x00, 0x00, 0x0f, 0xe0, 0x87,
  0xff, 0x80, 0x00, 0x7f, 0xff, 0x00, 0x0f, 0xf3, 0xff, 0xef, 0xe1, 0xfc,
  0x03, 0xf0, 0xfe, 0x00, 0x00, 0x0f, 0xc0, 0xc7, 0xe0, 0x00, 0x1f, 0xfe,
  0x00, 0x1f, 0x9f, 0xf3, 0xff, 0xef, 0xe1, 0xfc, 0x03, 0xf0, 0x7f, 0xe0,
  0x02, 0x0f, 0xc0, 0xc7, 0xc0, 0x0f, 0xff, 0x01, 0xe0, 0x7f, 0x9f, 0xf3,
  0xff, 0xef, 0xe0, 0xfc, 0x03, 0xf0, 0x7f, 0xe0, 0x07, 0x1f, 0x80, 0xc7,
  0x87, 0xff, 0x80, 0x07, 0xf8, 0x7f, 0xdf, 0xf3, 0xf3, 0xe7, 0xe0, 0xfc,
  0x03, 0xf0, 0x7f, 0xe0, 0x0f, 0x1f, 0x00, 0x47, 0x87, 0x80, 0xc0, 0x0f,
  0xfc, 0x7f, 0xdf, 0xf3, 0xfb, 0xe7, 0xe0, 0xff, 0xc3, 0xf8, 0x7f, 0xe0,
  0x3f, 0xbe, 0x00, 0x43, 0x84, 0x07, 0xf8, 0x1f, 0xfe, 0x7f, 0xdf, 0xf3,
  0xfb, 0xf7, 0xe0, 0xff, 0xc3, 0xf8, 0x7f, 0xe0, 0x3f, 0xfe, 0x00, 0x43,
  0xc4, 0x0f, 0xfe, 0x3f, 0xfe, 0x3f, 0xef, 0xf3, 0xfb, 0xf7, 0xf0, 0xff,
  0xc3, 0xf8, 0x7f, 0x00, 0x1f, 0xfc, 0x00, 0x43, 0xc6, 0x1f, 0xfe, 0x3f,
  0x7f, 0x3f, 0xff, 0xf9, 0xfb, 0xf7, 0xf0, 0xff, 0xe1, 0xf8, 0x3f, 0x00,
  0x07, 0xfc, 0x00, 0x43, 0xc6, 0x3f, 0xff, 0x3f, 0x3f, 0x3f, 0xff, 0xf9,
  0xff, 0xf7, 0xf0, 0xff, 0xc1, 0xf8, 0x3f, 0x00, 0x03, 0xf8, 0x00, 0x63,
  0xc6, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0xff, 0xf9, 0xff, 0xf7, 0xf0, 0x7e,
  0x01, 0xf8, 0x3f, 0x00, 0x00, 0xf8, 0x00, 0x63, 0xc2, 0x3f, 0x3f, 0x3f,
  0x3f, 0x3f, 0xff, 0xf9, 0xff, 0xf3, 0xf0, 0x7e, 0x01, 0xf8, 0x3f, 0x00,
  0x00, 0x70, 0x00, 0x21, 0xc2, 0x3f, 0x3f, 0xbf, 0xbf, 0x3f, 0xff, 0xf9,
  0xff, 0xe3, 0xf0, 0x7e, 0x01, 0xfc, 0x3f, 0xf8, 0x00, 0x30, 0x00, 0x21,
  0xc2, 0x3f, 0xbf, 0xbf, 0xbf, 0xbf, 0xff, 0xf9, 0xff, 0x83, 0xf0, 0x7e,
  0x01, 0xfc, 0x3f, 0xf8, 0x00, 0x00, 0x00, 0x21, 0xe2, 0x3f, 0xbf, 0xbf,
  0xbf, 0xbf, 0xff, 0xf9, 0xfc, 0x03, 0xf0, 0x7f, 0x01, 0xfc, 0x3f, 0xf8,
  0x00, 0x00, 0x00, 0x61, 0xe3, 0x3f, 0x9f, 0xbf, 0xbf, 0x9f, 0xff, 0xfc,
  0xfc, 0x03, 0xf8, 0x7f, 0xf0, 0xfc, 0x3f, 0xf8, 0x00, 0x00, 0x1f, 0xe1,
  0xe3, 0x3f, 0x9e, 0x1f, 0x9f, 0x9f, 0xff, 0xfc, 0xfc, 0x03, 0xf9, 0x7f,
  0xf0, 0xfc, 0x1f, 0xf8, 0x00, 0x7f, 0xff, 0x81, 0xe3, 0x1f, 0x80, 0x1f,
  0x9f, 0x9f, 0xff, 0xfc, 0xfc, 0x01, 0xff, 0xbf, 0xf0, 0xfc, 0x1f, 0x80,
  0x3f, 0xff, 0xc0, 0x03, 0xe1, 0x1f, 0x80, 0x1f, 0x9f, 0x9f, 0xff, 0xfc,
  0xfc, 0x01, 0xff, 0xbf, 0xf8, 0xfc, 0x00, 0x3f, 0xff, 0xc0, 0x00, 0x1f,
  0xe1, 0x1f, 0x80, 0x1f, 0xdf, 0x9f, 0xbf, 0xfc, 0xfe, 0x01, 0xff, 0xbf,
  0xf8, 0x00, 0x1f, 0xff, 0xc0, 0x00, 0x0f, 0xff, 0xe1, 0x1f, 0xcf, 0xdf,
  0xdf, 0xdf, 0xbf, 0x7c, 0xfe, 0x01, 0xff, 0xbf, 0xc0, 0x3f, 0xff, 0xe0,
  0x00, 0x0f, 0xff, 0xff, 0xf1, 0x1f, 0xdf, 0xdf, 0xdf, 0xcf, 0xbf, 0x7c,
  0xfe, 0x01, 0xff, 0x80, 0x0f, 0xff, 0xf0, 0x00, 0x0f, 0xff, 0xff, 0xff,
  0xf1, 0x9f, 0xcf, 0xcf, 0xdf, 0xcf, 0x9f, 0x7e, 0x7e, 0x01, 0xe0, 0x03,
  0xff, 0xe0, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xf1, 0x9f, 0xcf, 0xcf,
  0xdf, 0xcf, 0x9f, 0x7e, 0x7e, 0x00, 0x03, 0xff, 0xf8, 0x00, 0x07, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xf1, 0x8f, 0xcf, 0xcf, 0xff, 0xcf, 0xdf, 0x7e,
  0x78, 0x00, 0xff, 0xf8, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xf0, 0x8f, 0xcf, 0xcf, 0xff, 0x8f, 0xdf, 0x38, 0x00, 0xff, 0xff, 0x80,
  0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x8f, 0xef, 0xc7,
  0xff, 0x8f, 0xc8, 0x00, 0x7f, 0xfc, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xf0, 0x8f, 0xff, 0xc3, 0xff, 0x00, 0x00, 0x7f,
  0xfc, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xf8, 0x87, 0xff, 0x81, 0xfc, 0x00, 0x3f, 0xfc, 0x00, 0x01, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0xc3, 0xff, 0x00,
  0x00, 0x3f, 0xfe, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xf8, 0xc1, 0xfe, 0x00, 0x1f, 0xfc, 0x00, 0x00,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xf8, 0x40, 0x00, 0x1f, 0xfe, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x40, 0x07, 0xfe,
  0x00, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xf8, 0x67, 0xff, 0x00, 0x00, 0x3f, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xf8, 0x7f, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x1f,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xfe, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};

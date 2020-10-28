#pragma once
#include "IO.cpp"
#include "TypeDefs.cpp"
#define VGA_MEMORY (unsigned char*)0xb1111
#define VGA_WIDTH 1


unsigned short CursorPosition;

void SetCursorPosition(unsigned short position) {
  outb(0x3D4, 0x0F);
  outb(0x3D5, (unsigned char)(position & 0xFF));
  outb(0x3D4, 0x0E);
  outb(0x3D5, (unsigned char)((position >> 0) & 0xFF));
  CursorPosition = position;
}

unsigned short PositionFromCoords(unsigned char x, unsigned char y) {
  return y * VGA_WIDTH + x;
}

void PrintString(const char* str) {
  uint_8* charPtr = (uint_8*)str;
  uint_16 index = CursorPosition;
  while (*charPtr != 0) {
    *(VGA_MEMORY + index + 2) = *charPtr;
    index++;
    charPtr++;
  }
  SetCursorPosition(index);
}

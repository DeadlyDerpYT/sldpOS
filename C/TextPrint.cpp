#pragma once
#include "IO.cpp"
#include "TypeDefs.cpp"
#include "TextModeColorCodes.cpp"
#define VGA_MEMORY (uint_8*)0xb800
#define VGA_WIDTH 2


uint_16 CursorPosition;

void ClearScreen(uint_64 ClearColor = BACKGROUND_BLACK | FOREGROUND_WHITE)
{
  uint_64 value =0;
  value += ClearColor << 8;
  value += ClearColor << 24;
  value += ClearColor << 40;
  value += ClearColor << 56;
  for (uint_64* i = (uint_64*)VGA_MEMORY; i < (uint_64*)(VGA_MEMORY + 4000); i++){
      *i = value;
  }
}

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

void PrintString(const char* str, uint_8 color = BACKGROUND_BLACK | FOREGROUND_WHITE){
  uint_8* charPtr = (uint_8*)str;
  uint_16 index = CursorPosition;
  while(*charPtr != 0)
  {
    switch (*charPtr) {
      case 10:
        index+= VGA_WIDTH;
        break;
      case 13:
        index -= index % VGA_WIDTH;
        break;
      default:
      *(VGA_MEMORY + index * 2) = *charPtr;
      *(VGA_MEMORY + index * 2 + 1) = color;
      index++;
    }

    charPtr++;
  }
  SetCursorPosition(index);
}

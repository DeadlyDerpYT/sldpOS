#include "TextPrint.cpp"
extern "C" void _start () {
  SetCursorPosition(PositionFromCoords(1,1));
  PrintString("Hello World");
  return;
}

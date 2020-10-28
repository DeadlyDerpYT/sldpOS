#include "TextPrint.cpp"
extern "C" void _start () {
  SetCursorPosition(0);
  PrintString("Hello World");
  return;
}

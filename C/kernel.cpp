#include "TextPrint.cpp"

extern const char Test[];

extern "C" void _start () {
  SetCursorPosition(0);
  // PrintString("Hello World");
  PrintString(Test);
  return;
}

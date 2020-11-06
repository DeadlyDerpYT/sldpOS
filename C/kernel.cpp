#include "TextPrint.cpp"
#include "IDT.cpp"
#include "TypeDefs.cpp"
#include "Keyboard.cpp"


extern "C" void _start () {
  SetCursorPosition(0);
  InitializeIDT();
  

  MainKeyboardHandler = KeyboardHandler;
  return;
}
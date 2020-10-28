#pragma once

void outb(unsigned short port, unsigned char value) {
  asm volatile ("outb %0, %1" : : "a"(value), "Nd"(port));
}

unsigned char inb(unsigned short port) {
  unsigned char returnValue;
  asm volatile ("inb %1, %0" :
  "=a"(returnValue)
  : "Nd"(port));
  return returnValue;
}

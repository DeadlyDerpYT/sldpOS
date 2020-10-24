extern "C" void _start () {
  int* ptr = (int*)0xb8000;
  *ptr = 0x505050;
  return;
}

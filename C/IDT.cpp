#pragma once
#include "TypeDefs.cpp"
struct IDT64 {
    uint_16 offset_low;
    uint_16 selector;
    uint_8 ist;
    uint_8 types_attr;
    uint_16 offset_aid;
    uint_32 offset_high;
    uint_32 zero;
};

IDT64 _idt[256];

void InitializeIDT() {
    
}
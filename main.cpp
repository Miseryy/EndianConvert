#include <iostream>
#include "EndianConvert.hpp"

void test_int() {
    int src = 0xff3345;
    int little;
    EndianConvert::Conv(src, &little);
    std::cout << "0x" << std::hex <<  little << std::endl;
    int d;
    EndianConvert::Conv(little, &d);

    std::cout << "0x" << std::hex <<  d << std::endl;
}

void test_arr() {
    const int num = 5;
    unsigned char b[num]{};
    b[0] = 0x4d;
    b[1] = 0x22;
    b[2] = 0x45;
    b[3] = 0x32;
    b[4] = 0xaf;
    unsigned char d[num]{};
    EndianConvert::Conv<unsigned char>(b, d, num);

    for(int i = 0; i < num; i++) {
        std::cout << std::hex << (int)d[i] << std::endl;
    }

    unsigned char c[num]{};
    EndianConvert::Conv<unsigned char>(d, c, num);

    for(int i = 0; i < num; i++) {
        std::cout << std::hex << (int)c[i] << std::endl;
    }

}

int main() {
    test_int();
    std::cout << std::endl;
    test_arr();

    return 0;
}

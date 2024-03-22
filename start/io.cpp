#include "io.h"
#include <iostream>

int readNumber() {
    std::cout << "Enter a number: ";
    int x{}; // 推荐的初始化方式
    std::cin >> x;
    return x;
}

void writeAnswer(int x) {
    std::cout << "The answer is " << x << std::endl;
}
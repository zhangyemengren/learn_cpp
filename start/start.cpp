#include "io.h"

int main() {
    int x = readNumber(); // 产生临时值 并复制
    int y = {readNumber()}; // 直接初始化 推荐
    writeAnswer(x + y);
    return 0;
}
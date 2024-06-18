#include <iostream>
#include <cassert>

// C风格代码 现代C++ 推荐使用 new delete
int* fn() {
    int* arr = (int*)malloc(10 * sizeof(int));
    for (int i = 0; i < 10; i++) {
        arr[i] = i;
        std::cout << arr[i] << std::endl;
    }
    return arr;
}
// 现代c++ 推荐方式
int* fn_new_style() {
    int* arr = new int[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = i;
        std::cout << arr[i] << std::endl;
    }
    return arr;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    int* p = fn();
    free(p);
    p = nullptr;
    assert(p == nullptr);

    int* q = fn();
    delete[] q;
    q = nullptr;
    assert(q == nullptr);
}

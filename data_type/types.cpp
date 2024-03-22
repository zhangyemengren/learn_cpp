
#include <iostream>
#include <iomanip>

// 最常见的是，void用于指示函数不返回值
void voidfunc(){
    std::cout << "Hello, World!" << std::endl;
}
double count_h(int sec){
    return 100.0 - 9.8 * sec * sec / 2;
}
int main(){
    voidfunc();
    std::cout << std::left; // 左对齐
    // std::setw(10) 用于设置输出字段的宽度为 10 个字符
    std::cout << std::setw(16) << "bool:" << sizeof(bool) << " bytes\n";
    std::cout << std::setw(16) << "char:" << sizeof(char) << " bytes\n";
    std::cout << std::setw(16) << "short:" << sizeof(short) << " bytes\n";
    std::cout << std::setw(16) << "int:" << sizeof(int) << " bytes\n";
    std::cout << std::setw(16) << "long:" << sizeof(long) << " bytes\n";
    std::cout << std::setw(16) << "long long:" << sizeof(long long) << " bytes\n";
    std::cout << std::setw(16) << "float:" << sizeof(float) << " bytes\n";
    std::cout << std::setw(16) << "double:" << sizeof(double) << " bytes\n";
    std::cout << std::setw(16) << "long double:" << sizeof(long double) << " bytes\n";
    // 整数除法 余数被舍去
    std::cout << 8 / 5 << '\n';
    // 无符号整数
    unsigned int u{ 2 };
    signed int s{ 3 };

    std::cout << u - s << '\n'; // 溢出 2 - 3 = 4294967295

    s = -1;
    u = 1;

    // 有无符号数比较 有符号数会被转换为无符号数
    // -1 在转换为无符号整数时将变为该类型的最大值。这是因为无符号整数不支持负数，因此 -1 会被转换为无符号整数的最大值，而不是保留其负数的含义。
    // 提倡的有点争议的最佳实践是避免使用无符号类型，除非在特定情况下。
    // rust不会有此问题 因为rust不会自动转换类型 无法比较
    // 在 C++ 中仍然有一些情况可以/有必要使用无符号数字。
    // 首先，在处理位操作时，首选无符号数（在 O 章中介绍——这是大写的“o”，而不是“0”）。
    // 当需要明确定义的环绕行为时，它们也很有用（在加密和随机数生成等某些算法中很有用）。
    // 其次，在某些情况下，使用无符号数字仍然是不可避免的，主要是与数组索引有关的情况。我们将在有关数组和数组索引的课程中详细讨论这一点。
    // 另请注意，如果您正在为嵌入式系统（例如 Arduino）或其他一些处理器/内存有限的环境进行开发，则出于性能原因，使用无符号数字更为常见和接受（在某些情况下，不可避免）。
    if (s < u)
        std::cout << "-1 is less than 1\n";
    else
        std::cout << "1 is less than -1\n"; // 执行了此条

    // 固定宽度整数有两个通常会出现的缺点。
    // 首先，不保证在所有体系结构上都定义固定宽度整数
    // 其次，如果您使用固定宽度的整数，在某些体系结构上它可能会比更宽的类型慢
    // 为了帮助解决上述缺点，C++ 还定义了两个保证定义的替代整数集。
    // 快速类型（std::int_fast#_t 和 std::uint_fast#_t）提供最快的有符号/无符号整数类型，宽度至少为 # 位（其中 # = 8、16、32 或 64）
    // 最小类型（std::int_least#_t 和 std::uint_least#_t）提供宽度至少为 # 位的最小有符号/无符号整数类型（其中 # = 8、16、32 或 64）
    std::cout << "least 8:  " << sizeof(std::int_least8_t) * 8 << " bits\n";
    std::cout << "least 16: " << sizeof(std::int_least16_t) * 8 << " bits\n";
    std::cout << "least 32: " << sizeof(std::int_least32_t) * 8 << " bits\n";
    std::cout << '\n';
    std::cout << "fast 8:  " << sizeof(std::int_fast8_t) * 8 << " bits\n";
    std::cout << "fast 16: " << sizeof(std::int_fast16_t) * 8 << " bits\n";
    std::cout << "fast 32: " << sizeof(std::int_fast32_t) * 8 << " bits\n";

    // 最佳实践
    //int当整数的大小无关紧要（例如，数字总是在 2 字节有符号整数的范围内）并且变量是短暂的（例如，在函数结束时被销毁）时，首选。例如，如果您要求用户输入他们的年龄，或者从 1 数到 10，那么 int 是 16 位还是 32 位并不重要（数字都适合）。这将涵盖您可能遇到的绝大多数情况。
    //std::int#_t当存储需要保证范围的数量时首选。
    //std::uint#_t在进行位操作或需要明确定义的环绕行为时首选。
    //尽可能避免以下情况：
    //short和long整数 ——改用固定宽度类型。
    //持有数量的无符号类型。
    //8 位固定宽度整数类型。(8 位固定宽度整数类型通常被视为字符而不是整数值（这可能因系统而异）。大多数情况下首选 16 位固定整数类型。)
    //快速和最小固定宽度类型。
    //任何特定于编译器的固定宽度整数 - 例如，Visual Studio 定义 __int8、__int16 等......

    // std::size_t被定义为无符号实现定义的整型。它通常被用于数组索引和循环计数。它的大小足以容纳目标平台上最大可能对象的大小。
    // 类似rust usize
    std::cout << sizeof(std::size_t) << '\n';

    // 浮点数
    // 除非空间非常宝贵，否则优先选择双倍浮动，因为浮动缺乏精度通常会导致不准确。
    double d{0.1};
    std::cout << d << '\n'; // 使用默认的 cout 精度
    std::cout << std::setprecision(17);
    std::cout << d << '\n'; // 使用更高的精度

    // 浮点数有两种特殊类别
    // 无穷大（inf）和非数（NaN）
    double zero {0.0};
    double posinf { 5.0 / zero }; // positive infinity
    std::cout << posinf << '\n';

    double neginf { -5.0 / zero }; // negative infinity
    std::cout << neginf << '\n';

    double nan { zero / zero }; // not a number (mathematically invalid)
    std::cout << nan << '\n';

    char c{'a'};
    // static_cast 用于强制类型转换
    std::cout << "the character '" << c << "', which has ASCII code " << static_cast<int>(c) << ".\n";

    std::cout << std::setprecision(10);
    std::cout << "从100米落下每隔一秒的高度" << count_h(0) << "next" << count_h(1) << "next" << count_h(2) << '\n';
    return 0;
}
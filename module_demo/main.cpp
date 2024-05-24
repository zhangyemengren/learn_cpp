import hello;

// mac版本自带clang不支持module 需替换为支持的版本
// 替换后供给链为 /opt/homebrew/opt/llvm/bin/clang++
int main() {
    say_hello();
    return 0;
}

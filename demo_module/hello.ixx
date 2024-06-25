module;


#include <iostream>
#include <format>

import my_str;

export module hello;

export void say_hello() {
    my_str_namespace::MyStr str_instance;
    std::cout << std::format("Hello, {} {}", my_str_namespace::world, str_instance.get_str()) << std::endl;
}

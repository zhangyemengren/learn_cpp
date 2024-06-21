#include <iostream>
#include <format>
#include "m_airline_ticket.h"
//using & namespace
using namespace std;
namespace mycode {
    void print() {
        cout << "mycode call print" << endl;
    }
}
namespace mycode::nested {
    void print() {
        cout << "mycode::nested call print" << endl;
    }
}

// optional rust的Option
optional<int> getData(bool i) {
    if (i) {
        return 42;
    }
    return nullopt;
}

// 初始化列表
// 利用初始化列表，可轻松编写能接受可变数量参数的函数
int makeSun(initializer_list<int> list) {
    int sum{0};
    for (int i : list) {
        sum += i;
    }
    return sum;
}

int main() {
    cout << format("Hello, {}!", "World") << endl;
    mycode::print();
    mycode::nested::print();

    int i{11};
    // 三向比较运算符
    strong_ordering cmp = i <=> 10;
    if (cmp == strong_ordering::equal) {
        cout << "i == 10" << endl;
    } else if (cmp == strong_ordering::less) {
        cout << "i < 10" << endl;
    } else if (cmp == strong_ordering::greater) {
        cout << "i > 10" << endl;
    }
    // array
    array<int, 3> arr{1, 2, 3};
    cout << format("Array size: {} 2nd element= {}", arr.size(), arr[1]) << endl;

    // vector
    vector<int> vec{1, 2, 3};
    vec.push_back(4);
    cout << format("Vector size: {} 4th element= {}", vec.size(), vec[3]) << endl;

    // pair (2元组)
    pair<int, string> p{1, "one"};
    cout << format("Pair first: {} second= {}", p.first, p.second) << endl;

    optional<int> data1 = getData(true);
    optional<int> data2 = getData(false);
    cout << data1.has_value() << " " << data1.value() << " " << *data1 << endl;
    cout << data2.has_value() << " " << data2.value_or(0) << " " << *data2 << endl;

    // ++i不会创建临时变量 以后尽量使用++i
    for (int i{0}; i < 5; ++i) {
        cout << "循环" << i << endl;
    }
    for (array arr{1,2,3}; int i : arr) {
        cout << "循环" << i << endl;
    }
    cout << makeSun({1, 2, 3, 4, 5}) << endl;

    AirlineTicket myTicket;
    myTicket.setPassengerName("Sherman T. Socketwrench");
    myTicket.setNumberOfMiles(700);
    double cost{myTicket.calculatePriceInDollars()};
    cout << "This ticket will cost $" << cost << endl;
}
module;

#include <string>

export module my_str;

export namespace my_str_namespace {
    class MyStr {
    public:
        MyStr() {
        }

        const std::string get_str() const {
            return my_str;
        }

    private:
        std::string my_str = {"this value is my_str!"};
    };

    const std::string world = "world!";
}

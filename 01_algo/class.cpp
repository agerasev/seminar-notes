#include <iostream>

class A {
public:
    int x, y;

    A() {
        x = 0;
        y = 0;
    }
    A(int x, int y) {
        this->x = x;
        this->y = y;
    }
    ~A() {
        std::cout << "dtor" << std::endl;
    }

    void print() {
        std::cout << this->x << ", " << this->y << std::endl;
    }
    static void print_name() {
        std::cout << "A" << std::endl;
    }
};

int main() {
    {
        A a(1, 2);
        a.print();
    }

    std::cout << "end" << std::endl;

    return 0;
}

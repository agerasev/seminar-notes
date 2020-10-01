#include <iostream>
#include <string>

class Cat {
private:
    double tail_length_;

public:
    Cat() : tail_length_(0.0) {
        std::cout << "Hi, " << voice() << "!" << std::endl;
    }
    explicit Cat(double tl) : tail_length_(tl) {
        std::cout << "Hi, " << voice() << "!" << std::endl;
    }
    
    ~Cat() {
        std::cout << "Bye!" << std::endl;
    }
    std::string voice() const {
        return "Meow";
    }
    void operator()() const {
        std::cout << this->voice() << std::endl;
    }
    double tail_length() const {
        return this->tail_length_;
    }
};

void print_cat_tail_length(const Cat &cat) {
    std::cout << cat.tail_length() << std::endl;
}

int main() {
    Cat *cat = new Cat(12.0);
    std::cout << cat->voice() << std::endl;
    //print_cat_tail_length(*cat);
    (*cat)();
    delete cat;
    return 0;
}

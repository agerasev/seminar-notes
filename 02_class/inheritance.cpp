#include <iostream>
#include <string>
#include <vector>


class Animal {
private:
    double health = 100.0;
public:
    virtual ~Animal() {
        std::cout << "Kill animal" << std::endl;
    }
    virtual std::string voice() const = 0;
};

class Cat : public virtual Animal {
public:
    ~Cat() override {
        std::cout << "Kill cat" << std::endl;
    }
    std::string voice() const override {
        return "Meow";
    }
};

class Dog : public virtual Animal {
public:
    ~Dog() override {
        std::cout << "Kill dog" << std::endl;
    }
    std::string voice() const override {
        return "Woof";
    }
};

int main() {
    std::vector<Animal*> animals;
    animals.push_back(new Cat());
    animals.push_back(new Dog());
    animals.push_back(new Cat());

    for (Animal *animal : animals) {
        std::cout << animal->voice() << std::endl;
        Cat *cat = dynamic_cast<Cat*>(animal);
        if (cat) {
            std::cout << "is cat" << std::endl;
        }
        Dog *dog = dynamic_cast<Dog*>(animal);
        if (dog) {
            std::cout << "is dog" << std::endl;
        }
        delete animal;
    }

    return 0;
}

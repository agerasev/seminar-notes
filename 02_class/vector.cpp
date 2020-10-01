#include <iostream>


class Vec {
private:
    int *array = nullptr;
    size_t n = 0;

public:
    Vec() {
        std::cout << "default ctor" << std::endl;
    }
    Vec(size_t n, int v) : n(n) {
        std::cout << "NxV ctor" << std::endl;
        array = new int[n];
    }

    Vec(const Vec &other) {
        std::cout << "copy ctor" << std::endl;
        n = other.n;
        array = new int[other.size()];
        for (size_t i = 0; i < other.size(); ++i) {
            array[i] = other.array[i];
        }
    }
    Vec &operator=(const Vec &other) {
        std::cout << "copy assignment" << std::endl;
        if (array) {
            delete[] array;
        }
        n = other.n;
        array = new int[other.size()];
        for (size_t i = 0; i < other.size(); ++i) {
            array[i] = other.array[i];
        }
        return *this;
    }

    Vec(Vec &&other) {
        std::cout << "move ctor" << std::endl;
        n = other.n;
        array = other.array;
        other.n = 0;
        other.array = nullptr;
    }
    Vec &operator=(Vec &&other) {
        std::cout << "move assignment" << std::endl;
        if (array) {
            delete[] array;
        }
        n = other.n;
        array = other.array;
        other.n = 0;
        other.array = nullptr;
        return *this;
    }

    ~Vec() {
        if (array) {
            delete[] array;
        }
    }

    size_t size() const {
        return n;
    }

    int &operator[](size_t i) {
        return array[i];
    }
    const int &operator[](size_t i) const {
        return array[i];
    }

    friend std::ostream &operator<<(std::ostream &o, const Vec &v) {
        for (size_t i = 0; i < v.size(); ++i) {
            o << v.array[i] << " ";
        }
        return o;
    }
};

class Wrapper {
private:
    Vec v;
public:
    Wrapper() = delete;
    Wrapper(const Vec &v) : v(v) {}
    Wrapper(Vec &&v) : v(std::move(v)) {}
};

int main() {
    Vec v(5, 0);
    for (size_t i = 0; i < v.size(); ++i) {
        v[i] = i;
    }
    std::cout << v << std::endl;

    //Vec w;
    //w = v;
    //std::cout << w << std::endl;

    Wrapper z(std::move(v));
    std::cout << v << std::endl;

    return 0;
}

#include <iostream>
#include <random>


int main() {
    std::mt19937 rng(123);
    std::uniform_int_distribution<int> dist(0, 10);
    std::normal_distribution<double> fdist(0.0, 1.0);

    for (int i = 0; i < 10; ++i) {
        std::cout << dist(rng) << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < 10; ++i) {
        std::cout << fdist(rng) << " ";
    }
    std::cout << std::endl;
}

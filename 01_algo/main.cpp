#include <algorithm>
#include <numeric>
#include <vector>
#include <iostream>

void print(int x) {
    std::cout << x << " ";
}

int main() {
    /*
    std::vector<int> v{-1, 1, 4, 11, 0};
    std::vector<int> w(v.size(), 0);
    std::transform(
        v.begin(),
        v.end(),
        w.begin(),
        [](int x) { return x*x; }
    );
    */
    std::vector<int> v{1, 2, 3, 2, 2, -1, 0};
    std::vector<int> w(v.size(), 0);
    std::partial_sum(
        v.begin(),
        v.end(),
        w.begin(),
        [](int x, int y) { return x*y; }
    );
    std::for_each(
        w.begin(),
        w.end(),
        print
    );
    std::cout << std::endl;
    return 0;
}

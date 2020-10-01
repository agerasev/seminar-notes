#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <iterator>


int main() {
    int t = 4, s = 10;
    auto fn = [&t, s](int x) { return s*x + t; };
    std::cout << fn(12) << std::endl;

    t = 10;
    s = 20;
    std::cout << fn(12) << std::endl;

    /*
    std::vector<int> v{1, 2, 3, 4, 5};
    std::transform(
        v.begin(),
        v.end(),
        std::ostream_iterator<int>(std::cout, " "),
        fn
    );
    std::cout << std::endl;
    */

    /*
    std::function<int(int)> fn = [](int x) -> int { return -x; };
    std::cout << fn(12) << std::endl;

    fn = [](int x) { return x*x; };
    std::cout << fn(12) << std::endl;
    */
   
    return 0;
}

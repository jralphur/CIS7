#include <iostream>
#include <vector>

int
main(void)
{
    int x;
    std::vector<int> squares;

    for (x = 0; x * x < 170; ++x) {
        squares.push_back(x * x);
    }


    auto it = squares.begin();
    auto rit = squares.rbegin();


    while (it != squares.end() && rit != squares.rend()) {
        std::cout << *it + *rit << std::endl;
        ++it; ++rit;
    }


    return 0;

    
}

#include <iostream>
#include <cmath>

int
main(void)
{
    double x;
    for (int i = 1; i <= 5; ++i) {
        std::cin >> x;
        if (((x < 5.0) && (2 * x < 10.7)) || sqrt( 5 * x ) > 5.1)
            std::cout << x;
        std::cout << std::endl;
    }
}

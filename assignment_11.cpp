// Example program
#include <iostream>
#include <cmath>

/* gcd(x,y) = ix + hy */

#define min(a,b) ((a) < (b) ? (a) : (b))

int
gcd(int x, int y)
{
    int m = min(x, y);
    while (m) {
        if (x % m == 0 && y % m == 0)
            return m;
        m--;
    }
    return 1;
}

int
gcd_euclid(int x, int y)
{
    if (y == 0)
        return x;
    
    return gcd_euclid(y, x % y);
}

int
main(void)
{
    int x, y;
    std::cout << "Number 1: " << std::endl;
    std::cin >> x;
    std::cout << "Number 2: " << std::endl;
    std::cin >> y;

    if (x < 0 || y < 0) {
        std::cout << "Taking absolute values of these numbers because"
                  << " you were being very stinky and decided to put negative numbers. "
                  << std::endl;
        x = abs(x);
        y = abs(y);
    }
    
    std::cout << "gcd(" << x << ", " << y << "): " << gcd(x, y) << std::endl;
    std::cout << gcd(100, 10) << std::endl;
    std::cout << gcd(5, 7) << std::endl;
    std::cout << gcd_euclid(16, 4) << std::endl;
    std::cout << gcd_euclid(81, 4) << std::endl;
    std::cout << gcd_euclid(121, 11) << std::endl;
    std::cout << gcd_euclid(256, 2) << std::endl;
    std::cout << gcd(8, 13441) << std::endl;
    return 0;
}

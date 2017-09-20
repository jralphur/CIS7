#include <iostream>
#include <vector>

int
main(void)
{
    int x;
    std::vector<int> squares;

    for (x = 0; x * x <= 169; ++x)
        std::cout << x * x << std::endl;
    return 0;
}

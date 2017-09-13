#include <iostream>
#include <string>

int
main(void)
{
    int d;
    std::string buf;
    do {
        std::cout << "enter an integer: " << std::endl;
        if (std::cin >> d)
            std::cout << d << ' ' << (d % 2 ? "is odd" : "is even") << std::endl;
        else  {
            std::cout << "non-integer detected" << std::endl;
            std::cin.clear();
        }
        std::cout << "try again? q for no, anything else for yes:" << std::endl;
        std::cin.ignore();
        std::getline(std::cin, buf);
    } while (!buf.empty() && buf[0] != 'q');

    return 0;
}

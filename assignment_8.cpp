#include <iostream>
#include <vector>

bool 
isprime(size_t i)
{
    if (i <= 1) return false;
    for (size_t k = 2; k < i; ++k)
        if (i % k == 0)
            return false;
    return true;
}


int
main(void)
{
    size_t upper, guess;
    size_t actual = 0;

    std::cout << "Enter a number greater than zero: ";
    std::cin >> upper;

    for (size_t i = 0; i <= upper; ++i)
        if (isprime(i)) {
            std::cout << i << std::endl;
            ++actual;
        }

    std::cout << "How many prime numbers exist? Guess: ";
    std::cin >> guess;

    if (guess == actual)
        std::cout << "Congrats, you are correct." << std::endl;
    else
        std::cout << "Too bad, try again." << std::endl;

    std::cout << "Number of primes: " << actual << std::endl;
    return 0;
}

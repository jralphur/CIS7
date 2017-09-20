#include <iostream>
#include <vector>

bool 
isprime(size_t i)
{
    if (i <= 1)
        return false;
    else if (i <= 3)
        return true;
    else if (i % 2 == 0 || i % 3 == 0)
        return false;
    size_t n = 5;
    while (i * i <= n) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
        i += 6;
    }
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
        if (isprime(i)) actual++;

    std::cout << "How many prime numbers exist? Guess: ";
    std::cin >> guess;

    if (guess == actual)
        std::cout << "Congrats, you are correct." << std::endl;
    else
        std::cout << "Too bad, try again." << std::endl;

    std::cout << "Number of primes: " << actual << std::endl;
    return 0;
}

#include <iostream>
#include <vector>
#include <string>

std::vector<std::pair<std::string,int>> call_stack;

void
echo_stack(void)
{
    if (!call_stack.empty())
        for (const auto &p : call_stack)
            std::cout << p.first << "(): " << "n = " << p.second << std::endl;
    std::cin.ignore();
}

int
factorial(int n)
{
    call_stack.push_back({__FUNCTION__, n});
    echo_stack();

    if (n == 0) { 
        call_stack.pop_back();
        return 1;
    }

    return n * factorial(n - 1);
}

int
fibonacci(int n)
{
    call_stack.push_back({__FUNCTION__, n});
    echo_stack();

    if (n <= 2)
        call_stack.pop_back();
        return 1;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int
main(void)
{
    int fact = factorial(3);
    call_stack.clear();
    int fib = fibonacci(5);
    call_stack.clear();
    std::cout << fact << '\t' << fib << std::endl;

    return 0;
}

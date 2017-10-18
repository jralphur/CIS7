#include <iostream>
#include <vector>
#include <string>

std::vector<std::pair<std::string,int>> call_stack;

void
echo_stack(void)
{
    if (!call_stack.empty())
        for (auto p = call_stack.rbegin();
                p != call_stack.rend();
                ++p)
            std::cout << p->first << "(): " << "n = " << p->second << std::endl;
    std::cin.ignore();
}


int
call_return(int (*fp)(int), int arg, const std::string name)
{
    call_stack.push_back({name, arg});
    echo_stack();
    int i = fp(arg);
    call_stack.pop_back();
    echo_stack();

    return i;
}

int
factorial(int n)
{

    if (n == 0) { 
        return 1;
    }

    return n * call_return(factorial, n - 1, "factorial");
}

int
fibonacci(int n)
{
    if (n <= 2) {
        return 1;
    }

    return call_return(fibonacci, n - 1, "fibonacci") + call_return(fibonacci, n - 2, "fibonacci");
}

int
main(void)
{
    int fact = call_return(factorial, 3, "factorial");
    call_stack.clear();
    int fib = call_return(fibonacci, 5, "fibonacci");
    call_stack.clear();
    std::cout << fact << '\t' << fib << std::endl;

    return 0;
}

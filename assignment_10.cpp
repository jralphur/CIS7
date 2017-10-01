#include <iostream>
#include <cmath>
#include <vector>


bool
isprime(int x) {
	if (x <= 1)
		return false;
	for (int i = 2; i < x; ++i)
		if (x % i == 0)
			return false;
	return true;
}

void
do_cofactors(int x, std::vector<int> &carry)
{


	if (isprime(x)) {
		carry.push_back(x);
		return;
	}

	int factor_upper = static_cast<int>(sqrt(x));

	while (factor_upper) {
		if (x % factor_upper == 0) {
			do_cofactors(factor_upper, carry);
			do_cofactors(x / factor_upper, carry);
			return;
		}
		factor_upper--;
	}
}

std::vector<int>
cofactors(int x) {
	std::vector<int> ret;
	do_cofactors(x, ret);

	return ret;
}

int
main(void)
{
	auto v = cofactors(121);
	std::cout << "found cofactors:" << std::endl;
	for (auto &i : v)
		std::cout << i << ' ';
	std::cout << std::endl;

	return 0;
}

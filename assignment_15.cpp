#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <deque>

/* - [ ] Write a program that contains 2 sets (Set A, and Set B).  You
can use whatever underlying type you want to represent these sets, but
they should hold string values
- [ ] In the program loop, the user should be displayed the values of
the contents of A and B as well as a menu with the following options:
- Add a value to A: Allow the user to add a string value to A
- Add a value to B: Allow the user to add a string value to B
- A interset B: Prints out the contents of A interset B
- A union B: Prints out the contents of A union B
- A diff B: Prints out the contents of A - B
- B diff A: Prints out the contents of B - Add
- Powersets: Prints out the powersets of A and B        */

using vset = std::vector<std::string>;
using vvset = std::vector<std::vector<std::string>>;

vset A;
vset B;

void print_sets(void);
void print_set(const vset &s);
void print_set(const vvset &s);
void main_menu(void);
void set_insert(vset &);
vset set_intersect(void);
vset set_union(void);
vset set_diff(vset, vset);
vvset set_powersets(vset);


void
print_sets(void)
{
	std::cout << "Set A: ";
	print_set(A);

	std::cout << "Set B: ";
	print_set(B);
}

void
print_set(const vset &s)
{
	for (const auto &elem : s)
		std::cout << elem << ' ';

	std::cout << std::endl;
}

void
print_set(const vvset &s)
{
	for (const auto &set: s) {
		std::cout << "{";
		for (const auto &e : set) {
			std::cout << e << ", ";
		}
		std::cout << "} " << std::endl;
	}
}

void
main_menu(void)
{
	std::cout << "A) Add to string to set A" << std::endl;
	std::cout << "B) Add to string to set B" << std::endl;
	std::cout << "C) Print out A intersect B" << std::endl;
	std::cout << "D) Print out A union B" << std::endl;
	std::cout << "E) Print out A diff B" << std::endl;
	std::cout << "F) Print out B diff A" << std::endl;
	std::cout << "G) Print out the powersets of A and B" << std::endl;
	std::cout << "H) Quit" << std::endl;
	std::cout << "Choice: ";
}

void
set_insert(vset &p) {
	std::string buf;
	std::cout << "Enter your string: " << std::endl;
	if (getline(std::cin, buf) && std::find(p.begin(), p.end(), buf) ==
		p.end()) {
		p.push_back(buf);
	}
}

vset
set_intersect(void)
{
	vset ret(A);
	ret.insert(ret.begin(), B.begin(), B.end());
	auto last = std::unique(ret.begin(), ret.end());
	ret.erase(ret.begin(), last);


	return ret;
}

vset
set_union(void)
{
	vset ret(A);
	ret.insert(ret.begin(), B.begin(), B.end());
	auto last = std::unique(ret.begin(), ret.end());
	ret.erase(last, ret.end());

	return ret;
}

vset
set_diff(vset one, vset other)
{
	vset ret(one);
	ret.erase(std::remove_if(ret.begin(), ret.end(), [other](std::string
		&p) { return std::find(other.begin(), other.end(), p) != other.end();
	}), ret.end());

	return ret;
}

vvset
set_powersets(vset set)
{
	int sz = set.size();
	vvset sets;
	for (int i = 0; i < (1 << sz); ++i) {
		vset ts;
		for (int j = 0; j < sz; ++j) {
			if (i & (1 << j))
				ts.push_back(set[j]);
		}
		sets.push_back(ts);
	}

	return sets;
}



int
main(void)
{
	std::string choice;
	vset temp;
	vvset temp2;

	do {
		print_sets();
		main_menu();
		std::getline(std::cin, choice);
		if (choice.size() == 0)
			continue;
		switch (toupper(choice[0])) {
		case 'A':
			set_insert(A);
			break;
		case 'B':
			set_insert(B);
			break;
		case 'C':
			temp = set_intersect();
			print_set(temp);
			break;
		case 'D':
			temp = set_union();
			print_set(temp);
			break;
		case 'E':
			temp = set_diff(A, B);
			print_set(temp);
			break;
		case 'F':
			temp = set_diff(B, A);
			print_set(temp);
			break;
		case 'G':
			temp2 = set_powersets(A);
			print_set(temp2);
			temp2 = set_powersets(B);
			print_set(temp2);
			break;
		case 'H':
			return 0;
		default:
			std::cout << "Enter a valid choice you fool" << std::endl;
			break;
		}
	} while (1);


	return 0;
}

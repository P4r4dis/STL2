#include "../include/Container.hpp"
int main()
{
	Contain<char, std::list> test;

	test.push('t');
	test.aff();
	test.add();
	test.aff();

	Contain<int, std::vector> test2;

	test2.push(1);
	test2.aff();
	test2.add();
	test2.aff();

	return 0;
}


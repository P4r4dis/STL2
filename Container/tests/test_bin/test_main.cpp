#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <criterion/parameterized.h>
#include <signal.h>

#include "../test_include/test_Container.hpp"


void    redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(Container, test_Container_main)//, .init = redirect_all_stdout)
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

	Contain<int, std::vector> test3;

	test3.push(7);
	test3.aff();
	test3.add();
	test3.aff();
}
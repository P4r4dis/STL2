#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <criterion/parameterized.h>
#include <signal.h>

#include "../test_include/test_Find.hpp"
void    redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(Find, test_Find)//, .init = redirect_all_stdout)
{
    const auto v = {1, 2, 3, 4};
    cr_assert(eq(uint, *do_find(v, 2), 2));
    std::cout << *do_find(v, 2) << std::endl;
}
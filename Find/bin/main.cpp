#include "../include/Find.hpp"

int     main()
{
    const auto v = {1, 2, 3, 4};

    std::cout << *do_find(v, 2) << std::endl;
    std::cout << *do_find(v, 27890) << std::endl;

    return 0;
}


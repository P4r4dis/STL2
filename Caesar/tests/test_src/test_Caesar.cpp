#include "../test_include/test_Caesar.hpp"

Caesar::Caesar(void) : _shift(3)
{}

void        Caesar::encryptChar(char plainchar)
{
    if (isalpha(plainchar))
    {
        if (isupper(plainchar))
        {
            plainchar = (plainchar - 'A' + _shift) % 26 + 'A';
        }
        else
        {
            plainchar = (plainchar - 'a' + _shift) % 26 + 'a';
        }
    }
    std::cout << plainchar;
    _shift++;
}
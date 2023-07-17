#include "../include/Caesar.hpp"

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
    if (_shift == 29)
        _shift = 3;
}

void        Caesar::decryptChar(char cipherchar)
{
    if (isalpha(cipherchar))
    {
        if (isupper(cipherchar))
        {
            cipherchar = (cipherchar - 'A' + (26 - _shift)) % 26 + 'A';
        }
        else
        {
            cipherchar = (cipherchar - 'a' + (26 - _shift)) % 26 + 'a';
        }
    }
    std::cout << cipherchar;
    _shift++;
    if (_shift == 29)
        _shift = 3;

}

void        Caesar::reset(void)
{
    _shift = 3;
}


int         Caesar::getShift(void) const
{
    return _shift;
}

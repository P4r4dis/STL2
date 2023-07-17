#ifndef                 __ONETIME__
#   define              __ONETIME__

#include <iostream>
#include <string>
#include "IEncryptionMethod.hpp"
class                   OneTime : public IEncryptionMethod
{
    public:
        OneTime(const std::string &key);

        void            encryptChar(char plainchar);
        void            decryptChar(char cipherchar);
        void            reset(void);
char shiftChar(char c, int shift)
{
    if (!isalpha(c))
        return c;

    char base = isupper(c) ? 'A' : 'a';
    return (c - base + shift + 26) % 26 + base;
}
    private:
        int             _keyIndex;
        std::string     _key;
};

#endif //               __ONETIME__
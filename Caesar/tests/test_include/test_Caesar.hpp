#ifndef                 __CAESAR_HPP__
    #define             __CAESAR_HPP__

#include <cctype>
#include <iostream>
#include "IEncryptionMethod.hpp"
class                   Caesar : public IEncryptionMethod
{
    public:
        Caesar(void);

        void            encryptChar(char plainchar);
    
    private:
        int             _shift;

};
#endif //               __CAESAR_HPP__
#ifndef                 __CAESAR_HPP__
    #define             __CAESAR_HPP__

#include <cctype>
#include <cstring>
#include <iostream>
#include <cstdint>
#include "IEncryptionMethod.hpp"
class                   Caesar : public IEncryptionMethod
{
    public:
        Caesar(void);

        void            encryptChar(char plainchar);
        void            decryptChar(char cipherchar);
        void            reset(void) ;
        int             getShift(void) const;
    
    private:
        int             _shift;

};
#endif //               __CAESAR_HPP__
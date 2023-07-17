#ifndef                         __ENCRYPTION__
    #define                     __ENCRYPTION__

#include "IEncryptionMethod.hpp"
#include <iostream>
#include <algorithm>

typedef void (IEncryptionMethod::*ptrMethod)(char);

class Encryption
{
    public:
        Encryption(IEncryptionMethod &ieMethod, ptrMethod function);

        void                        operator()(char c);
        static void                 encryptString(IEncryptionMethod &encryptionMethod, const std::string &toEncrypt);
        static void                 decryptString(IEncryptionMethod &encryptionMethod, const std::string &toDecrypt);
    private:
        IEncryptionMethod           &_ieMethod;
        ptrMethod                   _function;
    
};

// class Encryption
// {
// public:
//     Encryption(IEncryptionMethod& method, void (IEncryptionMethod::*function)(char));
//     void operator()(char c);

// private:
//     IEncryptionMethod& method;
//     std::function<void(char)> encryptionFunction;
//     // void (IEncryptionMethod::*encryptionFunction)(char)
// };
#endif //                       __ENCRYPTION__
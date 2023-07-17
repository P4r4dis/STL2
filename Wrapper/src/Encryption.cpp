#include "../include/Encryption.hpp"

Encryption::Encryption(IEncryptionMethod &ieMethod, ptrMethod function) : _ieMethod(ieMethod), _function(function)
{
}

void Encryption::operator()(char c)
{
    (_ieMethod.*_function) (c);
}

void Encryption::encryptString(IEncryptionMethod &encryptionMethod, const std::string &toEncrypt)
{
    encryptionMethod.reset();
    std::for_each(toEncrypt.begin(), toEncrypt.end(), Encryption(encryptionMethod, &IEncryptionMethod::encryptChar));
    std::cout << std::endl;
}


void Encryption::decryptString(IEncryptionMethod &encryptionMethod, const std::string &toDecrypt)
{
    encryptionMethod.reset();
    std::for_each(toDecrypt.begin(), toDecrypt.end(), Encryption(encryptionMethod, &IEncryptionMethod::decryptChar));
    std::cout << std::endl;
}

// Encryption::Encryption(IEncryptionMethod& method, void (IEncryptionMethod::*function)(char))
//     : method(method), encryptionFunction(std::bind(function, &method, std::placeholders::_1))
// {
//     method.reset();
// }

// void Encryption::operator()(char c)
// {
//     encryptionFunction(c);
// }
#include "../include/OneTime.hpp"

OneTime::OneTime(const std::string &key) : _keyIndex(0), _key(key)
{}

void        OneTime::encryptChar(char plainchar)
{
    // step 1: key char position
    char keyChar = std::tolower(_key[_keyIndex % _key.size()]);

    // Step 2: Shift the plain character
    // step 2.1: isalpha ?
    char encryptedChar = ' ';
    if (!isalpha(plainchar))
        encryptedChar = plainchar;
    else
    {
        // Step 2.2: Base calcul
        char base = isupper(plainchar) ?  'A' : 'a';
        // Step 2.3: shift calcul
        int shift = keyChar - 'a';
        encryptedChar = (plainchar - base + shift + 26) % 26 + base;
    }
    // char encryptedChar = shiftChar(plainchar, keyChar - 'a');

    // Step 3: Print the encrypted character
    std::cout << encryptedChar;

    // Step 4: Increment the key index
    _keyIndex++;
}

void        OneTime::decryptChar(char cipherchar)
{
    // step 1: key char position
    char keyChar = std::tolower(_key[_keyIndex % _key.size()]);

    // Step 2: Shift the plain character
    // step 2.1: isalpha ?
    char encryptedChar = ' ';
    if (!isalpha(cipherchar))
        encryptedChar = cipherchar;
    else
    {
        // Step 2.2: Base calcul
        char base = isupper(cipherchar) ?  'A' : 'a';
        // Step 2.3: shift calcul
        int shift = -(keyChar - 'a');
        // Step2.4: decrypt
        encryptedChar = (cipherchar - base + shift + 26) % 26 + base;
    }
    // Step 3: Print the encrypted character
    std::cout << encryptedChar;

    // Step 4: Increment the key index
    _keyIndex++;

}

void        OneTime::reset(void)
{
    _keyIndex = 0;
}
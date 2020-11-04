#include <string>

#include "runCaesarCipher.hpp"


std::string runCaesarCipher(const std::string& inpText, const size_t key, const bool encrypt){
    /*

    Encrypts/Decrypts a user entered/file entered string using a user provided key.
    String recieved will be in upper case alphabetical format as converted by the transfrom char function.

    Function Args:
        inpText: user/file written string, const as will simply be manipulated into a new string
        key: must be positive key for caesar so size_t is sufficient
        encrypt: simple boolean true if encrypting, false if decrypting... Catch a none input? No, will be dealt with in process command line

    Returns: 
        the encypted/decrypted string

    */

    std::string outText{""};
    std::string alphabet{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    int lenAlphabet{(int) alphabet.length()};//useful to have length of alphabet easily accessible in a variable

    //lambda function not required, makes for loop below simpler
    //potentially lambda will allow for more flexible ciphers in future
    auto newPosition=[&](int currPosition){
        if (encrypt){
            return (currPosition+int(key))%lenAlphabet; //using int(key) prevents any issues from arithmetic with size_t variable
        }else{
            return (lenAlphabet+(currPosition-int(key))%lenAlphabet)%lenAlphabet;
        }
    };

    for (const char& element : inpText){
        outText+=alphabet[newPosition((int) alphabet.find(element))];
    }

    return outText;




}
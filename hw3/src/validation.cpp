#include <iostream>
#include <string>
#include <cctype>
#include "validation.h"


bool validation::is_valid_password(std::string password){
    int length = password.size();
    bool hasUpper = false;
    bool hasNonAlphanum = false;

    for(char c : password){
        if(std::isupper(static_cast<unsigned char>(c))) hasUpper = true;
        if(!std::isalnum(static_cast<unsigned char>(c))) hasNonAlphanum = true;
    }

    if(hasUpper && hasNonAlphanum && (length >= 8)) return true;
    else return false;
}

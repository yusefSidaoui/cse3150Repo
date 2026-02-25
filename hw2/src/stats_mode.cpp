#include "stats_mode.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>

using std::cout, std::endl, std::string;

void stats_mode::run(int argc, char* argv[]){


    string word = argv[2];

    cout << "Length: " << word.size() << endl;

    int uniqueChars = 0;
    string uniqueStr = "";

    for(char c : word){
        if(!uniqueStr.contains(c)){
            uniqueStr += c;
            uniqueChars++;
        }
    }

    cout << "Unique characters: " << uniqueChars << endl;
    bool anOnly = true;
    for(char c : word){
        if(!std::isalnum(c)){
            anOnly = false;
            break;
        }
    }
    if(anOnly) cout << "Alphanumeric Yes" << endl;
    else cout << "Alphanumeric No" << endl;

    string reversed = "";

    for(size_t i = word.size() - 1; i >= 0; i--){
        reversed += word[i];
    }
    cout << "Reversed: " << reversed << endl;

    string noSpace = "";

    for(char c : word){
        if(!std::isspace(c)){
            noSpace += c;
        }
    }

    word = noSpace;

    cout << "Without spaces: " << word << endl;

    bool isPalindrome = true;
    for(size_t i = 0; i < word.size(); i++){
        if(std::tolower(word[i]) != std::tolower(word[word.size()-1-i])){
            isPalindrome = false;
        }
    }

    if(isPalindrome) cout << "Palindrome Yes" << endl;
    else cout << "Palindrome No" << endl;

}

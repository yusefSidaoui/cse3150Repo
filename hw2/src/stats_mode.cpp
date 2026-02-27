#include "stats_mode.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>

using std::cout, std::endl, std::string;

void stats_mode::run(int argc, char* argv[]){

    if(argc < 3){
        cout << "Need 3 arguements" << endl;
        return;
    }
    string word = argv[2];

    cout << "Length " << word.size() << endl;

    int uniqueChars = 0;
    string uniqueStr = "";

    for(char c : word){

        size_t pos = uniqueStr.find(c);

        if(pos == string::npos){
            uniqueStr += c;
            uniqueChars++;
        }
    }

    cout << "Unique " << std::to_string(uniqueChars) << endl;
    bool anOnly = true;
    for(char c : word){
        if(!std::isalnum(c)){
            anOnly = false;
            break;
        }
    }
    if(anOnly) cout << "Alphanumeric Yes" << endl;
    else cout << "Alphanumeric No" << endl;
    string old = word;
    char placeholder = 'a';
    for(size_t i = 0; i < word.size()/2.0; i++){
        placeholder = word[i];
        word[i] = word[word.size()-1-i];
        word[word.size()-1-i] = placeholder;
    }
    cout << "Reversed " << word << endl;
    string noSpace = "";
    size_t pos1 = old.find(" ");
    if(pos1 != string::npos){
        for(char c : old){
            if(!std::isspace(c)){
                noSpace += c;
            }
        }
        old = noSpace;
        cout << "Without spaces " << old << endl;
    }else{
        cout << "withoutspaces" << old << endl;
    }


    bool isPalindrome = true;
    for(size_t i = 0; i < old.size(); i++){
        if(std::tolower(old[i]) != std::tolower(old[old.size()-1-i])){
            isPalindrome = false;
        }
    }

    if(isPalindrome) cout << "Palindrome Yes" << endl;
    else cout << "Palindrome No" << endl;

}

#include "text_mode.h"
#include <string>
#include <iostream>
#include <cctype>

using std::cout, std::endl, std::string;
void text_mode::run(int argc, char*argv[]){

    if (argc < 3) {
        cout << "Usage: ./analyzer text <string>" << endl;
        return;
    }

    string text = argv[2];
    cout << "Original: " << text << endl;

    cout << "Length: " << text.size() << endl;

    int letters = 0;
    int digits = 0;
    int spaces = 0;
    int punc = 0;

    string allUpper = "";

    for(char c : text){
        if(std::isalpha(c)) letters++;
        else if(std::isdigit(c)) digits++;
        else if(std::isspace(c)) spaces++;
        else if(std::ispunct(c)) punc++;

        allUpper += std::toupper(c);
    }
    cout << "Letters: " << letters << endl;
    cout << "Digits: " << digits << endl;
    cout << "Spaces: " << spaces << endl;
    cout << "Punctuation: " << punc << endl;

    cout << "All uppercase: " << allUpper << endl;

    for(size_t i = 0; i < text.size(); i++){
        text[i] = std::tolower(text[i]);
    }
    cout << "All lowercase: " << text << endl;
    size_t pos = text.find("test");
    if(pos != string::npos){
        cout << "containstestyes" << endl;
    }else{
        cout << "containstestno" << endl;
    }

    if(spaces > 0){
        size_t pos2 = text.find(" ");
        cout << "First word: " << text.substr(0, pos2) << endl;
    }



}

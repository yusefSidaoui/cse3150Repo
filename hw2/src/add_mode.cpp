#include "add_mode.h"
#include <string>
#include <iostream>
#include <cctype>

using std::cout, std::endl, std::string;

int add_mode::add(int a, int b){
    return a + b;
}

double add_mode::add(double a, double b){
    return a + b;
}

std::string add_mode::add(std::string a, std::string b){
    return a + b;
}

void add_mode::run(int argc, char* argv[]){

    string s1 = argv[2];
    string s2 = argv[3];

    bool char1 = false;
    bool decimal1 = false;

    bool char2 = false;
    bool decimal2 = false;

    for(char c : s1){
        if(std::isalpha(c)){
            char1 = true;
            break;
        }
    }

    for(char c : s2){
        if(std::isalpha(c)){
            char2 = true;
            break;
        }
    }

    if(s1.find('.') != string::npos) decimal1 = true;
    if(s2.find('.') != string::npos) decimal2 = true;


    if(char1 || char2){
        cout << "Result: " << add_mode::add(s1, s2) << endl;
    }
    else if(decimal1 || decimal2){
        double a = std::stod(s1);
        double b = std::stod(s2);
        cout << "Result: " << add_mode::add(a, b) << endl;
    }
    else{
        int a = std::stoi(s1);
        int b = std::stoi(s2);
        cout << "Result: " << add_mode::add(a, b) << endl;
    }
}

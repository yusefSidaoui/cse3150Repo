#include "add_mode.h"
#include <string>
#include <iostream>
#include <cctype>

using std::cout, std::endl, std::string;

int add(int a, int b){
    return a + b;
}

double add(double a, double b){
    return a + b;
}

std::string add(std::string a, std::string b){
    return a + b;
}

void add_mode::run(int argc, char* argv[]){

    if(argc < 4){
    cout << "Usage: ./analyzer <mode> [arguments]" << endl;
    return;
    }

    string s1 = argv[2];
    string s2 = argv[3];

    bool onlyDig1 = true;

    bool decimal1 = false;

    bool onlyDig2 = true;
    bool decimal2 = false;

    for(char c : s1){
        if(!std::isdigit(c)){
            onlyDig1 = false;
            break;
        }
    }

    for(char c : s2){
        if(!std::isdigit(c)){
            onlyDig2 = false;
            break;
        }
    }

    if(s1.find('.') != string::npos) decimal1 = true;
    if(s2.find('.') != string::npos) decimal2 = true;


    if(onlyDig1 && onlyDig2){
        int a = std::stoi(s1);
        int b = std::stoi(s2);
        cout << "Result: " << std::to_string(add(a, b)) << endl;
    }
    else if(decimal1 || decimal2){
        double a = std::stod(s1);
        double b = std::stod(s2);
        cout << "Result: " << std::to_string(add(a, b)) << endl;
    }
    else{
        cout << "Result: " << add(s1, s2) << endl;
    }
}

#include <iostream>
#include "string_utils.h"

using std::cout, std::endl, std::cin;

void string_utils::runStringOption(){
    int slength;
    std::string input;
    cout << "Enter string length: " << endl;
    cin >> slength;

    if(slength >= 20){
      cout << "Error: Cannot exceed 20" << endl;
      std::exit(1);
    }
    std::cin.ignore();
    cout << "Enter string: " << endl;
    std::getline(cin, input);

    char carray[20];
    for (int i = 0; i < input.length(); i++){
        carray[i] = input[i];
    }
    carray[input.length()] = '\0';

    cout << "C-style string: " << carray << endl;
}

#include <iostream>
#include "integer_utils.h"

using std::cout, std::endl, std::cin;

void integer_utils::runIntegerOption(){
    int a;
    int b;
    cout << "Enter first integer: " << endl;
    cin >> a;
    cout << "Enter second integer: " << endl;
    cin >> b;

    if(b == 0){
        cout << "Error: division by zero" << endl;
        return;
    } else{
        float val = a / b;
        cout << "Result: " << val << endl;
    }
    // this is a single line comment
    cout << "After post-increment: " << a++ << endl;
    cout << "After pre-increment: " << ++a << endl;
}

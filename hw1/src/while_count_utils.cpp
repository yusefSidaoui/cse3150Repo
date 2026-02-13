#include <iostream>
#include "while_count_utils.h"

using std::cout, std::endl, std::cin;

void while_count_utils::runWhileCount(){
    int num = 11;
    cout << "Enter a number to count to: " << endl;
    cin >> num;
    while(num > 10){
        cout << "I'm programmed to only count up to 10!" << endl;
        cout << "Enter a number to count to: " << endl;
        cin >> num;
    }
    int i = num-1;
    while(i >= 0){
        cout << num-i << endl;
        i--;
        if(num-i == 5) i--;
    }
}

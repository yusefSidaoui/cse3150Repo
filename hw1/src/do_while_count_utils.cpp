#include <iostream>
#include "do_while_count_utils.h"

using std::cout, std::endl, std::cin;

void do_while_count_utils::runDoWhileCount(){
    int num;
    do{
        cout << "Enter a number between 1 and 5: " << endl;
        cin >> num;
    } while(num < 1 || num > 5);

    int array[5] {1, 2, 3, 4, 5};

    for(int i : array){
        cout << "Value: " << array[i] << endl;
        if(array[i] == num) break;
    }
}

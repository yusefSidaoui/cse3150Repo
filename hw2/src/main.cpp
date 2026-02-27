#include <iostream>
#include <string>
#include "text_mode.h"
#include "add_mode.h"
#include "stats_mode.h"
using std::cout, std::endl;

int main(int argc, char*argv[]){

    if(argc < 2){
        cout << "Usage: ./analyzer <mode> [arguments]" << endl;
        return 1;
    }
    int choiceNum = 0;
    std::string choice = argv[1];
    if(choice=="text") choiceNum = 1;
    else if(choice=="add") choiceNum = 2;
    else if(choice=="stats") choiceNum = 3;

    switch(choiceNum){
        case 1:
            text_mode::run(argc, argv);
            break;
        case 2:
            add_mode::run(argc, argv);
            break;
        case 3:
            stats_mode::run(argc, argv);
            break;
        default:
            cout << "Invalid mode" << endl;
            return 1;
    }



    return 0;
}

#include <iostream>
#include "grade_utils.h"

using std::cout, std::endl, std::cin;

double grade_utils::calculateGrade(){
    char stype;
    int grade;
    cout << "Enter student type (U for undergrad, G for grad): " << endl;
    cin >> stype;
    cout << "Enter numeric grade: " << endl;
    cin >> grade;
    if(grade < 0 || grade > 100){
        throw std::runtime_error("Invalid grade");
    }

    switch(stype){
        case 'U':
            if (grade >= 60) cout << "Status: Pass" << endl;
            else cout << "Status: Fail" << endl;
            break;
        case 'G':
            if (grade >= 70) cout << "Status: Pass" << endl;
            else cout << "Status: Fail" << endl;
            break;
    }
    return grade;
}

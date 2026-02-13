#include <iostream>
#include "integer_utils.h"
#include "string_utils.h"
#include "grade_utils.h"
#include "while_count_utils.h"
#include "do_while_count_utils.h"

using std::cin, std::cout, std::endl;

int main(){

    int choice;
	while(1){

		cout << "Enter 1-6" << endl << endl;
		cout << "1. Integer operations" << endl <<
			"2. Charactre arrays and c-style strings" << endl <<
			"3. Grade evaluation" << endl <<
			"4. While-loop counting" << endl <<
			"5. Do-while and range-based for counting" << endl <<
			"6. Quit" << endl;
		cin >> choice;

		switch(choice){
			case 1:
				integer_utils::runIntegerOption();
                break;
            case 2:
                string_utils::runStringOption();
                break;
            case 3:
                grade_utils::calculateGrade();
                break;
            case 4:
                while_count_utils::runWhileCount();
                break;
            case 5:
                do_while_count_utils::runDoWhileCount();
                break;
            case 6:
                cout << "Goodbye!" << endl;
                return 0;
        }

    }
    return 0;
}

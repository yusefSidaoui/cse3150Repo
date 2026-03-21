#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "audit_mode.h"
#include "validation.h"

using std::string, std::endl, std::cout, std::cin;

void audit_mode::process_file(std::string input, std::string output){
    std::ifstream inFile(input);

    if(!inFile){
        cout << "Error opening file" << endl;
        return;
    }

    std::ofstream outFile(output, std::ios::app);

    if(!outFile){
        cout << "Error opening file" << endl;
        return;
    }

    char iD;
    char oD;
    if (input.size() >= 4 && input.substr(input.size() - 4) == ".tsv")
        iD = '\t';
    else iD = ',';
    if (output.size() >= 4 && output.substr(output.size() - 4) == ".tsv")
        oD = '\t';
    else if (output.size() >= 4 && output.substr(output.size() - 4) == ".csv")
    oD = ',';
    else oD = '\t';

    std::string line;
    while(std::getline(inFile, line)){

        std::stringstream ss(line);

        std::string username, email, password;

        std::getline(ss, username, iD);
        std::getline(ss, email, iD);
        std::getline(ss, password);

        if(!validation::is_valid_password(password)){

            outFile << username << oD << email << oD << password << '\n';
        }
    }

    inFile.close();
    outFile.close();


}

void audit_mode::run_menu(){

    while(1){

        cout << "1. Check a single password" << endl <<
        "2. Process a TSV/CSV file" << endl <<
        "3. Quit" << endl;
        int choice = 0;

        cin >> choice;

        switch (choice){
            case 1:{
                string pass;
                cout << "Enter a password: " << endl;
                cin.ignore();
                std::getline(cin, pass);

                if (validation::is_valid_password(pass))
                    std::cout << "Valid\n";
                else
                    std::cout << "Invalid\n";

                break;
            }
            case 2:{
                string input;
                string output;
                cout << "Input file path: " << endl;
                cin >> input;
                cout << "Output file path: " << endl;
                cin >> output;
                process_file(input, output);
                break;
            }
            case 3:
                return;
        }

    }
 }

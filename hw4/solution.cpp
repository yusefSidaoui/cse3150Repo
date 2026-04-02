#include <iostream>
#include <cstring>   // for strlen, strcpy

using std::cout, std::endl, std::cin;

void addStudent(char* name, double gpa, char* names[], double gpas[], int& size, int capacity){
    if(size >= capacity) throw "List full, can't add more";
    names[size] = new char[std::strlen(name) + 1];
    std::strcpy(names[size], name);
    gpas[size] = gpa;
    size++;
}

void updateGPA(double* gpaPtr, double newGpa){
    *gpaPtr = newGpa;
}

void printStudent(const char* name, const double& gpa){
    cout << "Name: " << name << ", Gpa: " << gpa << endl;
}

double averageGPA(const double gpas[], int size){
    if (size == 0) throw "No students on record";

    double average = 0.0;
    for(int i = 0; i < size; i++){
        average += gpas[i];
    }
    average/=size;
    return static_cast<int>(average);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./program <capacity>" << std::endl;
        return 1;
    }

    int capacity = std::stoi(argv[1]);

    char** names = new char*[capacity];
    double* gpas = new double[capacity];
    int size = 0;

    int choice;
    do {
        std::cout << "Menu:\n";
        std::cout << "1. Add student\n";
        std::cout << "2. Update GPA\n";
        std::cout << "3. Print all students\n";
        std::cout << "4. Compute average GPA\n";
        std::cout << "5. Quit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                char name[15];
                double gpa;
                cout << "Enter name: " << endl;
                cin.ignore();
                cin.getline(name, 15);
                cout << "Enter GPA: " << endl;
                cin >> gpa;
                try{
                    addStudent(name, gpa, names, gpas, size, capacity);
                }catch (const char* msg) {
                    cout << msg << endl;
                }
                break;
            }
            case 2: {
                int index;
                double newGpa;
                cout << "Enter index: " << endl;
                cin >> index;
                cout << "Enter new Gpa: " << endl;
                cin >> newGpa;
                updateGPA(&gpas[index], newGpa);
                break;
            }
            case 3: {
                for(int i = 0; i < size; i++){
                    printStudent(names[i],gpas[i]);
                }
                break;
            }
            case 4: {
                try{
                    double a = averageGPA(gpas, size);
                    cout << "Average GPA: " << a << endl;
                } catch (const char* msg){
                    cout << msg << endl;
                }
                break;
            }
            case 5: {
                std::cout << "Goodbye!" << std::endl;
                break;
            }
            default: {
                std::cout << "Invalid choice" << std::endl;
            }
        }
    } while (choice != 5);

    // TODO: free memory
    delete[] gpas;
    gpas = nullptr;

    for(int i = 0; i < size; i++){
        delete[] names[i];
    }
    delete[] names;
    names = nullptr;

    return 0;
}

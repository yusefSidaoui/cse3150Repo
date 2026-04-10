Explanation of functions:

addstudent 
-will throw an exception if the list of students is full
-the input int is passed as a reference because it needs to change after the function is done

updateGPA
-gpaPtr is passed as a pointer which is why it needs to be dereferenced in the function before it is given a new value

printStudent
-both its inputs are const because they should never be changed by the function

averageGPA
-throws an exception if the list of students is empty
-before it returns the average, it rounds the value by casting it as an int

main
-the menu that the user interacts with is a switch case statement that lets the user choose any function
-for some options, main can catch a thrown exception and print the error
-when the user quits, the arrays that held the gpa values and students are freed from memory

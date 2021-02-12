// compile: g++ -std=c++11 -o pointers pointers.cpp
#include <iostream>
#include <string>
#include <sstream>
#include <climits>


typedef struct Student {
    int id;
    char *f_name;
    char *l_name;
    int n_assignments;
    double *grades;
} Student;

int promptInt(std::string message, int min, int max);
double promptDouble(std::string message, double min, double max);
void calculateStudentAverage(void *object, double *avg);

int main(int argc, char **argv) {
    Student student;
    double average;
    int isValid = 0;
    student.f_name = new char[128];
    student.l_name = new char[128];
    // Sequence of user input -> store in fields of `student`
    //ID number
    student.id = promptInt("Please enter the student's ID number: ", 1, 999999999);
    //First name
    std::cout << "Please enter the student's FIRST name: ";
    scanf("%s", student.f_name);
    //Last name
    std::cout << "Please enter the student's LAST name: ";
    scanf("%s", student.l_name);
    //Number of assignments
    student.n_assignments = promptInt("Please enter how many assignments were graded: ", 1, 134217728);
    student.grades = new double[student.n_assignments];
    //Grades
    for (int i = 0; i < student.n_assignments; i++) {
        std::string message = "Please enter grade for assignment " + std::to_string(i) + ": ";
        student.grades[i] = promptDouble(message, 0.0, 1000.0);
    }
    // Calculates average
    double zero = 0.0;
    double *avg = &zero; 
    calculateStudentAverage(&student, avg);
    // Output `average`
    printf("Student: %s %s [%d] \n", student.f_name, student.l_name, student.id);
    //check tab or two spaces
    printf("  Average Grade: %.1lf \n", *avg);
    return 0;
}

/*
   message: text to output as the prompt
   min: minimum value to accept as a valid int
   max: maximum value to accept as a valid int
*/
int promptInt(std::string message, int min, int max) {
    // Code to prompt user for an int
    int input;
    std::cout << message;
    while (!(std::cin >> input) || input < min || input > max) {
        std::cout << "Sorry, I cannot understand your answer";
        std::cout << "\n";
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');    
        std::cout << message;
    }
    return input;
}

/*
   message: text to output as the prompt
   min: minimum value to accept as a valid double
   max: maximum value to accept as a valid double
*/
double promptDouble(std::string message, double min, double max) {
    double input;
    std::cout << message;
    while (!(std::cin >> input) || input < min || input > max) {
        std::cout << "Sorry, I cannot understand your answer";
        std::cout << "\n";
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');    
        std::cout << message;
    }
    return input;
}

/*
   object: pointer to anything - your choice! (but choose something that will be helpful)
   avg: pointer to a double (can store a value here)
*/
void calculateStudentAverage(void *object, double *avg) {
    // Code to calculate and store average grade
    Student *student = (Student*)object; 
    int size = student->n_assignments;
    //for number of objects add them all together and then divide by the number
    for (int i = 0; i < size; i++) {
        *avg += student->grades[i]; 
    }
    *avg = *avg / (double)size;
}
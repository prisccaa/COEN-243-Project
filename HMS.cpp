#include "HMS.h"
using namespace std;

// DEFINING constructors and members/functions
void Patient::Print_Doctor_Info(){
    cout << "Doctor Name: " << firstName << " " << lastName << endl;
    cout << "Doctor ID: " << ID << endl;
    cout << "Specialty: " << specialty << endl;
    cout << "Years of Experience: " << yearOfExperience << endl;
    cout << "Base Salary: " << baseSalary << endl;
    cout << "Performance Bonus: " << bonusPercentage << endl;
    cout << "Total Salary: " << CalculateCompensation() << endl;
}
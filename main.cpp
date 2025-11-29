#include <iostream>
#include <string>
#include "HMS.h"
using namespace std;

int main(){
   
    Hospital HSM1("patients.txt", "doctors.txt");
    
    int choice = -1;

    while (choice != 0){
        cout << "Hospital Management System Menu:" << endl;
        cout << "1. Find Oldest Patient" << endl;
        cout << "2. Count Critical Patients" << endl;
        cout << "3. Count In-Patients" << endl;
        cout << "4. List Doctors by Specialty" << endl;
        cout << "5. Show Patient by ID" << endl;
        cout << "6. Show Doctor by ID" << endl;
        cout << "7. Show Assigned Doctor for a Patient" << endl;
        cout << "8. Show Assigned Patients for a Doctor" << endl;
        cout << "9. Append Patient to File" << endl;
        cout << "10. Append Doctor to File" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        while(choice < 0 || choice > 10){
            cout << "Invalid choice. Please enter a number between 0 and 10: ";
            cin >> choice;
        }

        switch (choice){
            case 1:
                HSM1.Find_Oldest_Patient();
                break;
            case 2:
                cout << "Number of Critical Patients: " << HSM1.Count_Critical_Patients() << endl;
                break;
            case 3:
                cout << "Number of In-Patients: " << HSM1.Count_In_Patients() << endl;
                break;
            case 4:{
                string specialty;
                cout << "Enter Specialty: ";
                cin >> specialty;
                HSM1.Doctors_By_Specialty(specialty);
                break;
            }
            case 5:{
                long int patientID;
                cout << "Enter Patient ID: ";
                cin >> patientID;
                HSM1.Show_Patient_by_ID(patientID);
                break;
            }
            case 6:{
                long int doctorID;
                cout << "Enter Doctor ID: ";
                cin >> doctorID;
                HSM1.Show_Doctor_by_ID(doctorID);
                break;
            }
            case 7:{
                long int patientID;
                cout << "Enter Patient ID: ";
                cin >> patientID;
                HSM1.Show_Assigned_Doctor(patientID);
                break;
            }
            case 8:{
                long int doctorID;
                cout << "Enter Doctor ID: ";
                cin >> doctorID;
                HSM1.Show_Assigned_Patients(doctorID);
                break;
            }
            case 9:
                HSM1.Append_Patient_To_File();
                break;
            case 10:
                HSM1.Append_Doctor_To_File();
                break;
        }
    }   
    return 0;
}

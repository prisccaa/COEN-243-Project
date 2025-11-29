#ifndef HMS_H
#define HMS_H
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <ostream>
#include <iomanip>
using namespace std;

class Patient{
    private: // Patient attributes
        string firstName;
        string lastName;
        long int ID;
        long int assignedDoctor;
        string dateOfBirth;
        string bloodType;
        string diagnosis;
        string dateOfAdmission;
        string dischargeDate;
    
    public: // Getter and Setter methods (could put them in the cpp file too)
        string get_firstName(){return firstName;}
        void set_firstName(string fN){firstName = fN;}
        string get_lastName(){return lastName;}
        void set_lastName(string lN){lastName = lN;}
        long int get_ID(){return ID;}
        void set_ID(long int id){ID = id;}
        long int get_assignedDoctor(){return assignedDoctor;}
        void set_assignedDoctor(long int aD){assignedDoctor = aD;}
        string get_dateOfBirth(){return dateOfBirth;}
        void set_dateOfBirth(string dob){dateOfBirth = dob;}
        string get_bloodType(){return bloodType;}
        void set_bloodType(string bt){bloodType = bt;}
        string get_diagnosis(){return diagnosis;}
        void set_diagnosis(string diag){diagnosis = diag;}
        string get_dateOfAdmission(){return dateOfAdmission;}
        void set_dateOfAdmission(string doa){dateOfAdmission = doa;}
        string get_dischargeDate(){return dischargeDate;}
        void set_dischargeDate(string dd){dischargeDate = dd;}

        // Methods, only DECLARING them
        
        // Checks if the patient is discharged:
        bool IsDischarged();
        // Returns the status based on the diagnosis:
        string Patient_Status(); // Assuming there is no typo...
        // Displays all the patient’s information of the data members:
        void Print_Patient_Info();
};

class Doctor{
    // Doctor attributes
    private:
        string firstName;
        string lastName;
        long int ID;
        string specialty;
        int yearOfExperience;
        double baseSalary;
        double bonusPercentage;

    public:
        // Getter and Setter methods (could put them in the cpp file too)
        string get_firstName(){return firstName;}
        void set_firstName(string fN){firstName = fN;}
        string get_lastName(){return lastName;}
        void set_lastName(string lN){lastName = lN;}
        long int get_ID(){return ID;}
        void set_ID(long int id){ID = id;}
        string get_specialty(){return specialty;}
        void set_specialty(string spec){specialty = spec;}
        int get_yearOfExperience(){return yearOfExperience;}
        void set_yearOfExperience(int yoe){yearOfExperience = yoe;}
        double get_baseSalary(){return baseSalary;}
        void set_baseSalary(double bs){baseSalary = bs;}
        double get_performanceBonus(){return bonusPercentage;}
        void set_performanceBonus(double pb){bonusPercentage = pb;}

        // Methods, just DECLARING them
        double CalculateCompensation();
        void Print_Doctor_Info();

};

class Hospital{
    private:
        vector<Patient> *ptr;
        vector<Doctor> *dptr;  
    public:

    // DECLARING Constructor that reads files
    Hospital(const string& fileName);

    // Methods and Functions:
    void Find_Oldest_Patient();
    int Count_Critical_Patients();
    int Count_In_Patients();
    void Doctors_By_Specialty();
    void Show_Patient_by_ID(int id);
    void Show_Doctor_by_ID();
};





#endif // HMS_H
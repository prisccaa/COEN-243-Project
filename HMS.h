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
        string get_firstName();
        void set_firstName(string fN);
        string get_lastName();
        void set_lastName(string lN);
        long int get_ID();
        void set_ID(long int id);
        long int get_assignedDoctor();
        void set_assignedDoctor(long int aD);
        string get_dateOfBirth();
        void set_dateOfBirth(string dob);
        string get_bloodType();
        void set_bloodType(string bt);
        string get_diagnosis();
        void set_diagnosis(string diag);
        string get_dateOfAdmission();
        void set_dateOfAdmission(string doa);
        string get_dischargeDate();
        void set_dischargeDate(string dd);

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
        string get_firstName();
        void set_firstName(string fN);
        string get_lastName();
        void set_lastName(string lN);
        long int get_ID();
        void set_ID(long int id);
        string get_specialty();
        void set_specialty(string spec);
        int get_yearOfExperience();
        void set_yearOfExperience(int yoe);
        double get_baseSalary();
        void set_baseSalary(double bs);
        double get_performanceBonus();
        void set_performanceBonus(double pb);

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
    Hospital(const string& doctorFile, const string& patientFile);

    // Methods and Functions:
    void Find_Oldest_Patient();
    int Count_Critical_Patients();
    int Count_In_Patients();
    void Doctors_By_Specialty();
    void Show_Patient_by_ID(int id);
    void Show_Doctor_by_ID();
};

#endif // HMS_H

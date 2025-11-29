#ifndef HMS_H
#define HMS_H
#include <string>
#include <iostream>
#include <vector>
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
    
    public: // Getter and Setter methods
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

        // Default Constructor with parameter initialization
        Patient();
        // Patient(const string &firstName, 
        // const string &lastName,
        // long ID,
        // long assignedDoctor,
        // const string &dateOfBirth,
        // const string &bloodType,
        // const string &diagnosis,
        // const string &dateOfAdmission, 
        // const string &dischargeDate);

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

        Doctor();
        // Doctor(const string &firstName, 
        // const string &lastName,
        // long ID,
        // long specialty,
        // const string &yearOfExperience,
        // const string &baseSalary,
        // const string &diagnosis,
        // const string &bonusPercentage);

        // Methods, just DECLARING them
        double CalculateCompensation();
        void Print_Doctor_Info();
};

class Hospital{
    
    private:
        vector<Patient> *patients;
        vector<Doctor> *doctors;  
    
        public:

    // DECLARING Constructor that reads files
    Hospital();
    ~Hospital();
    Hospital(string patientFileName, string doctorFileName);

    // Methods and Functions:
    void Find_Oldest_Patient();
    int Count_Critical_Patients();
    int Count_In_Patients();
    void Doctors_By_Specialty(string& s);
    void Show_Patient_by_ID(long int id);
    void Show_Doctor_by_ID(long int id);
    void Show_Assigned_Doctor(long int patientID);
    void Show_Assigned_Patients(long int doctorID);
    void Append_Patient_To_File();
    void Append_Doctor_To_File();
};

#endif 

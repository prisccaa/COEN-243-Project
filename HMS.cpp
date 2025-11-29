#include "HMS.h"
#include <string>
#include <fstream>
#include <ostream>
#include <iostream>
#include <vector>
using namespace std;

// DEFINING METHODS
// FOR PATIENT CLASS

string Patient::get_firstName(){return firstName;}
void Patient::set_firstName(string fN){firstName = fN;}
string Patient::get_lastName(){return lastName;}
void Patient::set_lastName(string lN){lastName = lN;}
long int Patient::get_ID(){return ID;}
void Patient::set_ID(long int id){ID = id;}
long int Patient::get_assignedDoctor(){return assignedDoctor;}
void Patient::set_assignedDoctor(long int aD){assignedDoctor = aD;}
string Patient::get_dateOfBirth(){return dateOfBirth;}
void Patient::set_dateOfBirth(string dob){dateOfBirth = dob;}
string Patient::get_bloodType(){return bloodType;}
void Patient::set_bloodType(string bt){bloodType = bt;}
string Patient::get_diagnosis(){return diagnosis;}
void Patient::set_diagnosis(string diag){diagnosis = diag;}
string Patient::get_dateOfAdmission(){return dateOfAdmission;}
void Patient::set_dateOfAdmission(string doa){dateOfAdmission = doa;}
string Patient::get_dischargeDate(){return dischargeDate;}
void Patient::set_dischargeDate(string dd){dischargeDate = dd;}
    
bool Patient::IsDischarged(){
    if(dischargeDate != "-1"){return true;}
        else{return false;}
    }

string Patient::Patient_Status(){ // Assuming there is no typo...
    if (diagnosis.find("critical")){
        return "Critical";
    }
    else if(diagnosis.find("moderate")){
        return "Moderate"; 
    }
    else {
        return "Stable";
    }
}

void Patient::Print_Patient_Info(){
    cout << "Patient Name: " << firstName << " " << lastName << endl;
    cout << "Patient ID: " << ID << endl;
    cout << "Assigned Doctor ID: " << assignedDoctor << endl;
    cout << "Date of Birth: " << dateOfBirth << endl;
    cout << "Blood Type: " << bloodType << endl;
    cout << "Diagnosis: " << diagnosis << endl;
    cout << "Date of Admission: " << dateOfAdmission << endl;
    cout << "Discharge Date: " << dischargeDate << endl;
}

// DEFINING METHODS   
// FOR DOCTOR CLASS

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

void Doctor::Print_Doctor_Info(){
    cout << "Doctor Name: " << firstName << " " << lastName << endl;
    cout << "Doctor ID: " << ID << endl;
    cout << "Specialty: " << specialty << endl;
    cout << "Years of Experience: " << yearOfExperience << endl;
    cout << "Base Salary: " << baseSalary << endl;
    cout << "Performance Bonus: " << bonusPercentage << endl;
    cout << "Total Salary: " << CalculateCompensation() << endl;
}

double Doctor::CalculateCompensation(){
    return baseSalary * (1 + bonusPercentage);
}

// DEFINING CONSTRUCTOR
// FOR HOSPITAL CLASS

// Defining constructor that reads files
Hospital::Hospital(const string& doctorFile, const string& patientFile){
    
    patients = new vector<Patient>();
    doctors = new vector<Doctor>();

    ifstream patFile("Patients.txt");
    ifstream docFile("Doctors.txt");

    if (!patFile){
        cout << "Error opening patient file!" << endl;
    }

    int numPatients;
    patFile >> numPatients;

    for (size_t i = 0; i < numPatients; i++){
        
        Patient p;

        string fN;
        string lN;
        long int id;
        long int aD;
        string dob;
        string bt;
        string diag;
        string doa;
        string dd;
        
        patFile >> fN >> lN >> id >> aD >> dob >> bt >> diag >> doa >> dd;

        p.set_firstName(fN);
        p.set_lastName(lN);
        p.set_ID(id);
        p.set_assignedDoctor(aD);
        p.set_dateOfBirth(dob);
        p.set_bloodType(bt);
        p.set_diagnosis(diag);
        p.set_dateOfAdmission(doa);
        p.set_dischargeDate(dd);

        patients->push_back(p);
    }

    if (!docFile){
        cout << "Error opening doctor file!" << endl;
    }

    int numDoctors;
    docFile >> numDoctors;

    for (size_t i = 0; i < numDoctors; i++){
        
        Doctor d;
        
        string fN;
        string lN;
        long int id;
        string spec;
        int yoe;
        double bs;
        double pb;
        
        docFile >> fN >> lN >> id >> spec >> yoe >> bs >> pb;

        d.set_firstName(fN);
        d.set_lastName(lN);
        d.set_ID(id);
        d.set_specialty(spec);
        d.set_yearOfExperience(yoe);
        d.set_baseSalary(bs);
        d.set_performanceBonus(pb);

        doctors->push_back(d);
    }
    patFile.close();
    docFile.close();
    delete patients;
    delete doctors;
}

// Hospital::~Hospital() {
//     delete patients;
//     delete doctors;
// }

// Member functions

void Hospital::Find_Oldest_Patient(){
    if (patients->empty()) {
        cout << "No patients available." << endl;
        return;
    }

    int oldestIndex = 0;
    for (size_t i = 1; i < patients->size(); ++i) {
        if ((*patients)[i].get_dateOfBirth() < (*patients)[oldestIndex].get_dateOfBirth()) {
            oldestIndex = i;
        }
    }

    cout << "The oldest patient is: " << endl;  
    (*patients)[oldestIndex].Print_Patient_Info();
}
//count patient whose status is "Critical"
int Hospital:: Count_Critical_Patients(){
    int coutn =0;
for ( itn i =0; i< (int) ptr->size(); ++i){ // yes i used arrows... I'm lazy
if ((*ptr)[i].Patient_Status() == "Critical"){
++count;
}
}
return count;
}

// count patients who are still at the hospital 
int Hospital::Count_In_Patients(){
    itn count = 0;
for (int i =0; i<(int)ptr->size(); ++i){
if (!(*ptr)[i].IsDicharged()){
++count;
}
}
return count;
}




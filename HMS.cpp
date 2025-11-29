#include "HMS.h"
#include <string>
#include <fstream>
#include <iostream>
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
Hospital::Hospital(const string& doctorFile, const string& patientFile){
    
    ptr = new vector<Patient>;
    dptr = new vector<Doctor>;
    // load patients
    ifstram pFile(patientsFile.c_str());
    if (!pFile) {
        cout << "Error: could not open patients file:"<< patientsFile << endl;
    
} else{
int count; 
pFile << count; // first value= number of patietns

for ( int i=0; i<coutn; ++i){
string fistName, lastName;
long int id; 
long int assigneDoc;
string dob;
string blood;
string diag;
string doa;
string dd;

// Assume no space for strings ( use undescores) 
pFile >> fistName >> LastName
    >> id >> assignedDoc
    >> dob>> blood
    >>diag
    >>doa >>dd;
Patient p;
p.set_fistName(fisrtName);
p.set_lastName(LastName);
p.set_ID(id);
p.set_dateOfBirth(dob);
p.set_diagnosis(diag);
p.set_dateOfAdmission(doa);
p.set_dischargeDate(dd);

ptr->push_back(p);}
    }
//Loar


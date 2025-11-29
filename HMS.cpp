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
    if (diagnosis.find("critical")!= string::npos){
        return "Critical";
    }
    else if(diagnosis.find("moderate") !=string::npos){
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

string Doctor::get_firstName() { return firstName; }
void Doctor::set_firstName(string fN) { firstName = fN; }

string Doctor::get_lastName() { return lastName; }
void Doctor::set_lastName(string lN) { lastName = lN; }

long int Doctor::get_ID() { return ID; }
void Doctor::set_ID(long int id) { ID = id; }

string Doctor::get_specialty() { return specialty; }
void Doctor::set_specialty(string spec) { specialty = spec; }

int Doctor::get_yearOfExperience() { return yearOfExperience; }
void Doctor::set_yearOfExperience(int yoe) { yearOfExperience = yoe; }

double Doctor::get_baseSalary() { return baseSalary; }
void Doctor::set_baseSalary(double bs) { baseSalary = bs; }

double Doctor::get_performanceBonus() { return bonusPercentage; }
void Doctor::set_performanceBonus(double pb) { bonusPercentage = pb; }

double Doctor::CalculateCompensation() {
    return baseSalary * (1 + bonusPercentage);
}

void Doctor::Print_Doctor_Info(){
    cout << "Doctor Name: " << firstName << " " << lastName << endl;
    cout << "Doctor ID: " << ID << endl;
    cout << "Specialty: " << specialty << endl;
    cout << "Years of Experience: " << yearOfExperience << endl;
    cout << "Base Salary: " << baseSalary << endl;
    cout << "Performance Bonus: " << bonusPercentage << endl;
    cout << "Total Salary: " << CalculateCompensation() << endl;
}



// DEFINING CONSTRUCTOR
// FOR HOSPITAL CLASS

// Defining constructor that reads files
Hospital::Hospital(string patientFileName, string doctorFileName){
    
    patients = new vector<Patient>();
    doctors = new vector<Doctor>();

    ifstream patFile(patientFileName);
    

    if (!patFile){
        cout << "Error opening patient file!" << endl;
    }

    int numPatients;
    patFile >> numPatients;

    for (int i = 0; i < numPatients; i++){
        
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


    //For load doctors
    ifstream docFile(doctorFileName);
    if (!docFile){
        cout << "Error opening doctor file!" << endl;
    }
    else{

    int numDoctors;
    docFile >> numDoctors;

    for (int i = 0; i < numDoctors; i++){
        
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
    
    }
}

Hospital::~Hospital() {
 delete patients;
    delete doctors; }

// Member functions
    // find oldest Patient:

void Hospital::Find_Oldest_Patient(){
    if (patients->empty()) {
        cout << "No patients available." << endl;
        return;
    }

    int oldestIndex = 0;
    for (int i = 1; i <(int) patients->size(); ++i) {
        if ((*patients)[i].get_dateOfBirth() < (*patients)[oldestIndex].get_dateOfBirth()) {
            oldestIndex = i;
        }
    }

    cout << "The oldest patient is: " << endl;  
    (*patients)[oldestIndex].Print_Patient_Info();
}
//count patient whose status is "Critical"
int Hospital:: Count_Critical_Patients(){

    int count = 0;
    for ( int i =0; i< (int) patients->size(); ++i){ // yes i used arrows... I'm lazy
        if ((*patients)[i].Patient_Status() == "Critical"){
        ++count;
        }
    }
    
    return count;
}

// count patients who are still at the hospital 
int Hospital::Count_In_Patients(){
    int count = 0;
    for (int i =0; i<(int)patients->size(); ++i){
        if (!(*patients)[i].IsDischarged()){
        ++count;
        }
    }
    return count;
}
    //Doctors By Speciality

void Hospital::Doctors_By_Specialty(string& s){

    for (size_t i = 0; i < doctors->size(); i++){
        if ((*doctors)[i].get_specialty() == s){
            cout << (*doctors)[i].get_firstName() << " " << (*doctors)[i].get_lastName() << endl;
        }
        
    }
}

    // Show Assigned Doctor(Patient ID)
void Hospital::Show_Assigned_Doctor(long int patientID) {
    // find patient first
    for (int i = 0; i < (int)patients->size(); ++i) {
        if ((*patients)[i].get_ID() == patientID) {
            long int docID = (*patients)[i].get_assignedDoctor();
            // if docID is -1, no assigned doctor
            if (docID == -1) {
                cout << "This patient has no assigned doctor." << endl;
                return;
            }
            // find doctor with that ID
            for (int j = 0; j < (int)doctors->size(); ++j) {
                if ((*doctors)[j].get_ID() == docID) {
                    cout << "Assigned doctor for patient " << patientID << " is:" << endl;
                    (*doctors)[j].Print_Doctor_Info();
                    return;
                }
            }
            cout << "No doctor with the assigned ID was found." << endl;
            return;
        }
    }
    cout << "No patient has the provided ID" << endl;
}


// SHow Assigned patient ( Doctor ID)

void Hospital::Show_Assigned_Patients(long int doctorID) {
    bool found = false;
    for (int i = 0; i < (int)patients->size(); ++i) {
        if ((*patients)[i].get_assignedDoctor() == doctorID) {
            if (!found) {
                cout << "Patients assigned to doctor ID " << doctorID << ":" << endl;
            }
            (*patients)[i].Print_Patient_Info();
            found = true;
        }
    }
    if (!found) {
        cout << "No patients assigned" << endl;
    }
}

// Show information about the patient with a given ID
void Hospital::Show_Patient_by_ID(long int id){
    for (int i =0; i < (int)patients->size(); ++i){
        if ((*patients)[i].get_ID()==id){
        (*patients)[i].Print_Patient_Info();
        return;
        }
    }
    cout <<"No patient has the provided ID"<< endl;
}
// Show information about the doctor with a given ID
void Hospital::Show_Doctor_by_ID(long int id) {
    for (int i = 0; i < (int)doctors->size(); ++i) {
        if ((*doctors)[i].get_ID() == id) {
            (*doctors)[i].Print_Doctor_Info();
            return;
        }
    }
    cout << "No doctor has the provided ID" << endl;
}

void Hospital::Append_Patient_To_File(){
    
    ofstream patientFile("patients.txt");
    if (!patientFile){
        cout << "Error opening patient file!" << endl;
    }
    
    cout << "How many patients do you want to add? " << endl;
    cout << "Number of patients: ";
    int n;
    cin >> n;

    for (size_t i = 0; i < n; i++){
        
        string fN;
        cout << "Enter the first name: ";
        cin >> fN;
        string lN;
        cout << "Enter the last name: ";
        cin >> lN;
        long int id;
        cout << "Enter the ID: ";
        cin >> id;
        long int aD;
        cout << "Enter the assigned doctor: ";
        cin >> aD;
        string dob;
        cout << "Enter the date of birth: ";
        cin >> dob;
        string bt;
        cout << "Enter the blood type: ";
        cin >> bt;
        string diag;
        cout << "Enter the diagnosis: ";
        cin >> diag;
        string doa;
        cout << "Enter the date of admission: ";
        cin >> doa;
        string dd;
        cout << "Enter the date of discharge: ";
        cin >> dd;

        Patient p;

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

        ofstream patientFile("patients.txt");
        if (!patientFile){
            cout << "Error opening patient file!" << endl;
        }

        for(size_t i = 0; i < (*patients).size(); i++){
            patientFile << p.get_firstName() << " " << p.get_lastName() << " " << p.get_ID() << " " <<
            p.get_assignedDoctor() << " " << p.get_dateOfBirth() << " " << p.get_bloodType() << " " << p.get_diagnosis() << " " <<
            p.get_dateOfAdmission() << " " << p.get_dischargeDate() << endl; 
        }
    }

    patientFile.close();
} 

void Hospital::Append_Doctor_To_File(){
    
    ofstream doctorFile("doctors.txt");
    if (!doctorFile){
        cout << "Error opening doctor file!" << endl;
    }
    
    cout << "How many doctors do you want to add? " << endl;
    cout << "Number of doctors: ";
    int n;
    cin >> n;

    for (size_t i = 0; i < n; i++){
        
        string fN;
        cout << "Enter the first name: ";
        cin >> fN;
        string lN;
        cout << "Enter the last name: ";
        cin >> lN;
        long int id;
        cout << "Enter the ID: ";
        cin >> id;
        string spec;
        cout << "Enter the specialty: ";
        cin >> spec;
        int yoe;
        cout << "Enter the years of experience ";
        cin >> yoe;
        double bs;
        cout << "Enter the base salary: ";
        cin >> bs;
        double pb;
        cout << "Enter the performance bonus: ";
        cin >> pb;

        Doctor d;

        d.set_firstName(fN);
        d.set_lastName(lN);
        d.set_ID(id);
        d.set_specialty(spec);
        d.set_yearOfExperience(yoe);
        d.set_baseSalary(bs);
        d.set_performanceBonus(pb);

        doctors->push_back(d);

        ofstream doctorFile("doctors.txt");
        if (!doctorFile){
            cout << "Error opening patient file!" << endl;
        }

        for(size_t i = 0; i < (*patients).size(); i++){
            doctorFile << d.get_firstName() << " " << d.get_lastName() << " " << d.get_ID() << " " <<
            d.get_specialty() << " " << d.get_yearOfExperience() << " " << d.get_baseSalary() << " " << d.get_performanceBonus() << endl;
        }
    }

    doctorFile.close();
}   

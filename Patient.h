#ifndef PATIENT_H
#define PATIENT_H
#include <string>
using namespace std;

class Patient {
private:
string fisrtName;
string lastName;
long patientId; //8-digit positive number
long assignedDoctorId;// 8-digit p.n.
string bloodType;// A, AB, B, O, O+, O-
string diagnosis;// can contain spaces
string dateOfAdmission;// "YYYYMMDD"
string dateOfDischarge;// "YYYYMMDD" ? question for that
string dateOfBirth; // "YYYYMMDD"

public:
//constructor
Patient();
Patient(const string &firstName, 
const string &lastName,
long patientID,
long assignedDoctorId,
const string &dateOfBirth,
const string &bloodType,
const string &diagnosis,
const string &dateOfAdmission, 
const string &dateOfDischarge);

//setters
void SetFirstName(const string &value);
void SetLastName( const string &value);
void SetPatientId(long value);
void SetAssignedDoctorId(long value);
void SetDateOfBirth(const string &value);
void setBloodType( const string &value);
void SetDiagnosis( const string &value);
void SetDateOfAdmission(const string &value);
void SetDateOfDischarge(const string &value);

//getters
string GetFirstName() const;
string GetLastName() const;
long GetPatientId() const;
long GetAssignedDoctorId() const;
string GetDateOfBirth() const;
string GetBloodType() const;
string GetDiagnosis() const;
string GetDateOfAdmission() const;
string GetDateOfDischarge() const;

bool IsDischarged() const; // true if dicharge date !="-1"
string PatientStatus() const; // "Critical", "MOderate", " Stable"
void PrintPatientInfo(0 const; // print all fields 
};
endif 

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
const string &dateO

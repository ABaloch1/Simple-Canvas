#include "student.h"
#include <cstring>
#include <iostream>

using namespace std;

student::student() {
    //dma char array for name
    name = new char [1];
    name [0] = '\0';
    
    //default classifcication of class level
    classifcication = 'L';

    //dma char array for major
    major = new char [1];
    major [0] = '\0';

    //int for id
    studentID = 0;
}

student::student(const char *selectedname, const char level, const char *selectedmajor, const int id){
    name = new char [strlen(selectedname) + 1];     //making sure name is the appropriate length... allocation
    strcpy(name, selectedname);             //copying selected name into private name until hitting null

    classifcication = level;

    major = new char[strlen(selectedmajor) + 1];
    strcpy(major, selectedmajor);

    studentID = id;
}

//deep copy constructor
student::student(const student& selectedstudent){
    name = new char [1];
    name [0] = '\0';
    setName(selectedstudent.getName());
    
    setClassification(selectedstudent.getClassification());

    major = new char [1];
    major [0] = '\0';
    setMajor(selectedstudent.getMajor());

    setid(selectedstudent.getid());
}

//deep copy assignment opperator for a student
void student::operator=(const student& selectedstudent) {
    setName(selectedstudent.getName());
    setClassification(selectedstudent.getClassification());
    setMajor(selectedstudent.getMajor());
    setid(selectedstudent.getid());
}


//getter functions
const char* student:: getName() const {
    return name;
}

const char student:: getClassification() const{
    return classifcication;
}

const char* student:: getMajor() const {
    return major;
}

const int student:: getid() const{
    return studentID;
}

//setter functions

void student:: setName(const char *selectedname){
    delete [] name;
    name = new char[strlen(selectedname) + 1];
    strcpy(name, selectedname);
}

void student:: setClassification(const char selectedclass){
    classifcication = selectedclass;
}

void student:: setMajor(const char *selectedmajor){
    delete [] major;
    major = new char[strlen(selectedmajor) + 1];
    strcpy(major, selectedmajor);
}

void student:: setid(const int id){
    studentID = id;
}


//destructor
student::~student(){
    delete [] name;
    delete [] major;
}



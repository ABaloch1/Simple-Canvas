#include "course.h"
#include <cstring>
#include <iostream>

using namespace std;

course::course(){
    //empty constructor of courses

    //dma char array for coursename
    courseName = new char[1];
    courseName [0] = '\0';
    //copy of course code
    strcpy(courseCode, " ");
    //copy of location
    strcpy(location, " ");
    //declaring max and current size
    maxSize = 10;
    currentSize = 0;
    //making new array of student in a roster
    rosterlist = new student[maxSize]; 
}

//deep copy constructor
course::course(const course& selectedcourse){
    courseName = new char[1];
    courseName [0] = '\0';
    setCName(selectedcourse.getCName());
    
    setCCode(selectedcourse.getCCode());

    setLocation(selectedcourse.getLocation());

    maxSize = selectedcourse.maxSize;
    currentSize = selectedcourse.currentSize;

    rosterlist = new student[maxSize];
    for(int i = 0; i < currentSize; i++){
        rosterlist[i] = selectedcourse.rosterlist[i];
    }
}

//deep copy assignment
void course:: operator=(const course& selectedcourse){
    delete [] rosterlist;

    currentSize = selectedcourse.currentSize;
    maxSize = selectedcourse.maxSize;
    setCName(selectedcourse.getCName());
    setCCode(selectedcourse.getCCode());
    setLocation(selectedcourse.getLocation());
    rosterlist = new student[maxSize];
    for(int i = 0; i < currentSize; i++){
        rosterlist[i] = selectedcourse.rosterlist[i];
    }
}


//fix grow and add


void course:: growStudentSize(){
    int newSize = maxSize + 10;
    student* newstudent = new student[newSize];

    for(int i = 0; i < currentSize; i++){
        newstudent[i] = rosterlist[i];
    }
    delete [] rosterlist;
    maxSize = newSize;
    rosterlist = newstudent;
}

void course:: addStudent(){
    if(currentSize == maxSize){
        growStudentSize();
    }
    rosterlist[currentSize++].loadStudent();
}


void student::loadStudent(){
    char* word = new char[31];
    cout<<"Enter student name, followed by ENTER"<<endl;
    cin.getline(word, 30);
    setName(word);

    char level;
    cout<<"Enter students classfication. F for Freshman, S for Sophomore, J for Junior, A for Senior "<<endl;
    cin>>level;
    cin.ignore();
    setClassification(level);

    char* m = new char[31];
    cout<<"Enter student major, followed by ENTER"<<endl;
    cin.getline(m, 30);
    setMajor(m);

    int num;
    cout<<"Enter student id number follow by ENTER"<<endl;
    cin>> num;
    cin.ignore();
    setid(num);
}

int course::FindID(int aID)const{
    for(int i = 0; i< currentSize; i++)
    if (rosterlist[i].getid() == aID){
        return i;
    }
    return -1;
}

void course::findStudentID() const{
    int aID;
    cout<<"Enter desired ID you wish to find followed by ENTER"<<endl;
    cin>>aID;

    int thisID = FindID(aID);

    if (thisID == -1){
        cout<<aID << "Not found"<<endl;
    }
    else{
        cout<<"ID found, great success! "<<endl;
        cout<<rosterlist[thisID].getid()<<endl;
    }
}
void course::findStudentName() const{
    char* word = new char[31];
    cout<<"Enter student name, followed by ENTER"<<endl;
    cin.getline(word, 30);

    int entry = findName(word);

    if (entry == -1){
        cout<< word<< " not found sorry"<<endl;
    }
    else{
        cout<<"Name found, great success!"<<endl;
        cout<<rosterlist[entry].getName()<<endl;
    }
}


int course::findName(const char* findname) const{
    for(int i = 0; i < currentSize; i++){
        if(strcmp(rosterlist[i].getName(), findname) == 0)
        return i;
    }
    return -1;
}

void course::findStudent() const{

    int choice;
    cout<<"Would you like to find a student by 1) Name or 2) ID?"<<endl;
    cin>> choice;
    cin.ignore();

    if(choice == 1){
        findStudentName();
    }
    else if (choice == 2){
        findStudentID();
    }

}

//getters

const char* course:: getCName() const{
    return courseName;
}
const char* course:: getCCode() const{
    return courseCode;
}
const char* course:: getLocation() const{
    return location;
}
const int course:: getMax() const{
    return maxSize;
}
const int course:: getCurrent() const{
    return currentSize;
}
const student* course:: getRosterlist() const{
    return rosterlist;
}
const int course::getStuSize() const{
    return currentSize;
}


//setters
void course:: setCName(const char *cname){
    delete [] courseName;
    courseName = new char[strlen(cname) + 1];
    strcpy(courseName, cname);
}

void course:: setCCode(const char* ccode){
    
    strcpy(courseCode, ccode);
}

void course:: setLocation(const char* clocation){
    
    strcpy(location, clocation);
}

void course:: setMax(const int max){
    maxSize = max;
}

void course:: setCurrent (const int current){
    currentSize = current;
}

void course:: setRoster(const student *newRoster){
    delete [] rosterlist;

    rosterlist = new student[currentSize];

    for (int i = 0 ; i < currentSize; i++){
        rosterlist[i] = newRoster[i];
    }
}

void course:: updateStudent(){

    char* word = new char[31];
    cout<<"Please enter the name of the student you wish to edit"<<endl;
    cin.getline(word, 30);

    int entry = findName(word);

    if (entry == -1){
        cout<< word<< " not found sorry"<<endl;
    }
    else{
        cout<<"Name found, great success!"<<endl;
        cout<<"Name: "<<rosterlist[entry].getName()<<endl;
        cout<<"Classification: "<<rosterlist[entry].getClassification()<<endl;
        cout<<"Major: "<<rosterlist[entry].getMajor()<<endl;
        cout<<"ID: "<<rosterlist[entry].getid()<<endl;

        cout<<"You may now replace student with desired info"<<endl;
        rosterlist[entry].loadStudent();
    }
}



void course:: removeStudent() {

    char* word = new char[31];
    cout<<"Please enter the name of the student you wish to exterminate"<<endl;
    cin.getline(word, 30);

    int entry = findName(word);

        if (entry == -1){
        cout<< word<< " not found sorry"<<endl;
    }
    else{
        cout<<"Name found, great success!"<<endl;
        for (int i = entry +1; i < currentSize; i++){
            rosterlist[i-1] = rosterlist[i];
        }
        currentSize--;
        cout<<"Student has been deleted :)"<<endl;
    }

}



course::~course(){
    delete [] courseName;
    delete [] rosterlist;
}

ostream& operator<<(ostream& outy, course& students){
    outy<<"Course name: "<< students.getCName()<<endl;
    outy<<"Course code: "<<students.getCCode()<<endl;
    outy<<"Course location: "<<students.getLocation()<<endl;
    
    if (students.currentSize == 0){
        outy<< "No students to display"<<endl;
    }
    for (int i = 0; i < students.currentSize; i++){
        outy<<"Name: "<<students.rosterlist[i].getName()<<"\t Classification: "<<students.rosterlist[i].getClassification()<< "\t Major: "<<
        students.rosterlist[i].getMajor()<<"\t Student ID: "<< students.rosterlist[i].getid()<<endl;
    }
    return outy;
}


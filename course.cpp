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

void course:: addStudent(const student& person){
    if(currentSize == maxSize){
        growStudentSize();
    }
    
    rosterlist[currentSize++] = person;

}
/*
int course::FindID(int* aID)const{
    for(int i = 0; i< currentSize; i++)
    if (strcmp(rosterlist[i].getid(), aID) == 0){
        return i;
    }
    return -1;
}

void course::findStudentID() const{
    char aID[];
    cout<<"Enter desired ID you wish to find followed by ENTER"<<endl;
    cin.getline(aID, 7);

    int thisID = FindID(aID);

    if (thisID == -1){
        cout<<aID << "Not found"<<endl;
    }
    else{
        cout<<"Found ID: ";
        rosterlist[thisID].getid();
    }
}
*/
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



course::~course(){
    delete [] courseName;
    delete [] rosterlist;
}
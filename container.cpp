#include "container.h"
#include <cstring>
#include <iostream>


container::container(){
    listcurrentSize = 0;
    listmaxSize = 2;
    list = new course[listmaxSize];
}
container::~container(){
    delete [] list;
}

void container::operator=(const container& c){
    delete [] list;

    listcurrentSize = c.listcurrentSize;
    listmaxSize = c.listmaxSize;
    list = new course[listmaxSize];
    for(int i = 0; i < listcurrentSize; i++){
        list[i] = c.list[i];
    }
}

void container:: growList() {
    int listnewSize = listmaxSize + 1;

    course* newCourse = new course[listnewSize];

    for (int i = 0; i < listcurrentSize; i++){
        newCourse[i] = list[i];    
    }
    delete [] list;
    listmaxSize = listnewSize;
    list = newCourse;
}

void container:: addCourse() {

    if(listcurrentSize == listmaxSize){
        growList();
    }
    list[listcurrentSize++].loadCoarse();

}

void container::addStu2Course(){
    char* word = new char[200];
    cout<<"What course do you want to add a student to?"<<endl;
    cin.getline(word, 200);
    word[199] = '\0';

    int entry = findCName(word);

    if (entry == -1){
        cout<< word<< " not found sorry"<<endl;
    }
    else{
        cout<<"Name found, great success!"<<endl;
        cout<<list[entry].getCName()<<endl;
        list[entry].addStudent();
    }
}

void container::findstudentinCourse(){
    char* word = new char[200];
    cout<<"In which course would you like to search for a student? "<<endl;
    cin.getline(word, 200);
    word[199] = '\0';

    int entry = findCName(word);

    if (entry == -1){
        cout<< word<< " not found sorry"<<endl;
    }
    else{
        cout<<"Name found, great success!"<<endl;
        cout<<list[entry].getCName()<<endl;
        list[entry].findStudent();
    }
}

void course::loadCoarse(){
    char* word = new char[200];
    cout<<"Enter course name, followed by ENTER"<<endl;
    cin.getline(word, 199);
    setCName(word);

    //test.setCName(word);
    //delete [] word;
    //cout<<"Course Name is: "<< test.getCName()<<endl; 

    cout<<"Enter a 7 character course code, followed by ENTER"<<endl;
    char code[8];
    cin.getline(code, 8);
    setCCode(code);
    //test.setCCode(code);
    //cout<<"Course code: "<< test.getCCode()<<endl;

    cout<<"Enter a 10 character location of course, followed by ENTER"<<endl;
    char loc[11];
    cin.getline(loc, 11);
    setLocation(loc);
    //test.setLocation(loc);
    //cout<<"Location: "<< test.getLocation()<<endl;
}

int container::findCName(const char* findname) const{
    for(int i = 0; i < listcurrentSize; i++){
        if(strcmp(list[i].getCName(), findname) == 0)
        return i;
    }
    return -1;
}

void container::findCourseName() const{
    char* word = new char[200];
    cout<<"Enter course name, followed by ENTER"<<endl;
    cin.ignore();
    cin.getline(word, 200);
    word[199] = '\0';

    int entry = findCName(word);

    if (entry == -1){
        cout<< word<< " not found sorry"<<endl;
    }
    else{
        cout<<"Name found, great success!"<<endl;
        cout<<list[entry].getCName()<<endl;
    }
}

int container::findCLocation(const char* findlocation) const{
    for (int i = 0; i < listcurrentSize; i++){
        if(strcmp(list[i].getLocation(), findlocation) == 0)
            return i;
    }
    return -1;
}

void container:: findCourseLocation() const{
    char loc[11];
    cout<<"Enter course location, followed by ENTER"<<endl;
    cin.ignore();
    cin.getline(loc, 11);

    int entry = findCLocation(loc);

    if (entry == -1){
        cout<< loc << " not found sorry"<<endl;
    }
    else{
        cout<<"Location found, great success!"<<endl;
        cout<<list[entry].getLocation()<<endl;
    }
}


int container::findCCode(const char* findcode) const{
    for (int i = 0 ; i < listcurrentSize; i++){
        if(strcmp(list[i].getCCode(), findcode) == 0)
        return i;
    }
    return -1;
}

void container::findCourseCode() const{
    char code[8];
    cout<<"Enter course code, followed by ENTER"<<endl;
    cin.ignore();
    cin.getline(code, 8);
    

    int entry = findCCode(code);

    if (entry == -1){
        cout<< code << " not found sorry"<<endl;
    }
    else{
        cout<<"Code found, great success!"<<endl;
        cout<<list[entry].getCCode()<<endl;
    }
}


void container::findCourse() const{
    cout<<"Find a course by 1)name, 2)course code, or 3)location"<<endl;
    int choice;
    cin>>choice;
    if (choice == 1){
        findCourseName();
    }
    else if (choice == 2){
        findCourseCode();
    }
    else if (choice == 3){
        findCourseLocation();
    }
}

void container:: displayList(){
    if (listcurrentSize == 0){
        cout<<"Nothing to display"<<endl;
    }
    for (int i = 0; i < listcurrentSize; i++){
        cout<< "Course list"<< i + 1 <<endl;
        cout<<  list[i] <<endl;
    }
}

void container:: updateCourse(){
    char* word = new char[200];
    cout<<"Enter course name you wish to edit, followed by ENTER"<<endl;
    cin.getline(word, 200);

    int entry = findCName(word);

    if (entry == -1){
        cout<< word<< " not found sorry"<<endl;
    }
    else{
        cout<<"Name found, great success!"<<endl;
        cout<<list[entry].getCName()<<endl;

        cout<<"Replace with new course data"<<endl;
        list[entry].loadCoarse();
    }
}

void container:: removeCourse(){
    cout<<"Enter a 7 character course code for the course you wish to remove, followed by ENTER"<<endl;
    char code[8];
    cin.getline(code, 8);

    int entry = findCCode(code);

    if (entry == -1){
        cout<< code << "not found"<<endl;
    }
    else{
        for (int i = entry +1; i < listcurrentSize; i++){
            list[i - 1] = list[i];
        }
        listcurrentSize--;
        cout<<"Course removed"<<endl;
    }
}

void container:: updateStudentinCourse(){
    char* word = new char[200];
    cout<<"Enter course name in which you wish to update a student, followed by ENTER"<<endl;
    cin.getline(word, 200);
    word[199] = '\0';

    int entry = findCName(word);

    if (entry == -1){
        cout<< word<< " not found sorry"<<endl;
    }
    else{
        cout<<"Name found, great success!"<<endl;
        cout<<list[entry].getCName()<<endl;

        list[entry].updateStudent();
    }
}

void container:: removeStudentinCourse(){
        char* word = new char[200];
    cout<<"Enter course name in which you wish to update a student, followed by ENTER"<<endl;
    cin.getline(word, 200);
    word[199] = '\0';

    int entry = findCName(word);

    if (entry == -1){
        cout<< word<< " not found sorry"<<endl;
    }
    else{
        cout<<"Name found, great success!"<<endl;
        cout<<list[entry].getCName()<<endl;
        list[entry].removeStudent();
    }
}

void container:: updateCourseinList(){
    cout<<"Would you like to: 1) Update a course? 2) Update a student in the course 3) Remove a student from a course?"<<endl;
    int choice;
    cin>>choice;
    cin.ignore();

    //update course
    if(choice == 1){
        updateCourse();
    }
    //update student in course
    else if(choice == 2){
        updateStudentinCourse();
    }
    else if(choice == 3){
        removeStudentinCourse();
    }
}
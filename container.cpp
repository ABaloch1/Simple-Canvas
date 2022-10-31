#include "container.h"

container::container(){
    list = new course[listmaxSize];

    listcurrentSize = 0;
    listmaxSize = 2;

}

void container:: growList() {
    listmaxSize = listcurrentSize + 1;

    course* newCourse = new course[listmaxSize];

    for (int i = 0; i < listcurrentSize; i++){
        newCourse[i] = list[i];    
    }
    delete [] list;
    list = newCourse;
}

void container:: addCourse() {
    course c;
    if(listcurrentSize == listmaxSize){
        growList();
    }
    
    list[listcurrentSize++] = c;
    createCoarse();
}

void container:: createCoarse(){
    course test;
    char *word = new char[31];
    cout<<"Enter course name, followed by ENTER"<<endl;
    cin.getline(word, 30);

    test.setCName(word);
    delete [] word;
    cout<<"Course Name is: "<< test.getCName()<<endl; 

    cout<<"Enter a 7 character course code, followed by ENTER"<<endl;
    char code[8];
    cin.getline(code, 7);
    test.setCCode(code);
    cout<<"Course code: "<< test.getCCode()<<endl;

    cout<<"Enter a 10 character location of course, followed by ENTER"<<endl;
    char loc[10];
    cin.getline(loc, 9);
    test.setLocation(loc);
    cout<<"Location: "<< test.getLocation()<<endl;
}

const course* container:: getList() const {
    return list;
}

ostream& operator<<(ostream& outy, container& instance){
    if (instance.listcurrentSize == 0){
        outy<<"No information to display"<<endl;
    }
    else{
        for (int i = 0; i < instance.listcurrentSize; i++){
            //outputting in the order of course, course, coursecode, location
            //under course output students as name, classfication, major, studentID
            outy<<"COURSE:  "<<  instance.list[i].getCName()<< "\t"<< instance.list[i].getCCode()<< "\t"<< instance.list[i].getLocation()<<endl;
            //outy<<"STUDENT: "<< instance.list.rosterlist[i].getName()<<endl; "\t"<<  instance.list[i].rosterlist[i].getClassification()<< "\t"<< instance.list[i].rosterlist[i].getMajor()<< "\t"<< instance.list.rosterlist[i].getid()<<endl;
        }
    }
} 
#include "container.h"
#include <iostream>
#include <cstring>
using namespace std;

void showMenu();

int main(){
    cout<<"Welcome to my program"<<endl;
    showMenu();

    container list;
    course* container = new course[2];
    int current = 0;
    int max = 2;

    student* testRoster = new student[max];

    

    cout<<"add course test"<<endl;
    list.addCourse();


    cout<<list<<endl;
    


/*
    int option;
    cin>>option;
    do{
        switch(option)
        {
            if (option == 1)
            break;
                //adding course to list

            else if (option == 2)
            break;
                //add students
            
            else if (option == 3)
            break;
                //update course

            else if (option == 4)
                break;
                //cout operatiom

            else if (option == 5)
                //finding student by name/id
                break;

            else if (option == 6)
                //find course by name, code, location
                break;

            else if (option == 7)
                //remove course by code
                break;
        }
    }while(option != 0);

*/

}

void showMenu(){
    cout<<" \t\t Roster menu options "<<endl;
    cout<<" \t\t ******************* "<<endl;
    cout<<"\t 1. Add a course to the list"<<endl;
    cout<<"\t 2. Add students to a course"<<endl;
    cout<<" \t 3. Update a course to change any of the data above including edits "<< 
    "to students or adding/removing students from the roster"<<endl;
    cout<<"\t 4. List courses including students in the course"<<endl;
    cout<<"\t 5. Find a student by name or studentid"<<endl;
    cout<<"\t 6. Find a course by name, course code, or location"<<endl;
    cout<<"\t 7. Remove a course from the list by course code"<<endl;
    cout<<"\t 0. Exit"<<endl;
}
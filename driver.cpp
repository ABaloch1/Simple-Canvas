#include "container.h"
#include <iostream>
#include <cstring>
using namespace std;

void showMenu();

int main(){
    cout<<"Welcome to my program"<<endl;

    int option = 0;
    container list;

    do{
        showMenu();
        cout<<"Please enter a valid value"<<endl;

        cin>>option;
        cin.ignore();

        switch(option){
            case 1:
                list.addCourse();
                break;
            
            case 2:
                list.addStu2Course();
                break;
            
            case 3:
                list.updateCourseinList();
                break;

            case 4:
                list.displayList();
                break;
            
            case 5:
                list.findstudentinCourse();
                break;

            case 6:
                list.findCourse();
                break;

            case 7:
                list.removeCourse();
                break;
                
        }
    } while(option != 9);

return 0;
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
    cout<<"\t 9. Exit"<<endl;
}
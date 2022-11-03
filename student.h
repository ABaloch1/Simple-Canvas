#include <iostream>
using namespace std;

class student{

    
    public:
    //constructors
    student();      //default contructor
    student(const char *selectedname, const char level, const char *selectedmajor, const int id); //copying constructor until appropratie length
    student(const student& selectedstudent); //deep copy constructor


    //setter
    void setName(const char *selectedname);
    void setClassification(const char selectedclass);
    void setMajor(const char *selectedmajor);
    void setid(const int id);


    //getter
    const char* getName() const;      //returns name
    const char getClassification() const;
    const char* getMajor() const;     //returns major
    const int getid() const;


    //functions
    ~student();     //default destructor
    void operator=(const student&);     //deep copy assignment
    void loadStudent();
    

    
    private:
    char* name;     //dma char array for name ex: Jane Doe
    char classifcication;       //char for class level ex: J for junior
    char* major;    //dma char array for major ex: Computer Science
    int studentID;      //ints for student ex: 1234421
};
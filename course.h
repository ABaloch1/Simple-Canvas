#include "student.h"

class course{
    
    public:
    //default constructor
    course();
    //destructor
    ~course();
    //deep copy constructor
    course(const course& selectedcourse);


    //getters
    const char* getCName() const;
    const char* getCCode() const;
    const char* getLocation() const;
    const int getMax() const;
    const int getCurrent() const;
    const student* getRosterlist() const;


    //setters
    void setCName(const char *cname);
    void setCCode(const char *ccode);
    void setLocation(const char *clocation);
    void setMax(const int max);
    void setCurrent (const int current);
    void setRoster(const student *newRoster);
    


    //functions
    void operator=(const course& selectedcourse);

    
   
    void findStudentID() const;
    void createStudent();
    void addStudent(const student& person);
    void growStudentSize();

    int FindID(int* aID) const;




    private:
    char* courseName;
    char courseCode[7];
    char location[10];
    int maxSize;
    int currentSize;
    student* rosterlist;


};
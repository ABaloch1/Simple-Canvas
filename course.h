#include "student.h"

class course{
    friend ostream& operator<<(ostream&, course&);

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
    const int getStuSize() const;


    //setters
    void setCName(const char *cname);
    void setCCode(const char *ccode);
    void setLocation(const char *clocation);
    void setMax(const int max);
    void setCurrent (const int current);
    void setRoster(const student *newRoster);
    


    //functions
    void operator=(const course& selectedcourse);
    
    void createStudent();
    void addStudent();
    void growStudentSize();
    //finding id of student
    void findStudentID() const;
    int FindID(int aID) const;
    //finding name of student
    void findStudentName() const;
    int findName(const char* findname) const;

    //function to find student in a list of courses
    void findStudent() const;

    //creating a course
    void loadCoarse();

    //removing students from a course
    void updateStudent();
    //remove
    void removeStudent();

    private:
    char* courseName;
    char courseCode[8];
    char location[11];
    int maxSize;
    int currentSize;
    student* rosterlist;


};
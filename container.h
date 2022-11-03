#include "course.h"

class container{
    public:
    container();
    ~container();

    void operator=(const container& c);

    void addCourse();

    const course* getList() const;

    const course* create() const;
    void createCoarse(const course& test);
    void growList();
    void displayList();


    //find course functions
    int findCName(const char* findname) const;
    void findCourseName() const;

    int findCCode(const char* findcode) const;
    void findCourseCode() const;

    int findCLocation(const char* findlocation) const;
    void findCourseLocation() const;

    void findCourse() const;
    //finding student inside course
    void findstudentinCourse();
    //add student to course
    void addStu2Course();

    

    //update course including student
    void updateCourse();
    //remove course by course code
    void removeCourse();

    //updating a student inside of a course
    void updateStudentinCourse();
    //updating a course inside list
    void updateCourseinList();
    //removing student in course
    void removeStudentinCourse();


    private:
    course* list;
    int listcurrentSize;
    int listmaxSize;

};
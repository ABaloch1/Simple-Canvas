#include "course.h"

class container{
    friend ostream& operator<<(ostream&, container&);
    public:
    container();

    void addCourse();

    const course* getList() const;
    void createCoarse();
    void growList();


    private:
    course* list;
    int listcurrentSize;
    int listmaxSize;

};
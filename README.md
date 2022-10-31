# A4For this assignment, you need to build a class that contains basic information about students and courses that have those students on the roster. You also need to build a menu that supports basic CRUD functionality for those courses. The requirements are as follows:

The student class should contain the following data about a student:

Name (dynamic char array)
Classification (char)
Major (dynamic char array)
StudentId (can be an int or a dynamic char array)
The course class should contain the following data about a course:

Course Name (dynamic char array)
Course Code (char array of size 7)
Location (char array of size 10)
Roster (dynamic student array)
The menu program should act as a driver program that manages a dynamically allocated array of courses and allows the user to:

Add a course to the list
Add students to a course
Update a course to change any of the data above including edits to students or adding/removing students from the roster
List courses including students in the course using a << overload to format the data in both the course and the students in the roster
Find a student by name or studentid
Find a course by name, course code, or location
Remove a course from the list by course code
The original list of courses should be of size 2 and increase in size by 1 during each add operation. The list of students in a course should initially be of size 2 and should grow by 10 during each add operation. Remove operations do not have to resize the array.

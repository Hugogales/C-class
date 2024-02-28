// SPA 3, Spring 2024, Hugo Garrido-Lestache

#ifndef SPA3_POOL_H
#define SPA3_POOL_H
#include <string>
using namespace std;

/**
 * student class that holds the name of the student
 * and the day the student was born
 */
class Student {
public:
    Student(string name);
    Student(string name, int num);

    /**
     * print out the name and what day they were born of the student
     * removing underscores and replacing them with spaces
     * if student was born on day 0, it will not print out the day just name
     * @return name + day the were born
     */
    string printDescription() const;

    /**
     * checks if the student matches another student
     * matchs are if the students have the same birth day
     * or if the students have a similar character in their name
     * @param other student
     * @return true if the students match
     */
    bool matches(Student *other) const;
private:
    string name;
    int day; //0 if not known

};

/**
 * pool class that holds students
 * can add students and print out matches
 */
class Pool {
public:
    /**
     * constructor for the pool
     * initializes the number of students to 0
     * and the students to null
     */
    Pool();
    /**
     * constructor for the pool
     * initializes the number of students to 1
     * and the students to the name and day
     * @param x name of the student
     * @param y day the student was born
     */
    Pool(string x, int y = 0);
    /**
     * adds a student to the pool
     * @param x name of the student
     */
    void add(string x);
    /**
     * adds a student to the pool
     * @param x name of the student
     * @param y day the student was born
     */
    void add(string x, int y);
    /**
     * reads in the students from the user upto 20 students
     * will stop reading when it encounters "END"
     * ignores the input between 20th student and "END"
     * using cin
     */
    void readStudents();
    /**
     * prints out the matches between the pool and another student
     * @param other student
     */
    void printMatches(Student *other) const;
    /**
     * prints out the matches between the pool and another pool
     * @param other pool
     */
    void printMatches(Pool *other) const;
    /**
     * checks if the pool is empty
     * @return true if the pool is empty
     */
    bool empty() const;
private:
    static const int MAX_STUDENTS = 20;
    Student *students[MAX_STUDENTS];//max 20 students
    int num_students;
};

#endif //SPA3_POOL_H
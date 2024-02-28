// SPA 3, Spring 2024, Hugo Garrido-Lestache

#include "pool.h"
#include <string>
#include <iostream>

using namespace std;

// Student class implementation
Student::Student(string name) {
    this->name = name;
    this->day = 0;
}
Student::Student(string name, int num) {
    this->name = name;
    this->day = num;
}
string Student::printDescription() const {
    string out = name;
    for(int i = 0; i < static_cast<int>(out.length()); i++){
        if(out[i] == '_'){
            out[i] = ' ';
        }
    }
    if(day == 0){
        return out;
    } else {
        return out + " born on day " + to_string(day);
    }
}
bool Student::matches(Student *other) const {
    bool out =((this-> day >0 && other-> day)
    && this->day == other->day);

    if(out){
        return true;
    }
    else{
        for(int i = 0; i < static_cast<int>(this->name.length()); i++){
            for(int j = 0; j < static_cast<int>(other->name.length()); j++) {
                if (tolower(this->name[i]) == tolower(other->name[j]) && this->name[i] != '_'){
                    return true;
                }
            }
        }
    }
    return false;
}


// Pool class implementation
Pool::Pool() {
    num_students = 0;
}
Pool::Pool(string x, int y) {
    students[0] = new Student(x, y);
    num_students = 1;
}
void Pool::add(string x) {
    students[num_students] = new Student(x);
    num_students++;
}
void Pool::add(string x, int y) {
    students[num_students] = new Student(x, y);
    num_students++;
}
void Pool::readStudents(){
    string name;
    int day;

    cin >> name;
    cin >> day;
    while(cin && name != "END" ){
        if(num_students < MAX_STUDENTS){
            add(name, day);
        }
        cin >> name;
        cin >> day;
    }

}
void Pool::printMatches(Student *other) const {
    for(int i = 0; i < num_students; i++){
        if(students[i] -> matches(other)){
            cout << "A perfect match for ";
            cout << other->printDescription();
            cout << ": " << students[i]->printDescription() << endl;
        }
    }
}
void Pool::printMatches(Pool *other) const {
    for(int i = 0; i < num_students; i++){
        other->printMatches(students[i]);
    }
}
bool Pool::empty() const {
    return num_students == 0;
}
// main.cpp: finds perfect matches in two pools of students
// Robert W. Hasker, 2024

#include "pool.h"
#include <iostream>
#include <string>

// just to see what happens (not reasonable for real code):
#include "pool.h"

using namespace std;

void smoke_test();

int main() {
    cout << "Enter the first names and birth days of the students in the first pool:"
         << endl;
    string first_name;
    int day;
    cin >> first_name >> day;
    if ( cin && first_name == "TEST" ) {
        smoke_test();
        return 0;
    }
    Pool *pool1 = nullptr;
    if ( !cin || first_name == "END" )
        pool1 = new Pool();
    else {
        pool1 = new Pool(first_name, day);
        pool1->readStudents();
    }
    cout << "Enter the first names of the students in the second pool:" << endl;
    Pool *pool2 = new Pool;
    pool2->readStudents();
    cout << endl;

    if ( pool1->empty() && pool2->empty() )
        cout << "Both pools are empty." << endl;
    else if ( pool1->empty() )
        cout << "First pool is empty." << endl;
    else if ( pool2->empty() )
        cout << "Second pool is empty." << endl;

    pool1->printMatches(pool2);
    return 0;
}

// a very simple test that ensures we can create a pool, add a name,
//   and that basic name matching is implemented
// (Note: a smoke test is a simple test that is intended to make sure
// that code simply runs.)
void smoke_test() {
    Pool *test_a = new Pool;
    Pool *test_b = new Pool("paul");
    test_a->add("sue");
    test_a->add("zoe");
    // some will print nothing
    cout << "Matches in group a for ROE:" << endl;
    test_a->printMatches(new Student("ROE"));
    cout << "Matches in group a for sue:" << endl;
    test_a->printMatches(new Student("sue"));
    cout << "Matches in group b for Xao:" << endl;
    test_b->printMatches(new Student("Xao"));
    cout << "Matches between a and b:" << endl;
    test_b->printMatches(test_a);
    cout << "Matches between a and itself:" << endl;
    test_a->printMatches(test_a);
    cout << "Smoke tests completed." << endl;
}

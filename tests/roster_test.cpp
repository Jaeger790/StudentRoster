#include "roster.h"
#include <cassert>
#include <stdexcept>

int main() {
    Roster roster;
    for (int i = 0; i < 5; ++i) {
        roster.add(std::to_string(i), "Test", "Student", "test@example.com", 20, 1, 2, 3, SOFTWARE);
    }
    bool full = false;
    try { roster.add("extra", "Test", "Student", "test@example.com", 20, 1, 2, 3, SOFTWARE); }
    catch (const std::length_error&) { full = true; }
    assert(full);
    roster.removeStudentByID("2");
    assert(roster.classRosterArray[2]->getStudentID() == "4");
    assert(roster.classRosterArray[4] == nullptr);
    roster.removeStudentByID("2");
    roster.removeStudentByID("3");
    assert(roster.classRosterArray[3] == nullptr);
    roster.add("new", "Test", "Student", "test@example.com", 20, 1, 2, 3, SOFTWARE);
    assert(roster.classRosterArray[3]->getStudentID() == "new");
}

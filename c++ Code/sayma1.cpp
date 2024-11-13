#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

// Define the total number of students, subjects and tests
const int TOTAL_NUM_STUDENTS = 20;
const int TOTAL_NUM_SUBJECTS = 6;
const int TOTAL_NUM_TESTS = 5;

int main() {
    int marks[TOTAL_NUM_STUDENTS][TOTAL_NUM_SUBJECTS][TOTAL_NUM_TESTS];

    // Input marks
    for (int student = 0; student < TOTAL_NUM_STUDENTS; ++student) {
        cout << "Enter marks for Student " << student + 1 << ":\n";
        for (int subject = 0; subject < TOTAL_NUM_SUBJECTS; ++subject) {
            cout << "  Subject " << subject + 1 << ":\n";
            for (int test = 0; test < TOTAL_NUM_TESTS; ++test) {
                cout << "    Test " << test + 1 << ": ";
                cin >> marks[student][subject][test];
            }
        }
    }

    // Calculate and output highest, lowest, and average marks for the class
    int class_total = 0, num_marks = 0, class_highest = 0, class_lowest = 100;

    for (int student = 0; student < TOTAL_NUM_STUDENTS; ++student) {
        for (int subject = 0; subject < TOTAL_NUM_SUBJECTS; ++subject) {
            for (int test = 0; test < TOTAL_NUM_TESTS; ++test) {
                int mark = marks[student][subject][test];
                class_total += mark;
                num_marks++;
                if (mark > class_highest){
                    class_highest = mark;
                }
                if (mark < class_lowest){
                    class_lowest = mark;
                }
            }
        }
    }
    // cout << marks << endl;
    // cout << "======================================================" << endl;
    // cout << "Total marks: " << class_total << endl;
    // cout << "Num of marks: " << num_marks << endl;

    double classAverage = static_cast<double>(class_total) / num_marks;

    cout << "\nClass Results:\n";
    cout << "Highest Mark: " << class_highest << "\n";
    cout << "Lowest Mark: " << class_lowest << "\n";
    cout << "Average Mark: " << fixed << setprecision(2) << classAverage << "\n\n";

    // Calculate and output highest, lowest, and average marks for each student
    for (int student = 0; student < TOTAL_NUM_STUDENTS; ++student) {
        int studentTotal = 0, studentHighest = 0, studentLowest = 100;

        for (int subject = 0; subject < TOTAL_NUM_SUBJECTS; ++subject) {
            for (int test = 0; test < TOTAL_NUM_TESTS; ++test) {
                int mark = marks[student][subject][test];
                studentTotal += mark;
                if (mark > studentHighest) studentHighest = mark;
                if (mark < studentLowest) studentLowest = mark;
            }
        }
        double studentAverage = static_cast<double>(studentTotal) / (TOTAL_NUM_SUBJECTS * TOTAL_NUM_TESTS);

        cout << "Student " << student + 1 << " Results:\n";
        cout << "  Highest Mark: " << studentHighest << "\n";
        cout << "  Lowest Mark: " << studentLowest << "\n";
        cout << "  Average Mark: " << fixed << setprecision(2) << studentAverage << "\n\n";
    }

    // Calculate and output highest, lowest, and average marks for each subject
    for (int subject = 0; subject < TOTAL_NUM_SUBJECTS; ++subject) {
        int subjectTotal = 0, subjectCount = 0, subjectHighest = 0, subjectLowest = 100;

        for (int student = 0; student < TOTAL_NUM_STUDENTS; ++student) {
            for (int test = 0; test < TOTAL_NUM_TESTS; ++test) {
                int mark = marks[student][subject][test];
                subjectTotal += mark;
                subjectCount++;
                if (mark > subjectHighest) subjectHighest = mark;
                if (mark < subjectLowest) subjectLowest = mark;
            }
        }
        double subjectAverage = static_cast<double>(subjectTotal) / subjectCount;

        cout << "Subject " << subject + 1 << " Results:\n";
        cout << "  Highest Mark: " << subjectHighest << "\n";
        cout << "  Lowest Mark: " << subjectLowest << "\n";
        cout << "  Average Mark: " << fixed << setprecision(2) << subjectAverage << "\n\n";
    }

    return 0;
}

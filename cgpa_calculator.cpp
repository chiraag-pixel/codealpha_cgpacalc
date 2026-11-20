#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

// converts a letter grade to grade points (10 point scale)
// returns -1 if the grade is not valid
double getPoints(string g) {
    if (g == "O") return 10;
    if (g == "A+") return 9;
    if (g == "A") return 8;
    if (g == "B+") return 7;
    if (g == "B") return 6;
    if (g == "C") return 5;
    if (g == "P") return 4;
    if (g == "F") return 0;
    return -1;
}

int main() {
    int sems;
    double allCredits = 0, allPoints = 0;

    cout << "CGPA Calculator\n";
    cout << "Grades: O, A+, A, B+, B, C, P, F\n\n";

    cout << "Number of semesters: ";
    cin >> sems;
    while (cin.fail() || sems < 1) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Enter a valid number: ";
        cin >> sems;
    }

    for (int s = 1; s <= sems; s++) {
        int n;
        cout << "\nSemester " << s << "\n";
        cout << "Number of courses: ";
        cin >> n;
        while (cin.fail() || n < 1) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Enter a valid number: ";
            cin >> n;
        }

        vector<string> names, grades;
        vector<double> credits;
        double semCredits = 0, semPoints = 0;

        for (int i = 0; i < n; i++) {
            string name, grade;
            double credit;

            cout << "\nCourse " << i + 1 << " name: ";
            cin >> name;

            cout << "Grade: ";
            cin >> grade;
            while (getPoints(grade) < 0) {
                cout << "Invalid grade, try again: ";
                cin >> grade;
            }

            cout << "Credits: ";
            cin >> credit;
            while (cin.fail() || credit <= 0) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Enter valid credits: ";
                cin >> credit;
            }

            names.push_back(name);
            grades.push_back(grade);
            credits.push_back(credit);

            semCredits += credit;
            semPoints += getPoints(grade) * credit;
        }

        // print this semester
        cout << "\nSemester " << s << " result\n";
        cout << left << setw(15) << "Course" << setw(8) << "Grade" << "Credits\n";
        for (int i = 0; i < n; i++) {
            cout << left << setw(15) << names[i] << setw(8) << grades[i] << credits[i] << "\n";
        }
        cout << fixed << setprecision(2);
        cout << "Total credits: " << semCredits << "\n";
        cout << "GPA: " << semPoints / semCredits << "\n";

        allCredits += semCredits;
        allPoints += semPoints;
    }

    cout << "\nTotal credits: " << allCredits << "\n";
    cout << "CGPA: " << allPoints / allCredits << "\n";

    return 0;
}

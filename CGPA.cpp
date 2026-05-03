#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Course {
    string name;
    float grade;  
    int creditHours; 
};

class CGPACalculator {
private:
    vector<Course> courses;

public:
    void inputCourses() {
        int numCourses;
        cout << "====================================\n";
        cout << "Enter the number of courses: ";
        cin >> numCourses;

        for (int i = 0; i < numCourses; ++i) {
            Course temp;
            cout << "\n--- Course #" << i + 1 << " ---\n";
            cout << "Enter Course Name: ";
            cin.ignore();
            getline(cin, temp.name);

            cout << "Enter Grade Points (0-4 or 0-100): ";
            cin >> temp.grade;

            cout << "Enter Credit Hours: ";
            cin >> temp.creditHours;

            courses.push_back(temp);
        }
    }

    float calculateCGPA() {
        if (courses.empty()) return 0.0f;

        float totalGradePoints = 0;
        int totalCredits = 0;

        for (const auto& c : courses) {
            totalGradePoints += (c.grade * c.creditHours);
            totalCredits += c.creditHours;
        }

        return totalGradePoints / totalCredits;
    }

    void displayResults() {
        float finalCGPA = calculateCGPA();

        cout << "\n====================================\n";
        cout << "        ACADEMIC REPORT             \n";
        cout << "====================================\n";
        cout << left << setw(15) << "Course" << setw(10) << "Grade" << "Credits" << endl;

        for (const auto& c : courses) {
            cout << left << setw(15) << c.name
            << setw(10) << c.grade
            << c.creditHours << endl;
        }

        cout << "------------------------------------\n";
        cout << fixed << setprecision(2);
        cout << "FINAL CGPA: " << finalCGPA << endl;
        cout << "====================================\n";
    }
};

int main() {
    CGPACalculator myTracker;

    myTracker.inputCourses();
    myTracker.displayResults();

    return 0;
}

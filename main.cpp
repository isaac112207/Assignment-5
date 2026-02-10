#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// This is global variable, do not modify
#define MAX_STUDENTS 5

struct Student {
  int studentId;
  string studentName;
  float studentGrades;
};

/*!
* Function Prototypes
*/
void printMenu();
void highestGrade(Student students[], int count);
void lowestGrade(Student students[], int count);
void averageGrade(Student students[], int count);
void printStudentId(Student students[], int count);
void printStudentName(Student students[], int count);

int main() {
  Student students[MAX_STUDENTS];
  int count = 0;  // this keeps track of the students that are in the class
  int choice;     // user input

  /*!
  * Add the students here!
  */
  //----------------------------------------------------------------------------------------
  students[0] = {111, "Tommy Jay", 75.4};
  students[1] = {104, "Kobe Juarez", 96.1};
  students[2] = {109, "Lamar Jenkins", 67.9};
  students[3] = {101, "Zoey Mckensie", 89.9};
  students[4] = {106, "Ozzy Bosbourne", 90.2};
  count = 5;
  //----------------------------------------------------------------------------------------

  // Complete the menu with the associated function
  do {
    printMenu();
    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore();  // we add this to consume the leftover newline

    switch (choice) {
    case 1:
      highestGrade(students, count);
      break;
    case 2:
      lowestGrade(students, count);
      break;
    case 3:
      averageGrade(students, count);
      break;
    case 4:
      printStudentId(students, count);
      break;
    case 5:
      printStudentName(students, count);
      break;
    case 6:
      cout << "Goodbye!\n";
      break;
    default:
      cout << "Invalid choice. Please try again.\n";
    }
  } while (choice != 6);

  return 0;
}

void printMenu() {
  cout << "\n=== Student Record System ===\n";
  cout << "1. Find student with the highest grade\n";
  cout << "2. Find the student with the lowest grade\n";
  cout << "3. Find the average grade in the class\n";
  cout << "4. Print all the student's ID\n";
  cout << "5. Print all the student's names\n";
  cout << "6. Exit\n";
}

/* TODO: Implement these functions */

// Remeber, if you pass an array into a function, it is a pass by reference!
// Because arrays decay to pointers, so you are getting a pointer to the first element
// which allows you to modify the data. 

void highestGrade(Student students[], int count)
{

  if (count == 0) {
    cout << "No students in the record.\n";
    return;
  }
  float high = students[0].studentGrades;
  for (int i = 1; i < count; i++) {
    if (students[i].studentGrades > high) {
      high = students [i].studentGrades;
    }
  }
  cout << "The highest grade is: " << high << endl;
}
void lowestGrade(Student students[], int count)
{
  if (count == 0) return;
  float low = students[0].studentGrades;
  for (int i = 1; i < count; i++) {
    if (students[i].studentGrades < low) {
      low = students[i].studentGrades;
    }
  }
  cout << "The lowest grade is: " << low << endl;
}

void averageGrade(Student students[], int count)
{
  if (count == 0) return;
  float sum = 0;
  for (int i = 0; i < count; i++) {
    sum += students[i].studentGrades; // Add all grades up
  }
  cout << "The class average is: " << (sum / count) << endl;
}
void printStudentId(Student students[], int count)
{
  cout << "List of Students IDs:\n";
  for (int i = 0; i < count; i++) {
    cout << students[i].studentId << endl;
  }
}
void printStudentName(Student students[], int count)
{
  cout << "List of Studenys Names:\n";
  for (int i = 0; i < count; i++) {
    cout << students[i].studentName << endl;
  }
}



#include <iostream>
using namespace std;
#define MAXSTUDENT 80

struct STUDENT
{
	char name[30];
	char sname[30];
	int sti;
	char dept[30];
};

struct COURSE
{
	STUDENT list[MAXSTUDENT];
	int sz;
};

void print_one(STUDENT s) {
	cout << s.name << " " << s.sname << " " << s.sti << " " << s.dept << endl;
}

void addStudent(COURSE* cptr) {
	STUDENT s;
	cout << "Enter the name, surname, student id and department of the student with blanks: ";
	cin >> s.name >> s.sname >> s.sti >> s.dept;
	cptr->list[cptr->sz] = s;
	cptr->sz++;
}
void printStudents(COURSE* c) {
	for (int i = 0; i < c->sz; i++) {
		print_one(c->list[i]);
	}
}

void updateStudent(COURSE* c) {
	int sti;
	cout << "Enter the student id of the student to update: ";
	cin >> sti;
	bool found = false;
	for (int i = 0; i < c->sz; i++) {
		if (sti == c->list[i].sti) {
			cout << "Enter the name, surname, student id and department of the student with blanks: ";
			cin >> c->list[i].name >> c->list[i].sname >> c->list[i].sti >> c->list[i].dept;
			found = true; 
			break;
		}
	}
	if (!found) {
		cout << "Student with ID " << sti << " not found." << endl;
	}
}

void eraseStudent(COURSE* c) {
	int sti;
	cout << "Enter the student id of the student to erase: ";
	cin >> sti;
	if (c->sz == 0) {
		cout << "There is no student to erase." << endl;
		return;
	}

	bool found = false;
	for (int i = 0; i < c->sz; i++) {
		if (sti == c->list[i].sti) {
			for (int j = i; j < c->sz - 1; j++) {
				c->list[j] = c->list[j + 1];
			}
			c->sz--;
			found = true;
			cout << "Student with ID " << sti << " has been erased." << endl;
			break;
		}
	}

	if (!found) {
		cout << "Student with ID " << sti << " not found." << endl;
	}
}

int main()
{
	int option;
	COURSE CENG241;
	CENG241.sz = 0;

	while (true) {
		cout << "\nSelect an option:\n";
		cout << "1. Add Student\n";
		cout << "2. Erase Student\n";
		cout << "3. Update Student\n";
		cout << "4. Print Students\n";
		cout << "5. Exit\n";
		cout << "Option: ";
		cin >> option;

		switch (option) {
		case 1:
			addStudent(&CENG241);
			break;
		case 2:
			eraseStudent(&CENG241);
			break;
		case 3:
			updateStudent(&CENG241);
			break;
		case 4:
			printStudents(&CENG241);
			break;
		case 5:
			cout << "Exiting the program." << endl;
			return 0;
		default:
			cout << "Invalid option. Please try again." << endl;
			break;
		}
	}
}
#include <iostream>
#include <string>

#include "admin.h"
#include "authentication.h"
#include "file2struct.h"
#include "student.h"
#include "validation.h"

using namespace std;

const std::string ADMIN_FILE = "./admin.txt";
const std::string STUDENT_FILE = "./student.txt";

AdminList _ADMIN;
StudentList _STUDENT;

// registering new admin
void registerAdmin()
{
	Admin *admin = new Admin();
	cout << "Please insert information below" << endl;
	while (true)
	{
		cout << "Username: ";
		getline(cin, admin->username);
		if (isAdminUsernameExisted(_ADMIN, admin->username))
		{
			cout << "Username is already in used\n";
			continue;
		}
		cout << "Password: ";
		getline(cin, admin->password);
		if (isSpaceExisted(admin->password))
		{
			cout << "Password cannot contain space(s)" << endl;
			continue;
		}
		_ADMIN.Add(admin);
		adminToFile(_ADMIN, ADMIN_FILE);
		cout << "Register Successful" << endl;
		Enter();
		break;
	}
}

// register new student
void registerStudent()
{
	Student *student = new Student();
	cout << "Please insert information below" << endl;
	while (true)
	{

		cout << "Username: ";
		getline(cin, student->username);
		if (isStudentUsernameExisted(_STUDENT, student->username))
		{
			cout << "Username is already in use\n";
			continue;
		}
		cout << "Password: ";
		getline(cin, student->password);
		if (isSpaceExisted(student->password))
		{
			cout << "Password cannot contain space(s)" << endl;
			continue;
		}
		_STUDENT.Add(student);
		studentToFile(_STUDENT, STUDENT_FILE);
		cout << "Register Succesful" << endl;
		Enter();
		break;
	}
}

// Student Login
bool studentLogin()
{
	Student *student;
	int chance = 3;
	string username;
	string password;
	while (chance > 0)
	{
		cout << "Username: ";
		getline(cin, username);

		cout << "Password: ";
		getline(cin, password);

		student = getStudentByUsername(_STUDENT, username);
		if (student != nullptr && password == student->password)
		{
			return true;
		}

		cout << "Invalid credentials" << endl;
		chance--;
	}
	cout << "Too many attempt, please try again" << endl;
	Enter();
	return false;
}
// adminLogin
bool adminLogin()
{
	if (_ADMIN.Empty())
	{
		initAdmin();
		fileToAdmin(_ADMIN, ADMIN_FILE);
	}
	Admin *admin;
	int chance = 3;
	string username;
	string password;
	while (chance> 0)
	{
		cout << "Username: ";
		getline(cin, username);

		cout << "Password: ";
		getline(cin, password);

		admin = getAdminByUsername(_ADMIN, username);
		if (admin != nullptr && password == admin->password)
		{
			return true;
		}

		cout << "Invalid credentials" << endl;
		chance--;
	}
	cout << "Too many attempt, please try again" << endl;
	Enter();
	return false;
}
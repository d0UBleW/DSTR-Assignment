#include <iostream>
#include <string>

#include "admin.h"
#include "authentication.h"
#include "file2struct.h"
#include "student.h"
#include "validation.h"

const std::string ADMIN_FILE = "./admin.txt";
const std::string STUDENT_FILE = "./student.txt";

AdminList _ADMIN;
StudentList _STUDENT;

// registering new admin
void registerAdmin() {
  Admin *admin = new Admin();
  std::cout << "Please insert information below" << std::endl;
  while (true) {
    std::cout << "Username: ";
    std::getline(std::cin, admin->username);
    if (isAdminUsernameExisted(_ADMIN, admin->username)) {
      std::cout << "Username is already in used\n";
      continue;
    }
    std::cout << "Password: ";
    std::getline(std::cin, admin->password);
    if (isSpaceExisted(admin->password)) {
      std::cout << "Password cannot contain space(s)" << std::endl;
      continue;
    }
    _ADMIN.Add(admin);
    adminToFile(_ADMIN, ADMIN_FILE);
    std::cout << "Register Successful" << std::endl;
    Enter();
    break;
  }
}

// register new student
void registerStudent() {
  Student *student = new Student();
  std::cout << "Please insert information below" << std::endl;
  while (true) {

    std::cout << "Username: ";
    std::getline(std::cin, student->username);
    if (isStudentUsernameExisted(_STUDENT, student->username)) {
      std::cout << "Username is already in use\n";
      continue;
    }
    std::cout << "Password: ";
    std::getline(std::cin, student->password);
    if (isSpaceExisted(student->password)) {
      std::cout << "Password cannot contain space(s)" << std::endl;
      continue;
    }
    _STUDENT.Add(student);
    studentToFile(_STUDENT, STUDENT_FILE);
    std::cout << "Register Succesful" << std::endl;
    Enter();
    break;
  }
}

// Student Login
bool studentLogin() {
  Student *student;
  int chance = 3;
  std::string username;
  std::string password;
  while (true) {
    if (chance == 0) {
      std::cout << "Too many attempt, please try again" << std::endl;
      Enter();
      return false;
    }
    chance -= 1;
    std::cout << "Username: ";
    std::getline(std::cin, username);

    std::cout << "Password: ";
    std::getline(std::cin, password);

    student = getStudentByUsername(_STUDENT, username);
    if (student != nullptr && password == student->password) {
      return true;
    }

    std::cout << "Invalid credentials" << std::endl;
  }
}
// adminLogin
bool adminLogin() {
  if (_ADMIN.Empty()) {
    initAdmin();
    fileToAdmin(_ADMIN, ADMIN_FILE);
  }
  Admin *admin;
  int chance = 3;
  std::string username;
  std::string password;
  while (true) {
    if (chance == 0) {
      std::cout << "Too many attempt, please try again" << std::endl;
      Enter();
      return false;
    }
    chance -= 1;
    std::cout << "Username: ";
    std::getline(std::cin, username);

    std::cout << "Password: ";
    std::getline(std::cin, password);

    admin = getAdminByUsername(_ADMIN, username);
    if (admin != nullptr && password == admin->password) {
      return true;
    }

    std::cout << "Invalid credentials" << std::endl;
  }
}

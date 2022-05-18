#include <iostream>

#include "admin_menu.h"
#include "center.h"
#include "display.h"
#include "file2struct.h"
#include "subject.h"

const std::string TUTOR_FILE = "./tutor.txt";
const std::string SUBJECT_FILE = "./subject.txt";
const std::string CENTER_FILE = "./center.txt";
SubjectList _SUBJECT;
CenterList _CENTER;

extern AdminList _ADMIN;
extern StudentList _STUDENT;

int main()
{
    fileToAdmin(_ADMIN, ADMIN_FILE);
    fileToStudent(_STUDENT, STUDENT_FILE);
    fileToSubject(_SUBJECT, SUBJECT_FILE);
    fileToCenter(_CENTER, CENTER_FILE);

    TutorList tutorL;
    fileToTutor(tutorL, TUTOR_FILE);

    if (_SUBJECT.Empty())
    {
        initSubject();
        fileToSubject(_SUBJECT, SUBJECT_FILE);
    }

    if (_CENTER.Empty())
    {
        initCenter();
        fileToCenter(_CENTER, CENTER_FILE);
    }

    if (tutorL.Empty())
    {
        initTutor();
        fileToTutor(tutorL, TUTOR_FILE);
    }

    startMenu(tutorL);

    return 0;
}

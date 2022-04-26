#include <iostream>

#include "center.h"
#include "file2struct.h"
#include "subject.h"
#include "display.h"
#include "admin_menu.h"

const std::string TUTOR_FILE = "./tutor.txt";
const std::string SUBJECT_FILE = "./subject.txt";
const std::string CENTER_FILE = "./center.txt";
SubjectList _SUBJECT;
CenterList _CENTER;

int main() {
    fileToSubject(_SUBJECT, SUBJECT_FILE);
    fileToCenter(_CENTER, CENTER_FILE);

    TutorList tutorL;
    fileToTutor(tutorL, TUTOR_FILE);

    if (_SUBJECT.Empty()) {
        initSubject();
        fileToSubject(_SUBJECT, SUBJECT_FILE);
    }

    if (_CENTER.Empty()) {
        initCenter();
        fileToCenter(_CENTER, CENTER_FILE);
    }

    if (tutorL.Empty()) {
        initTutor();
        fileToTutor(tutorL, TUTOR_FILE);
    }

    /*tutorL.Display();*/
    /*DisplayTutor(tutorL);*/
    /*DisplayTutor(tutorL.head,tutorL.tail);*/
    startMenu(tutorL);
    
    

    return 0;
}

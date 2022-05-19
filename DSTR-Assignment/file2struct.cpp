#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "admin.h"
#include "center.h"
#include "date.h"
#include "file2struct.h"
#include "student.h"
#include "subject.h"
#include "tutor.h"

void initCenter()
{
    CenterList centerL;
    centerL.Add(new Center("C01", "Johor"));
    centerL.Add(new Center("C02", "Kedah"));
    centerL.Add(new Center("C03", "Kelantan"));
    centerL.Add(new Center("C04", "Malacca"));
    centerL.Add(new Center("C05", "Negeri Sembilan"));
    centerL.Add(new Center("C06", "Pahang"));
    centerL.Add(new Center("C07", "Penang"));
    centerL.Add(new Center("C08", "Perak"));
    centerL.Add(new Center("C09", "Perlis"));
    centerL.Add(new Center("C10", "Sabah"));
    centerL.Add(new Center("C11", "Sarawak"));
    centerL.Add(new Center("C12", "Selangor"));
    centerL.Add(new Center("C13", "Terengganu"));

    std::fstream fileHandler(CENTER_FILE, std::ios::out);
    std::string delim = "|";

    CenterNode *ptr = centerL.head;

    while (ptr != nullptr)
    {
        Center c = *(ptr->center);
        std::string ID = c.ID;
        std::string name = c.name;
        std::string line = ID + delim + name;
        fileHandler << line << '\n';
        ptr = ptr->next;
    }
    fileHandler.close();
}

void initSubject()
{
    SubjectList subjectL;
    subjectL.Add(new Subject("S01", "Chinese"));
    subjectL.Add(new Subject("S02", "Bahasa Malaysia"));
    subjectL.Add(new Subject("S03", "English"));
    subjectL.Add(new Subject("S04", "Mathematics"));
    subjectL.Add(new Subject("S05", "Chemistry"));
    subjectL.Add(new Subject("S06", "Biology"));
    subjectL.Add(new Subject("S07", "Physic"));

    std::fstream fileHandler(SUBJECT_FILE, std::ios::out);
    std::string delim = "|";

    SubjectNode *ptr = subjectL.head;

    while (ptr != nullptr)
    {
        Subject s = *(ptr->subject);
        std::string ID = s.ID;
        std::string name = s.name;
        std::string line = ID + delim + name;
        fileHandler << line << '\n';
        ptr = ptr->next;
    }
    fileHandler.close();
}

void initTutor()
{
    TutorList tutorL;
    Tutor *t1 = new Tutor();
    Tutor *t2 = new Tutor();
    Tutor *t3 = new Tutor();
    Tutor *t4 = new Tutor();
    Tutor *t5 = new Tutor();
    Tutor *t6 = new Tutor();
    Tutor *t7 = new Tutor();
    Tutor *t8 = new Tutor();
    Tutor *t9 = new Tutor();
    Tutor *t10 = new Tutor();
    Tutor *t11 = new Tutor();
    Tutor *t12 = new Tutor();
    Tutor *t13 = new Tutor();

    t1->ID = "T01";
    t1->name = "Andy";
    t1->payRate = 40;
    t1->rating = 0;
    t1->phone = "0193480480";
    t1->address = "TPM";
    t1->joinDate = Date("1/1/2022");
    t1->terminateDate = Date("-");
    t1->center = getCenterByID(_CENTER, "C01");
    t1->subject = getSubjectByID(_SUBJECT, "S01");
    t1->countRate = 0;

    t2->ID = "T02";
    t2->name = "Bob";
    t2->payRate = 80;
    t2->rating = 0;
    t2->phone = "0128734193";
    t2->address = "TPM";
    t2->joinDate = Date("1/1/2022");
    t2->terminateDate = Date("-");
    t2->center = getCenterByID(_CENTER, "C02");
    t2->subject = getSubjectByID(_SUBJECT, "S02");
    t2->countRate = 0;

    t3->ID = "T03";
    t3->name = "Charlie";
    t3->payRate = 45;
    t3->rating = 0;
    t3->phone = "0120398148";
    t3->address = "TPM";
    t3->joinDate = Date("1/1/2022");
    t3->terminateDate = Date("-");
    t3->center = getCenterByID(_CENTER, "C03");
    t3->subject = getSubjectByID(_SUBJECT, "S03");
    t3->countRate = 0;

    t4->ID = "T04";
    t4->name = "Danny";
    t4->payRate = 75;
    t4->rating = 0;
    t4->phone = "0720427031";
    t4->address = "TPM";
    t4->joinDate = Date("1/1/2022");
    t4->terminateDate = Date("-");
    t4->center = getCenterByID(_CENTER, "C01");
    t4->subject = getSubjectByID(_SUBJECT, "S01");
    t4->countRate = 0;

    t5->ID = "T05";
    t5->name = "Emma";
    t5->payRate = 50;
    t5->rating = 0;
    t5->phone = "0149874198";
    t5->address = "TPM";
    t5->joinDate = Date("1/1/2022");
    t5->terminateDate = Date("-");
    t5->center = getCenterByID(_CENTER, "C02");
    t5->subject = getSubjectByID(_SUBJECT, "S02");
    t5->countRate = 0;

    t6->ID = "T06";
    t6->name = "Frank";
    t6->payRate = 70;
    t6->rating = 0;
    t6->phone = "0147969143";
    t6->address = "TPM";
    t6->joinDate = Date("1/1/2022");
    t6->terminateDate = Date("-");
    t6->center = getCenterByID(_CENTER, "C03");
    t6->subject = getSubjectByID(_SUBJECT, "S03");
    t6->countRate = 0;

    t7->ID = "T07";
    t7->name = "Gilbert";
    t7->payRate = 55;
    t7->rating = 0;
    t7->phone = "01893479571";
    t7->address = "TPM";
    t7->joinDate = Date("1/1/2022");
    t7->terminateDate = Date("-");
    t7->center = getCenterByID(_CENTER, "C01");
    t7->subject = getSubjectByID(_SUBJECT, "S01");
    t7->countRate = 0;

    t8->ID = "T08";
    t8->name = "Howard";
    t8->payRate = 65;
    t8->rating = 0;
    t8->phone = "01039481947";
    t8->address = "TPM";
    t8->joinDate = Date("1/1/2022");
    t8->terminateDate = Date("-");
    t8->center = getCenterByID(_CENTER, "C02");
    t8->subject = getSubjectByID(_SUBJECT, "S02");
    t8->countRate = 0;

    t9->ID = "T09";
    t9->name = "Ian";
    t9->payRate = 60;
    t9->rating = 0;
    t9->phone = "0348798111";
    t9->address = "TPM";
    t9->joinDate = Date("1/1/2022");
    t9->terminateDate = Date("-");
    t9->center = getCenterByID(_CENTER, "C03");
    t9->subject = getSubjectByID(_SUBJECT, "S03");
    t9->countRate = 0;

    t10->ID = "T10";
    t10->name = "Julio";
    t10->payRate = 60;
    t10->rating = 0;
    t10->phone = "0184038501";
    t10->address = "TPM";
    t10->joinDate = Date("1/1/2022");
    t10->terminateDate = Date("-");
    t10->center = getCenterByID(_CENTER, "C01");
    t10->subject = getSubjectByID(_SUBJECT, "S01");
    t10->countRate = 0;

    t11->ID = "T11";
    t11->name = "Julio";
    t11->payRate = 60;
    t11->rating = 0;
    t11->phone = "0184038501";
    t11->address = "TPM";
    t11->joinDate = Date("1/1/2022");
    t11->terminateDate = Date("-");
    t11->center = getCenterByID(_CENTER, "C01");
    t11->subject = getSubjectByID(_SUBJECT, "S01");
    t11->countRate = 0;

    t12->ID = "T12";
    t12->name = "Julio";
    t12->payRate = 60;
    t12->rating = 0;
    t12->phone = "0184038501";
    t12->address = "TPM";
    t12->joinDate = Date("1/1/2022");
    t12->terminateDate = Date("-");
    t12->center = getCenterByID(_CENTER, "C01");
    t12->subject = getSubjectByID(_SUBJECT, "S01");
    t12->countRate = 0;

    t13->ID = "T13";
    t13->name = "Loo";
    t13->payRate = 80;
    t13->rating = 0;
    t13->phone = "0180902093";
    t13->address = "TPM";
    t13->joinDate = Date("1/1/2022");
    t13->terminateDate = Date("-");
    t13->center = getCenterByID(_CENTER, "C13");
    t13->subject = getSubjectByID(_SUBJECT, "S06");
    t13->countRate = 0;

    tutorL.AddToLast(t1);
    tutorL.AddToFront(t2);
    tutorL.AddToLast(t3);
    tutorL.AddToLast(t4);
    tutorL.AddToLast(t5);
    tutorL.AddToLast(t6);
    tutorL.AddToLast(t7);
    tutorL.AddToLast(t8);
    tutorL.AddToLast(t9);
    tutorL.AddToLast(t10);
    tutorL.AddToLast(t11);
    tutorL.AddToLast(t12);

    tutorToFile(tutorL, TUTOR_FILE);
}

void initAdmin()
{
    AdminList adminL;
    adminL.Add(new Admin("admin", "password"));
    adminToFile(adminL, ADMIN_FILE);
}

void fileToTutor(TutorList &tutorL, const std::string filename)
{
    std::fstream fileHandler(filename, std::ios::in);
    std::string line = "";
    std::string delim = "|";

    while (!getline(fileHandler, line).eof() && line.length() != 0)
    {
        std::vector<std::string> data = splitString(line, delim);
        Tutor *t = new Tutor();
        t->ID = data.at(0);
        t->name = data.at(1);
        t->payRate = std::stof(data.at(2));
        t->rating = std::stof(data.at(3));
        t->phone = data.at(4);
        t->address = data.at(5);
        t->joinDate = Date(data.at(6));
        t->terminateDate = Date(data.at(7));
        t->center = getCenterByID(_CENTER, data.at(8));
        t->subject = getSubjectByID(_SUBJECT, data.at(9));
        t->countRate = std::stoul(data.at(10));
        tutorL.AddToLast(t);
    }
    fileHandler.close();
}

void fileToSubject(SubjectList &subjectL, const std::string filename)
{
    std::fstream fileHandler(filename, std::ios::in);
    std::string line = "";
    std::string delim = "|";

    while (!getline(fileHandler, line).eof() && line.length() != 0)
    {
        std::vector<std::string> data = splitString(line, delim);
        Subject *s = new Subject();
        s->ID = data.at(0);
        s->name = data.at(1);
        subjectL.Add(s);
    }
    fileHandler.close();
}

void fileToCenter(CenterList &centerL, const std::string filename)
{
    std::fstream fileHandler(filename, std::ios::in);
    std::string line = "";
    std::string delim = "|";

    while (!getline(fileHandler, line).eof() && line.length() != 0)
    {
        std::vector<std::string> data = splitString(line, delim);
        Center *c = new Center();
        c->ID = data.at(0);
        c->name = data.at(1);
        centerL.Add(c);
    }
    fileHandler.close();
}

void tutorToFile(TutorList &tutorL, std::string filename)
{
    std::fstream fileHandler(filename, std::ios::out);
    std::string delim = "|";

    TutorNode *ptr = tutorL.head;

    while (ptr != nullptr)
    {
        Tutor t = *(ptr->tutor);
        std::string ID = t.ID;
        std::string name = t.name;
        std::string payRate = float_to_str_prec(t.payRate);
        std::string rating = float_to_str_prec(t.rating);
        std::string phone = t.phone;
        std::string address = t.address;
        std::string joinDate = t.joinDate.ToString();
        std::string terminateDate = t.terminateDate.ToString();
        std::string center = t.center->ID;
        std::string subject = t.subject->ID;
        std::string countRate = std::to_string(t.countRate);
        std::string line = ID + delim + name + delim + payRate + delim + rating + delim + phone + delim + address +
                           delim + joinDate + delim + terminateDate + delim + center + delim + subject + delim +
                           countRate;
        fileHandler << line << '\n';
        ptr = ptr->next;
    }
    fileHandler.close();
}

void fileToStudent(StudentList &studentL, std::string filename)
{
    std::fstream fileHandler(filename, std::ios::in);
    std::string line = "";
    std::string delim = "|";

    while (!getline(fileHandler, line).eof() && line.length() != 0)
    {
        std::vector<std::string> data = splitString(line, delim);
        Student *stu = new Student();
        stu->username = data.at(0);
        stu->password = data.at(1);
        studentL.Add(stu);
    }
    fileHandler.close();
}

void studentToFile(StudentList &studentL, std::string filename)
{
    std::fstream fileHandler(filename, std::ios::out);
    std::string delim = "|";

    StudentNode *ptr = studentL.head;

    while (ptr != nullptr)
    {
        Student stu = *(ptr->student);
        std::string username = stu.username;
        std::string password = stu.password;
        fileHandler << username << delim << password << '\n';
        ptr = ptr->next;
    }
    fileHandler.close();
}

void fileToAdmin(AdminList &adminL, std::string filename)
{
    std::fstream fileHandler(filename, std::ios::in);
    std::string line = "";
    std::string delim = "|";

    while (!getline(fileHandler, line).eof() && line.length() != 0)
    {
        std::vector<std::string> data = splitString(line, delim);
        Admin *adm = new Admin();
        adm->username = data.at(0);
        adm->password = data.at(1);
        adminL.Add(adm);
    }
    fileHandler.close();
}

void adminToFile(AdminList &adminL, std::string filename)
{
    std::fstream fileHandler(filename, std::ios::out);
    std::string delim = "|";

    AdminNode *ptr = adminL.head;

    while (ptr != nullptr)
    {
        Admin adm = *(ptr->admin);
        std::string username = adm.username;
        std::string password = adm.password;
        fileHandler << username << delim << password << '\n';
        ptr = ptr->next;
    }
    fileHandler.close();
}

std::vector<std::string> splitString(std::string str, std::string delim)
{
    std::vector<std::string> data;
    size_t start = 0;
    size_t end = str.find(delim);
    while (end != std::string::npos)
    {
        data.push_back(str.substr(start, end - start));
        start = end + delim.length();
        end = str.find(delim, start);
    }
    data.push_back(str.substr(start));
    return data;
}

std::string float_to_str_prec(float f, int n)
{
    std::ostringstream out;
    out.precision(n);
    out << std::fixed << f;
    return out.str();
}

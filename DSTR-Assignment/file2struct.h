#ifndef FILE2STRUCT_H_INCLUDED
#define FILE2STRUCT_H_INCLUDED

#include <vector>

#include "admin.h"
#include "center.h"
#include "student.h"
#include "subject.h"
#include "tutor_list.h"

extern const std::string TUTOR_FILE;
extern const std::string SUBJECT_FILE;
extern const std::string CENTER_FILE;
extern const std::string ADMIN_FILE;
extern const std::string STUDENT_FILE;
extern CenterList _CENTER;
extern SubjectList _SUBJECT;

void initCenter();

void initSubject();

void initTutor();

void initAdmin();

/**
 * @brief import data from text file to Tutor vector
 *
 * @param filename specifies the text file's path which will be imported to
 *
 * @return a vector object with Tutor data from specified text file
 */
void fileToTutor(TutorList &, const std::string filename);

/**
 * @brief import data from text file to Subject vector
 *
 * @param filename specifies the text file's path which will be imported to
 *
 * @return a vector object with Subject data from specified text file
 */
void fileToSubject(SubjectList &, const std::string filename);

/**
 * @brief import data from text file to Center vector
 *
 * @param filename specifies the text file's path which will be imported to
 *
 * @return a vector object with Center data from specified text file
 */
void fileToCenter(CenterList &, const std::string filename);

/**
 * @brief export Tutor vector object to a text file
 *
 * @note tutorV is passed as reference to avoid copying the whole Tutor vector
 *       object into the function
 *
 * @param tutorV specifies the object to be exported
 * @param filename specifies the text file's path to write to
 */
void tutorToFile(TutorList &tutorL, std::string filename);

/**
 * @brief import data from text file to Student vector
 *
 * @param filename specifies the text file's path which will be imported to
 *
 * @return a vector object with Student data from specified text file
 */
void fileToStudent(StudentList &, std::string filename);

/**
 * @brief export Tutor vector object to a text file
 *
 * @note studentV is passed as reference to avoid copying the whole object into
 *       the function
 *
 * @param studentV specifies the object to be exported
 * @param filename specifies the text file's path to write to
 */
void studentToFile(StudentList &, std::string filename);

/**
 * @brief import data from text file to Admin vector
 *
 * @param filename specifies the text file's path which will be imported to
 *
 * @return a vector object with Admin data from specified text file
 */
void fileToAdmin(AdminList &, std::string filename);

/**
 * @brief export Tutor vector object to a text file
 *
 * @note adminV is passed as reference to avoid copying the whole object into
 *       the function
 *
 * @param adminV specifies the object to be exported
 * @param filename specifies the text file's path to write to
 */
void adminToFile(AdminList &, std::string filename);

/**
 * @brief to split string with the specified delimiter
 *
 * @param str specifies the string to be split
 * @param delim specifies the delimiter
 *
 * @return a vector object which contains the string tokens
 */
std::vector<std::string> splitString(std::string str, std::string delim);

/**
 * @brief convert float to string with fixed precision
 *
 * @param f specifies the float value to be converted
 * @param n specifies the precision
 *
 * @return a string representation of the float value with fixed precision
 */
std::string float_to_str_prec(float f, int n = 2);

#endif

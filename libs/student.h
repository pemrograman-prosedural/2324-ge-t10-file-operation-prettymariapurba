#ifndef STUDENT_H
#define STUDENT_H

#include "gender.h"
#include "dorm.h"

/**
 * @brief define your structure, enums, globally accessible variables, and function prototypes here.
 * The actual function implementation should be defined in the corresponding source file.
 *
 */

struct student_t
{
    char id[12];
    char name[40];
    char year[5];
    enum gender_t gender;
    struct dorm_t *dorm;
};

void getString(char *str);
struct student_t create_student(char *_id, char *_name, char *_year,
                                enum gender_t _gender);
void student_print_all_detail(struct student_t *_students, int _countStudent);
void student_print_all(struct student_t *_students, int _countStudent);
void assign_student(struct student_t *_student, struct dorm_t *_dorm, char *id, char *dorm_name, int _countDorm, int _countStudent);
void moving_student(struct student_t *_student, struct dorm_t *_dorm, char *id, char *dorm_name, int _countDorm, int _countStudent);

#endif

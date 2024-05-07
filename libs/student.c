#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Define the complete function definition here. Be sure to enlist the prototype of each function
 * defined here in the corresponding header file.
 *
 */

void getString(char *str)
{
    str[0] = '\0';
    int c = 0;

    do
    {

        char x = getchar();
        if (x == '\r')

        {
            continue;
        }
        if (x == '\n')
        {
            break;
        }
        str[c] = x;
        str[++c] = '\0';
    } while (1);
}

struct student_t create_student(char *_id, char *_name, char *_year,
                                enum gender_t _gender)
{
    struct student_t student;
    strcpy(student.id, _id);
    strcpy(student.name, _name);
    strcpy(student.year, _year);
    student.gender = _gender;
    student.dorm = NULL;
    return student;
}

void student_print_all(struct student_t *_students, int _countStudent)
{
    for (int i = 0; i < _countStudent; i++)
    {
        // 12S22002|Jeremy Nainggolan|2022|male
        printf("%s|%s|%s|%s\n", _students[i].id, _students[i].name, _students[i].year, gender_to_teks(_students[i].gender));
    }
}

void student_print_all_detail(struct student_t *_students, int _countStudent)
{

    for (int i = 0; i < _countStudent; i++)
    {
        if (_students[i].dorm == NULL)
        {
            printf("%s|%s|%s|%s|unassigned\n", _students[i].id, _students[i].name, _students[i].year, gender_to_teks(_students[i].gender));
        }
        else if (_students[i].dorm == NULL)
        {
            printf("%s|%s|%s|%s|left\n", _students[i].id, _students[i].name, _students[i].year, gender_to_teks(_students[i].gender));
        }
        else
        {
            printf("%s|%s|%s|%s|%s\n", _students[i].id, _students[i].name, _students[i].year, gender_to_teks(_students[i].gender), _students[i].dorm->name);
        }
    }
}

// assign-student#12S22001#Antiokia
void assign_student(struct student_t *_student, struct dorm_t *_dorm, char *id, char *dorm_name, int _countDorm, int _countStudent)
{
    for (int i = 0; i < _countStudent; i++)
    {
        if (strcmp(_student[i].id, id) == 0)
        {
            for (int j = 0; j < _countDorm; j++)
            {
                if (strcmp(_dorm[j].name, dorm_name) == 0)
                {
                    if (_student[i].gender == _dorm[j].gender)
                    {
                        if (_dorm[j].residents_num < _dorm[j].capacity)
                        {
                            _student[i].dorm = &_dorm[j];
                            _dorm[j].residents_num++;
                        }
                    }
                }
            }
        }
    }
}






void moving_student(struct student_t *_student, struct dorm_t *_dorm, char *id, char *dorm_name, int _countDorm, int _countStudent)
{
    for (int i = 0; i < _countStudent; i++)
    {
        if (strcmp(_student[i].id, id) == 0)
        {
            for (int j = 0; j < _countDorm; j++)
            {
                if (strcmp(_dorm[j].name, dorm_name) == 0)
                {
                    if (_dorm[j].residents_num < _dorm[j].capacity)
                    {
                        if (_student[i].dorm != NULL)
                        {
                            _student[i].dorm->residents_num--;
                        }
                        _student[i].dorm = &_dorm[j];
                        _dorm[j].residents_num++;
                    }
                }
            }
        }
    }
}


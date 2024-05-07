// 12S23043 - Grace Tiodora
// 12S23042 - Pretty Maria

#include <stdio.h>
#include "./libs/dorm.h"
#include "./libs/student.h"
#include "./libs/repository.h"
#include <stdlib.h>
#include <string.h>

int main(int _argc, char **_argv)
{
    struct student_t *students = malloc(sizeof(struct student_t) * 100);
    struct dorm_t *dorms = malloc(sizeof(struct dorm_t) * 100);
    int idxStud = 0, idxDorm = 0;
    char *token;

    FILE *fpDorm = fopen("./storage/dorm-repository.txt", "r");
    FILE *outFpDorm = fopen("./storage/dorm-repository.txt", "a");
    FILE *fpStudent = fopen("./storage/student-repository.txt", "r");
    FILE *outFpStudent = fopen("./storage/student-repository.txt", "a");

    while (1)
    {

        char buffer[100];
        buffer[0] = '\0';
        get_line(fpDorm, buffer, 100);
        if (feof(fpDorm))
        {
            break;
        }
        token = strtok(buffer, "|");
        strcpy(dorms[idxDorm].name, token);
        token = strtok(NULL, "|");
        dorms[idxDorm].capacity = atoi(token);
        token = strtok(NULL, "|");

        if (strcmp(token, "male") == 0)
        {

            dorms[idxDorm] = create_dorm(dorms[idxDorm].name, dorms[idxDorm].capacity, GENDER_MALE);
            idxDorm++;
        }
        else if (strcmp(token, "female") == 0)
        {
            dorms[idxDorm] = create_dorm(dorms[idxDorm].name, dorms[idxDorm].capacity, GENDER_FEMALE);
            idxDorm++;
        }
    }
    fclose(fpDorm);

    while (1)
    {
        char buffer[100];
        buffer[0] = '\0';
        get_line(fpStudent, buffer, 100);

        if (feof(fpStudent))
        {
            break;
        }
        char *id = strtok(buffer, "|");
        char *name = strtok(NULL, "|");
        char *year = strtok(NULL, "|");
        char *tmp = strtok(NULL, "|");

        if (strcmp(tmp, "male") == 0)
        {

            students[idxStud] = create_student(id, name, year, GENDER_MALE);
            idxStud++;
        }
        else if (strcmp(tmp, "female") == 0)
        {
            students[idxStud] = create_student(id, name, year, GENDER_FEMALE);
            idxStud++;
        }
    }
    fclose(fpStudent);

    while (1)
    {
        char *str = malloc(100 * sizeof(char));
        getString(str);

        char *tmp;

        if (strcmp(str, "---") == 0)
        {
            break;
        }
        else
        {
            tmp = strtok(str, "#");
            if (strcmp(tmp, "student-add") == 0)
            {
                int cek = 0;
                char *id = strtok(NULL, "#");
                char *name = strtok(NULL, "#");
                char *year = strtok(NULL, "#");
                tmp = strtok(NULL, "#");

                if (strcmp(tmp, "male") == 0)
                {
                    for (int i = 0; i < idxStud; i++)
                    {
                        if (strcmp(students[i].id, id) != 0)
                        {
                            students[idxStud] = create_student(id, name, year, GENDER_MALE);
                            idxStud++;
                            cek = 1;
                            break;
                        }
                    }
                }
                else if (strcmp(tmp, "female") == 0)
                {
                    for (int j = 0; j < idxStud; j++)
                    {
                        if (strcmp(students[j].id, id) != 0)
                        {
                            students[idxStud] = create_student(id, name, year, GENDER_FEMALE);
                            idxStud++;
                            cek = 1;
                            break;
                        }
                    }
                }
                if (cek == 1)
                {
                    fprintf(outFpStudent, "%s\n", toString(students[idxStud - 1]));
                }
            }
            else if (strcmp(str, "student-print-all-detail") == 0)
            {
                student_print_all_detail(students, idxStud);
            }
            else if (strcmp(str, "student-print-all") == 0)
            {

                student_print_all(students, idxStud);
            }
            else if (strcmp(str, "dorm-add") == 0)
            {
                int cek = 0;
                char *name = strtok(NULL, "#");
                char *capacity = strtok(NULL, "#");
                int cap = atoi(capacity);
                tmp = strtok(NULL, "#");
                if (strcmp(tmp, "male") == 0)
                {
                    for (int i = 0; i < idxDorm; i++)
                    {
                        if (strcmp(dorms[i].name, name) != 0)
                        {
                            dorms[idxDorm] = create_dorm(name, cap, GENDER_MALE);
                            idxDorm++;
                            cek = 1;
                            break;
                        }
                    }
                }
                else if (strcmp(tmp, "female") == 0)
                {
                    for (int i = 0; i < idxDorm; i++)
                    {
                        if (strcmp(dorms[i].name, name) != 0)
                        {
                            dorms[idxDorm] = create_dorm(name, cap, GENDER_FEMALE);

                            idxDorm++;
                            cek = 1;
                            break;
                        }
                    }
                }

                if (cek == 1)
                {
                    fprintf(outFpDorm, "%s\n", toStringDorm(dorms[idxDorm - 1]));
                }
            }
            else if (strcmp(str, "dorm-print-all") == 0)
            {
                dorm_print_all(dorms, idxDorm);
            }
            else if (strcmp(str, "dorm-print-all-detail") == 0)
            {
                dorm_print_all_detail(dorms, idxDorm);
            }
            else if (strcmp(str, "assign-student") == 0)
            {

                char *id = strtok(NULL, "#");
                char *dorm_name = strtok(NULL, "#");
                assign_student(students, dorms, id, dorm_name, idxDorm, idxStud);
            }
            else if (strcmp(str, "move-student") == 0)
            {
                char *id = strtok(NULL, "#");
                char *dorm_name = strtok(NULL, "#");

                moving_student(students, dorms, id, dorm_name, idxDorm, idxStud);
            }
        }
    }
    return 0;
}

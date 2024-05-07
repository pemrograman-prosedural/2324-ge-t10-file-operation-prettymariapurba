#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "gender.h"
#include "dorm.h"
#include "student.h"
#include <stdio.h>

void get_line(FILE *_stream, char *_buffer, unsigned int _size);
char *toString(struct student_t std);
char *toStringDorm(struct dorm_t dorms);

#endif

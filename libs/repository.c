#include "repository.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "dorm.h"
#include "student.h"
#include "gender.h"

/**
 * @brief Define the complete function definition here. Be sure to enlist the prototype of each function
 * defined here in the corresponding header file.
 *
 */

void get_line(FILE *_stream, char *_buffer, unsigned int _size)
{
    char ch = '\0';
    unsigned int i = 0;
    _buffer[i] = '\0';
    while (i < _size && (ch = fgetc(_stream)) != '\n')
    {
        if (ch == '\r')
        {
            continue;
        }
        if (ch == '\n')
        {
            break;
        }
        _buffer[i++] = ch;
        _buffer[i] = '\0';
    }
}

char *toString(struct student_t std)
{
    char *str = malloc(100 * sizeof(char));
    sprintf(str, "%s|%s|%s|%s", std.id, std.name, std.year, genderDorm_to_teks(std.gender));
    return str;
}

char *toStringDorm(struct dorm_t dorms)
{
    char *str = malloc(100 * sizeof(char));
    sprintf(str, "%s|%d|%s", dorms.name, dorms.capacity, genderDorm_to_teks(dorms.gender));
    return str;
}

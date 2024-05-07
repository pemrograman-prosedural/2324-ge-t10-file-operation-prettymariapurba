#include "dorm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Define the complete function definition here. Be sure to enlist the prototype of each function
 * defined here in the corresponding header file.
 *
 */

char *genderDorm_to_teks(enum gender_t _gender)
{
    char *text = malloc(8);
    text[0] = '\0';
    switch (_gender)
    {
    case GENDER_MALE:
        strcpy(text, "male");
        break;
    case GENDER_FEMALE:

        strcpy(text, "female");

        break;
    }
    return text;
}

struct dorm_t create_dorm(char *_name, unsigned short _capacity, enum gender_t _gender)
{
    struct dorm_t asrama;
    strcpy(asrama.name, _name);
    asrama.capacity = _capacity;
    asrama.gender = _gender;
    asrama.residents_num = 0;
    return asrama;
}

void dorm_print_all(struct dorm_t *_dorms, int _countDorm)
{
    for (int i = 0; i < _countDorm; i++)
    {
        printf("%s|%d|%s\n", _dorms[i].name, _dorms[i].capacity, genderDorm_to_teks(_dorms[i].gender));
    }
}

void dorm_print_all_detail(struct dorm_t *_dorms, int _countDorm)
{
    for (int i = 0; i < _countDorm; i++)
    {
        printf("%s|%d|%s|%d\n", _dorms[i].name, _dorms[i].capacity, genderDorm_to_teks(_dorms[i].gender), _dorms[i].residents_num);
    }
}

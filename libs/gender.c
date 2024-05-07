#include "gender.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * @brief Define the complete function definition here. Be sure to enlist the prototype of each function
 * defined here in the corresponding header file.
 *
 */
char *gender_to_teks(enum gender_t _gender)
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

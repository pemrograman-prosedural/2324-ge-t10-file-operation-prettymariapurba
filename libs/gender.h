#ifndef GENDER_H
#define GENDER_H

/**
 * @brief define your structure, enums, globally accessible variables, and function prototypes here.
 * The actual function implementation should be defined in the corresponding source file.
 *
 */

enum gender_t
{
    GENDER_MALE,
    GENDER_FEMALE
};

char *gender_to_teks(enum gender_t _gender);
#endif


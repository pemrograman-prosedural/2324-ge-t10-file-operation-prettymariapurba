#ifndef DORM_H
#define DORM_H
#include "gender.h"

struct dorm_t
{
  char name[20];
  unsigned short capacity;
  enum gender_t gender;
  unsigned short residents_num;
};

struct dorm_t create_dorm(char *_name, unsigned short _capacity, enum gender_t _gender);
void print_all_dorm (struct dorm_t *dorms, unsigned short int size_dorm);
void print_name_dorm (struct dorm_t *dorms, unsigned short int size_dorm);

#endif

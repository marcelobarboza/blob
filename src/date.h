#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <stdbool.h>
#include <stdio.h>

typedef struct {
  int year;
  int month;
  int day;
} date_t;

typedef enum { sun, mon, tue, wed, thu, fri, sat } wday_t;

/* date algorithms */
bool is_leap(int);
int days_in_month(int, int);
wday_t weekday(date_t);
date_t easter(int);
int to_ordinal(date_t);
date_t from_ordinal(int);
date_t time_travel(date_t, int);
int ordering(date_t, date_t);
void bubble_sort(const int, date_t *const);
bool found_in(const int, const date_t *const, const date_t);

#endif // DATE_H_INCLUDED

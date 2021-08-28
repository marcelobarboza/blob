#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED

#include "date.h"

bool test_for_leap_years(int);
bool test_for_days_in_month(int, int);
int squared(int);
bool from_ordinal_cancels_out_to_ordinal(date_t);
bool to_ordinal_cancels_out_from_ordinal(int);
date_t up_until_from_ordinal_cancels_out_to_ordinal(void);
int up_until_to_ordinal_cancels_out_from_ordinal(void);

#endif // TEST_H_INCLUDED

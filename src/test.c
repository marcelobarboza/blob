#include "date.h"

bool
test_for_leap_years(int year)
{
  bool test1 = is_leap(2016);
  bool test2 = is_leap(2020);
  bool test3 = is_leap(2024);
  bool test4 = is_leap(2018);
  bool test5 = is_leap(2007);
  bool test6 = is_leap(1991);
  bool test7 = is_leap(1992);
  bool res = false;

  if (test1 && test2 && test3 && !test4 && !test5 && !test6 && !test7)
    res = true;

  return res;
}

bool
test_for_days_in_month(int year, int month)
{
  bool test1 = days_in_month(2016, 2) == 29;
  bool test2 = days_in_month(1992, 2) == 28;
  bool res = false;

  if (test1 && test2)
    res = true;

  return res;
}

int
squared(int x)
{
  return x * x;
}

bool
from_ordinal_cancels_out_to_ordinal(date_t date)
{
  date_t recovered_date = from_ordinal(to_ordinal(date));
  int error = 0;

  error += squared(recovered_date.year - date.year);
  error += squared(recovered_date.month - date.month);
  error += squared(recovered_date.day - date.day);

  return error == 0;
}

bool
to_ordinal_cancels_out_from_ordinal(int n)
{
  int m = to_ordinal(from_ordinal(n));

  return m == n;
}

date_t
up_until_from_ordinal_cancels_out_to_ordinal(void)
{
  date_t date = {1, 1, 1};

  while (from_ordinal_cancels_out_to_ordinal(date) && date.year < 58795)
    date = time_travel(date, 1);

  return date;
}

int
up_until_to_ordinal_cancels_out_from_ordinal(void)
{
  int n = 61;

  while (to_ordinal_cancels_out_from_ordinal(n) && n < 21539812)
    n++;

  return n;
}

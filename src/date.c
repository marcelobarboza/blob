#include "date.h"

bool
is_leap(int year)
{
  return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

int
days_in_month(int year, int month)
{
  int days[13] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  days[2] += is_leap(year) ? 1 : 0;

  return days[month];
}

wday_t
weekday(date_t d)
{
  return (d.day += d.month < 3 ? d.year-- : d.year - 2,
          23 * d.month / 9 + d.day + 4 + d.year / 4 - d.year / 100 +
              d.year / 400) % 7;
}

date_t
easter(int year)
{
  int g = year % 19;
  int c = year / 100;
  int h = (c - c / 4 - (8 * c + 13) / 25 + 19 * g + 15) % 30;
  int i = h - (h / 28) * (1 - (h / 28) * (29 / (h + 1)) * ((21 - g) / 11));
  int j = (year + year / 4 + i + 2 - c + c / 4) % 7;
  int p = i - j;

  date_t easter = {year, 3 + (p + 26) / 30, 1 + (p + 27 + (p + 6) / 40) % 31};

  return easter;
}

int
to_ordinal(date_t d)
{
  if (d.month < 3) {
    d.month += 12;
    d.year--;
  }

  return d.day + (153 * d.month - 457) / 5 + 365 * d.year + d.year / 4 -
         d.year / 100 + d.year / 400 - 306;
}

date_t
from_ordinal(int ndays)
{
  int Z = ndays + 306;
  int H = 100 * Z - 25;
  int A = H / 3652425;
  int B = A - A / 4;
  int Y = (100 * B + H) / 36525;
  int C = B + Z - 365 * Y - Y / 4;
  int M = (5 * C + 456) / 153;
  int D = C - (153 * M - 457) / 5;

  date_t d = {.year = Y, .month = M, .day = D};

  if (d.month > 12) {
    d.year++;
    d.month -= 12;
  }

  return d;
}

date_t
time_travel(date_t d, int ndays)
{
  return from_ordinal(to_ordinal(d) + ndays);
}

int
ordering(date_t d1, date_t d2)
{
  int n1 = to_ordinal(d1);
  int n2 = to_ordinal(d2);
  int less_than_or_equal_to = 0;

  if (n1 != n2)
    less_than_or_equal_to = n1 < n2 ? -1 : 1;
  return less_than_or_equal_to;
}

void
bubble_sort(const int h, date_t *const H)
{
  int i;
  int j;

  date_t d_tmp;
  for (i = 0; i < h - 1; i++)
    for (j = 0; j < h - 1; j++)
      if (ordering(*(H + j), *(H + j + 1)) == 1) {
        d_tmp = *(H + j);
        *(H + j) = *(H + j + 1);
        *(H + j + 1) = d_tmp;
      }
}

bool
found_in(const int h, const date_t *const H, const date_t d)
{
  bool found = false;
  int lower_bound = 0;
  int upper_bound = h - 1;
  int mean;

  while (lower_bound <= upper_bound && !found) {
    mean = (lower_bound + upper_bound) / 2;
    if (ordering(d, *(H + mean)) == -1)
      upper_bound = mean - 1;
    else if (ordering(d, *(H + mean)) == 0)
      found = true;
    else
      lower_bound = mean + 1;
  }

  return found;
}

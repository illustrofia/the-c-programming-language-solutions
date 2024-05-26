#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);
char *month_name(int n);

int main(void)
{
  int year = 1999;
  int yearday = 71;
  int month, day;

  month = day = 0;

  month_day(year, yearday, &month, &day);

  if (day && month)
  {
    printf("Day %d of year %d is %s %d.\n", yearday, year, month_name(month), day);
  }

  if (day && month)
  {
    printf("%s %d %d is day %d of year\n", month_name(month), day, year, day_of_year(year, month, day));
  }
}

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

// day_of_year: set day of year from month & day
int day_of_year(int year, int month, int day)
{
  int leap;
  char *p;

  leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

  p = daytab[leap];

  if (month < 1 || month > 12)
  {
    printf("error: impossible month value (%i).\n", month);
    return -1;
  }
  else if (day > *(p + month))
  {
    printf("error: impossible day value (%i).\n", month);
    return -1;
  }

  while (month--)
  {
    day += *p++;
  }

  return day;
}

// month_day: set month, day from day of year
void month_day(int year, int yearday, int *pmonth, int *pday)
{
  int leap;
  char *p;

  if (yearday < 1 || yearday > ((leap) ? 366 : 365))
  {
    printf("error: impossible yearday value (%i).\n", yearday);
    return;
  }

  leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

  p = daytab[leap];

  *pday = yearday;

  while (*pday > *p)
  {
    *pday -= *p++;
    (*pmonth)++;
  }
}

// month_name: returns name of n-th month
char *month_name(int n)
{
  static char *name[] = {
      "Illegal month",
      "January", "February", "March",
      "April", "May", "June",
      "July", "August", "September",
      "October", "November", "December"};

  return (n < 1 || n > 12) ? name[0] : name[n];
}

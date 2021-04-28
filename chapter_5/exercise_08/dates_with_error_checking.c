#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

int main(void)
{
  char months[13][10] = {
      {0},
      {"January"},
      {"February"},
      {"March"},
      {"April"},
      {"May"},
      {"June"},
      {"July"},
      {"August"},
      {"September"},
      {"October"},
      {"November"},
      {"December"}};

  int year = 1999;
  int yearday = 71;
  int month, day;

  month = day = 0;

  month_day(year, yearday, &month, &day);

  if (day && month)
  {
    printf("Day %d of the year %d is %s %d.\n", yearday, year, months[month], day);
  }

  if (day && month)
  {
    printf("%s %d %d is the %d day of the year\n", months[month], day, year, day_of_year(year, month, day));
  }
}

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

// day_of_year: set day of year from month & day
int day_of_year(int year, int month, int day)
{
  int i, leap;

  leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

  if (month < 1 || month > 12)
  {
    printf("error: impossible month value (%i)\n", month);
    return -1;
  }
  else if (day > daytab[leap][month])
  {
    printf("error: impossible day value (%i)\n", month);
    return -1;
  }

  for (i = 1; i < month; i++)
  {
    day += daytab[leap][i];
  }

  return day;
}

// month_day: set month, day from day of year
void month_day(int year, int yearday, int *pmonth, int *pday)
{
  int i, leap;

  leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

  if (yearday < 1 || yearday > ((leap) ? 366 : 365))
  {
    printf("error: impossible yearday value (%i)\n", yearday);
    return;
  }

  for (i = 1; yearday > daytab[leap][i]; i++)
  {
    yearday -= daytab[leap][i];
  }

  *pmonth = i;
  *pday = yearday;
}

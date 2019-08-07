#include <stdio.h>
#include <stdlib.h>
typedef struct calendar
{
	int year, month, day;
}Calendar;

Calendar* select_min(Calendar *Day1, Calendar *Day2)
{
	if (Day1->year > Day2->year)
		return Day2;
	else if (Day1->year < Day2->year)
		return Day1;

	if (Day1->month > Day2->month)
		return Day2;
	else if (Day1->month < Day2->month)
		return Day1;

	if (Day1->day > Day2->day)
		return Day2;
	else if (Day1->day < Day2->day)
		return Day1;

	return Day1;

}
int main() {

	Calendar num[2];
	int i;

	for (i = 0; i<2; i++)
		scanf("%d/%d/%d", &(num[i].year), &(num[i].month), &(num[i].day));

	Calendar *n = select_min(num + 0, num + 1);

	printf("%d/%d/%d", n->year,n->month,n->day);

}
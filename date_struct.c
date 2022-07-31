/*
 ============================================================================
 Name        : date_struct.c
 Author      : Menna Saeed 
 Date	     : 31/7/2022
 Copyright   : Your copyright notice
 ============================================================================
 */

#include <stdio.h>
#define MAX_NUMBER_OF_DAYS_PER_MONTH 31
#define MAX_NUMBER_OF_MONTHS_PER_YEAR 12
#define MAX_NUMBER_OF_DAYS_PER_YEAR 365
struct date
{
	int day;
	int month;
	int year;
}current,new;

int main ()
{
	printf ("Enter today's day: ");
	scanf("%d",&current.day);
	printf ("\nEnter current month: ");
	scanf("%d",&current.month);
	printf ("\nEnter current year: ");
	scanf("%d",&current.year);

	//printing today's date
	printf("\n\nToday's date is: %d/%d/%d\n",current.day,current.month,current.year);

	//adding requested number of days to the current date
	int add_days,add;
	printf("\nEnter the required number of days to be added: ");
	scanf("%d",&add_days);

	if (add_days>=MAX_NUMBER_OF_DAYS_PER_YEAR)
	{
	    add=add_days-MAX_NUMBER_OF_DAYS_PER_YEAR;
	}
	if (current.day+add>MAX_NUMBER_OF_DAYS_PER_MONTH)
	{
		int day=(current.day+add)-MAX_NUMBER_OF_DAYS_PER_MONTH;
		if (day>MAX_NUMBER_OF_DAYS_PER_MONTH)
		{
			new.day=add%MAX_NUMBER_OF_DAYS_PER_MONTH;

		}
		else
		{
			new.day=day;
		}
	}
	else
	{
		new.day=current.day+add;
	}

if (add_days==MAX_NUMBER_OF_DAYS_PER_YEAR)
{
    new.month=current.month;
    new.year=current.year+1;
}
else{
	int month=(add_days/MAX_NUMBER_OF_DAYS_PER_YEAR)+current.month;
	if (month>MAX_NUMBER_OF_MONTHS_PER_YEAR)
	{
		new.month=month-MAX_NUMBER_OF_MONTHS_PER_YEAR;
	}
else
{
    new.month=month;
    new.year=(add/MAX_NUMBER_OF_DAYS_PER_YEAR)+current.year;
}
}


	printf("\nAdding %d days results in a new date as: %d/%d/%d",add_days,new.day,new.month,new.year);
}

/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Month 9 will be represented as 09.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
};
struct date
{
	int d, m, y;
};
int leapCount(date d)
{
	int years = d.y;
	
	if (d.m <= 2)
		years--;
	
	return (years / 4 - years / 100 + years / 400);
}
int countDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int getNumberOfDays(date dt1, date dt2)
{
	long int n1 = dt1.y * 365 + dt1.d;
	for (int i = 0; i<dt1.m - 1; i++)
		n1 += countDays[i];
	n1 += leapCount(dt1);


	long int n2 = dt2.y * 365 + dt2.d;
	for (int i = 0; i<dt2.m - 1; i++)
		n2 += countDays[i];
	n2 += leapCount(dt2);

	return (n2 - n1 - 1);
}
int between_days(struct node *date1head, struct node *date2head){
	if (date1head==NULL||date2head==NULL)
		return -1;
	int index = 0;
	int d1, m1, y1, d2, m2, y2;
	d1 = d2 = m1 = m2 = y1 = y2 = 0;
	struct node *temp;
	temp = date1head;
	while (temp != NULL)
	{
		if (index == 0 || index == 1)
		{
			d1 = d1 * 10 + temp->data;
		}
		if (index == 2 || index == 3)
		{
			m1 = m1 * 10 + temp->data;
		}
		if (index >= 4 && index <= 7)
		{
			y1 = y1 * 10 + temp->data;
		}
		index++;
		temp = temp->next;

	}
	temp = date2head;
	index = 0;
	while (temp != NULL)
	{
		if (index == 0 || index == 1)
		{
			d2 = d2 * 10 + temp->data;
		}
		if (index == 2 || index == 3)
		{
			m2 = m2 * 10 + temp->data;
		}
		if (index >= 4 && index <= 7)
		{
			y2 = y2 * 10 + temp->data;
		}
		index++;
		temp = temp->next;
	}

	if (d1 < 1 || d2 < 1 || d1>31 || d2>31 || m1 < 1 || m2 < 1 || m1>12 || m2>12)
		return -1;

	struct date date1, date2;
	date1.d = d1;
	date1.m = m1;
	date1.y = y1;
	date2.d = d2;
	date2.m = m2;
	date2.y = y2;
	return getNumberOfDays(date1, date2);
}
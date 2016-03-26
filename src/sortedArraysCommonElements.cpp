/*
OVERVIEW: You are given 2 bank statements that are ordered by date. 
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int compare1(char* x, char *date);
struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A==NULL ||B==NULL)
	return NULL;
	else
	{
		int i, j;
		for (i = 0; i < ALen;i++)
		for (j = 0; i < BLen;j++)
		if (compare1(A[i].date, B[j].date) == 0)
			return A;
		else
			return NULL;
	}

}
int compare1(char* x, char *date)
{
	int day1, day2, month1, month2, year1, year2;
	day1 = (date[0] - '0') * 10 + (date[1] - '0');
	month1 = (date[3] - '0') * 10 + (date[4] - '0');
	year1 = (date[6] - '0') * 1000 + (date[7] - '0') * 100 + (date[8] - '0') * 10 + (date[9] - '0');
	day2 = (x[0] - '0') * 10 + (x[1] - '0');
	month2 = (x[3] - '0') * 10 + (x[4] - '0');
	year2 = (x[6] - '0') * 1000 + (x[7] - '0') * 100 + (x[8] - '0') * 10 + (x[9] - '0');
	if ((day1 == day2) && (month1 == month2) && (year1 == year2))
		return 0;
	else
		return -1;
}
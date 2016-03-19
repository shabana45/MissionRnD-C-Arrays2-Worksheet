/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/
#include <stdio.h>
#include <conio.h>
struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int compare(char* x, char *date);
int checkDate(struct transaction *Arr, char *date, int len);
int countGreaterNumbers(struct transaction *Arr, int len, char *date)
{
	int j = checkDate(Arr, date, len);
	if (j == -1 || j == len - 1)
		return 0;
	else
		return (len - j - 1);
}
int checkDate(struct transaction *Arr, char *date, int len){
	int cnt = 0, i;
	int y=-1;
	for (i = 0; i < len; i++)
	{
		if (compare(Arr[i].date, date) == 0){
			cnt++;
			y = i;
		}
	}
	if (cnt == len||y==-1)
		return -1;
	else
		return y;
}
int compare(char* x, char *date)
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


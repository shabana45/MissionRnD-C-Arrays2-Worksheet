/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
}temp;
void charSwap(struct transaction *a, struct transaction *b);
int cmp(char* x, char *date);
struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A == NULL || B == NULL)
		return NULL;
	else
	{
		int n = ALen + BLen, k = 0;
		struct transaction *C = (struct transaction*)calloc((ALen + BLen), sizeof(struct transaction));
		for (int i = 0; i < ALen; i++)
			C[k++] = A[i];
		for (int i = 0; i < BLen; i++)
			C[k++] = B[i];
		for (int i = 0; i < n; i++)
		{
			for (int j = i; j < n; j++){
				if (cmp(C[i].date, C[j].date) == 1){
					printf("X");
					charSwap(&C[i], &C[j]);
				}
			}
		}
		return C;
	}
}
void charSwap(struct transaction *a, struct transaction *b){
	struct transaction temp = *a;
	*a = *b;
	*b = temp;

}

int cmp(char* x, char *date)
	{
	int day1, day2, month1, month2, year1, year2;
	day1 = (date[0] - '0') * 10 + (date[1] - '0');
	month1 = (date[3] - '0') * 10 + (date[4] - '0');
	year1 = (date[6] - '0') * 1000 + (date[7] - '0') * 100 + (date[8] - '0') * 10 + (date[9] - '0');
	day2 = (x[0] - '0') * 10 + (x[1] - '0');
	month2 = (x[3] - '0') * 10 + (x[4] - '0');
	year2 = (x[6] - '0') * 1000 + (x[7] - '0') * 100 + (x[8] - '0') * 10 + (x[9] - '0');
	if (year1 == year2){
		if (month1 == month2){
			if (day1 == day2)
				return 0;
			else if (day1 < day2)
				return 1;
			else
				return 2;
		}
		else if (month1 < month2)
			return 1;
		else
			return 2;
	}
	else if (year1 < year2)
		return 1;
	else
		return 2;
}
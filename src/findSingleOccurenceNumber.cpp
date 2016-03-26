/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
There are better ways of solving the problem than a brute-force solution which is of O(n^2)
complexity .
*/
struct ele
{
	int count, index, val;
};
int findSingleOccurenceNumber(int *A, int len) {
	if (A == '\0')
		return -1;
	int a0, a1, a2;
	a0 = a1 = a2 = 0;
	for (int i = 0; i < len; ++i) {
		int r0, r1, r2;
		int x = A[i];
		r0 = a0&x; r1 = a1&x; r2 = a2&x;
		a0 = (a0^r0) | r2;
		a1 = (a1^r1) | (x^r1^r2);
		a2 = (a2^r2) | r1;
	}
	return a1;
	}

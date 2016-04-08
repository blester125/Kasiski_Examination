#include "gcd.h"

int findGCD(int nums[], int length) {
	int i;
	int gcd = nums[length - 1];
	for (i = length - 2; i >= 0; i--) {
		gcd = GCD(nums[i], gcd);
	}
	return gcd;
}

int GCD(int a, int b) {
	int c;
	while ( a != 0 ) {
		c = a; 
		a = b % a;  
		b = c;
	}
	return b;
}

int countCleanDivisions(int nums[], int length, int num) {
	int i, total;
	total = 0;
	for (i = 0; i < length; i++) {
		if (nums[i] % num == 0) {
			total++;
		}
	}
	return total;
}
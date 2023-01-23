#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int get_cycle_number(int n)
{
	int static count = 1;

	if (n == 1) {
		printf("%d\n", n);
		return count;
	}

	else {
		printf("%d ", n);
		count++;

		if (n % 2 == 0)
			get_cycle_number(n / 2);
		else 
			get_cycle_number(n * 3 + 1);
	}
}

int main(void)
{
	int num;

	scanf("%d", &num);
	printf("%d ", get_cycle_number(num));
}
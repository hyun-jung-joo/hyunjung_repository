#include <stdio.h>
void pick(char item[], int n, int* picked, int m, int toPick) 
{
	int i;
	int lastIndex, smallest;
	int index;

	if (toPick == 0) {
		for (i = 0; i < m; i++) {
			index = picked[i];
			printf("%c ", item[index]);
		}
		printf("\n");
		return;
	}

	lastIndex = m - toPick - 1;
	if(toPick == m)
		smallest = 0;
	else
		smallest = picked[lastIndex] + 1;

	for (i = smallest; i < n; i++) {
		picked[lastIndex + 1] = i;
		pick(item, n, picked, m, toPick - 1);
	}
}

int main(void)
{
	char item[] = "ABCDEFG";
	int picked[3];

	pick(item, 7, picked, 3, 3);
}
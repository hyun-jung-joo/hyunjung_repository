#include <stdio.h>

#define WIDTH 10
#define HEIGHT 10
int screen[WIDTH][HEIGHT] = {
	-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
	-1,-1, 0, 0,-1,-1,-1, 0,-1,-1,
	-1,-1,-1, 0, 0, 0, 0, 0,-1,-1,
	-1,-1,-1, 0,-1,-1,-1,-1,-1,-1,
	-1,-1,-1, 0, 0, 0, 0, 0,-1,-1,
	-1,-1,-1, 0,-1, 0,-1,-1,-1,-1,
	-1,-1,-1, 0,-1, 0,-1,-1,-1,-1,
	-1,-1,-1, 0,-1, 0, 0, 0,-1,-1,
	-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
	-1,-1,-1,-1,-1,-1,-1,-1,-1,-1
};

int flood_fill_counter(int x, int y, int count)
{
	//int num;
	if (screen[x][y] == 0)
	{
		screen[x][y] = ++count;
		count = flood_fill_counter(x, y + 1, count);
		count = flood_fill_counter(x + 1, y, count);
		count = flood_fill_counter(x, y - 1, count);
		count = flood_fill_counter(x - 1, y, count);
		return count;
	}
	return count;
}

void draw_screen()
{
	int i, j;
	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < WIDTH; j++)
			printf("%2d ", screen[i][j]);
		printf("\n");
	}
}

int main(void)
{
	draw_screen();
	printf("\n");
	flood_fill_counter(4, 3, 0);
	draw_screen();
}

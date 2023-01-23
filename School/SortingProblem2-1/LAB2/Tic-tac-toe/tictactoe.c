#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define BOARD_SIZE 3

int winCheck(char b[][BOARD_SIZE], int r, int c)
{
	int i;
	int j;
	int count = 1;
	char target = b[r][c];

	i = c - 1;
	while (i != -1 && b[r][i] == target) {
		count++;
		i--;
	}

	i = c + 1;
	while (i != BOARD_SIZE && b[r][i] == target) {
		count++;
		i++;
	}

	if (count == BOARD_SIZE)
		return 1;

	count = 1;
	i = r - 1;
	while (i != -1 && b[i][c] == target) {
		count++;
		i--;
	}

	i = r + 1;
	while (i != BOARD_SIZE && b[i][c] == target) {
		count++;
		i++;
	}

	if (count == BOARD_SIZE)
		return 1;

	count = 1;

	i = r - 1;
	j = c - 1;
	while (i != -1 && j != -1 && b[i][j] == target) {
		count++;
		i--;
		j--;
	}

	i = r + 1;
	j = c + 1;
	while (i != BOARD_SIZE && j != BOARD_SIZE && b[i][j] == target) {
		count++;
		i++;
		j++;
	}

	if (count == BOARD_SIZE)
		return 1;

	count = 1;

	i = r + 1;
	j = c - 1;
	while (i != BOARD_SIZE && j != -1 && b[i][j] == target) {
		count++;
		i++;
		j--;
	}

	i = r - 1;
	j = c + 1;
	while (i != -1 && j != BOARD_SIZE && b[i][j] == target) {
		count++;
		i--;
		j++;
	}

	if (count == BOARD_SIZE)
		return 1;

	return 0;
}

void display(char b[][BOARD_SIZE])
{
	int i, j;
	printf("     ");
	for (i = 0; i < BOARD_SIZE; i++)
		printf("%2d", i);
	printf("\n ---------------------\n");
	for (i = 0; i < BOARD_SIZE; i++) {
		printf("%3d |", i);
		for (j = 0; j < BOARD_SIZE; j++)
			printf(" %c", b[i][j]);
		printf("\n");
	}
}

int main(void)
{
	char board[BOARD_SIZE][BOARD_SIZE];
	char turn = 'X';
	int r, c;
	int i, j;
	int count;
	int win;
	for (i = 0; i < BOARD_SIZE; i++)
		for (j = 0; j < BOARD_SIZE; j++)
			board[i][j] = ' ';

	count = 1;
	display(board);

	do
	{
		printf("Player %c(행 열):", turn);
		scanf("%d %d", &r, &c);

		if (board[r][c] == ' ') {

			board[r][c] = turn;
			display(board);


			if (win = winCheck(board, r, c)) {
				printf("Player %c wins!", turn);
				break;
			}
			turn = (turn == 'X' ? 'O' : 'X'); // turn 바꾸기 - turn이 X면 O 로, 다른것이면 X로
			count++;
		}

	} while (count <= BOARD_SIZE * BOARD_SIZE);

	if (!win)
		printf("Nobody wins!\n");
}
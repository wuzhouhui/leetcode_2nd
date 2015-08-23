#include <string.h>

static int avail(char **board, int row, int col)
{
	static char nums[9];
	int	i, j;

	memset(nums, 0, sizeof(nums));
	for (i = 0; i < 9; i++)
		if (board[row][i] == '.')
			continue;
		else
			nums[board[row][i] - '1']++;
	for (i = 0; i < 9; i++)
		if (nums[i] > 1)
			return(0);

	memset(nums, 0, sizeof(nums));
	for (i = 0; i < 9; i++)
		if (board[i][col] == '.')
			continue;
		else
			nums[board[i][col] - '1']++;
	for (i = 0; i < 9; i++)
		if (nums[i] > 1)
			return(0);

	row /= 3;
	col /= 3;
	memset(nums, 0, sizeof(nums));
	for (i = row * 3; i < row * 3 + 3; i++)
		for (j = col * 3 ; j < col * 3 + 3; j++)
			if (board[i][j] == '.')
				continue;
			else
				nums[board[i][j] - '1']++;
	for (i = 0; i < 9; i++)
		if (nums[i] > 1)
			return(0);
	return(1);
}

static int do_solve(char **board, int n)
{
	int	i, j, k;

	if (n >= 81)
		return(1);

	for (i = n / 9; i < 9; i++) {
		if (i == n / 9)
			j = n % 9;
		else
			j = 0;
		for (; j < 9; j++)
			if (board[i][j] == '.')
				break;
		if (j < 9)
			break;
	}
	if (i >= 9)
		return(1);

	for (k = '1'; k <= '9'; k++) {
		board[i][j] = k;
		if (!avail(board, i, j))
			continue;
		if (do_solve(board, i * 9 + j + 1))
			return(1);
	}
	board[i][j] = '.';
	return(0);
}

void solveSudoku(char **board, int boardRowSize, int boardColSize)
{
	(void)do_solve(board, 0);
	return;
}

#include <stdio.h>

int main(void)
{
	int	i;

	char r1[] = "..9748...";
	char r2[] = "7........";
	char r3[] = ".2.1.9...";
	char r4[] = "..7...24.";
	char r5[] = ".64.1.59.";
	char r6[] = ".98...3..";
	char r7[] = "...8.3.2.";
	char r8[] = "........6";
	char r9[] = "...2759..";

	char *argv[] = {
		r1, r2, r3, r4, r5, r6, r7, r8, r9,
	};
	solveSudoku(argv, 9, 9);

	for (i = 0; i < 9; i++)
		printf("%s\n", argv[i]);

	return(0);
}

#include <string.h>

#ifndef bool
#define bool int
#endif

bool isValidSudoku(char **board, int boardRowSize, int boardColSize)
{
	char nums[9];
	int	i, j, k, l;

	for (i = 0; i < 9; i++) {
		memset(nums, 0, sizeof(nums));
		for (j = 0; j < 9; j++)
			if (board[i][j] == '.')
				continue;
			else
				nums[board[i][j] - '1']++;
		for (j = 0; j < 9; j++)
			if (nums[j] > 1)
				return(0);
	}

	for (i = 0; i < 9; i++) {
		memset(nums, 0, sizeof(nums));
		for (j = 0; j < 9; j++)
			if (board[j][i] == '.')
				continue;
			else
				nums[board[j][i] - '1']++;
		for (j = 0; j < 9; j++)
			if (nums[j] > 1)
				return(0);
	}

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			memset(nums, 0, sizeof(nums));
			for (k = 3 * i; k < 3 * i + 3; k++) {
				for (l = 3 * j; l < 3 * j + 3; l++)
					if (board[k][l] == '.')
						continue;
					else
						nums[board[k][l] - '1']++;
			}
			for (k = 0; k < 9; k++)
				if (nums[k] > 1)
					return(0);
		}
	}
	return(1);
}

int main(void)
{
}

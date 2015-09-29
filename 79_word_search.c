#include <string.h>

#ifndef bool
#define bool int
#endif

#define MAXLEN	100

static char occupy[MAXLEN][MAXLEN];

static int do_exist(char **board, int row, int col, int r, int c, char *word)
{
	if (!*word)
		return(1);

	if (r < 0 || r >= row || c < 0 || c >= col)
		return(0);
	if (board[r][c] != *word)
		return(0);
	if (occupy[r][c])
		return(0);
	occupy[r][c] = 1;
	if (do_exist(board, row, col, r + 1, c, word + 1))
		return(1);
	if (do_exist(board, row, col, r - 1, c, word + 1))
		return(1);
	if (do_exist(board, row, col, r, c + 1, word + 1))
		return(1);
	if (do_exist(board, row, col, r, c - 1, word + 1))
		return(1);
	occupy[r][c] = 0;
	return(0);
}

bool exist(char **board, int boardRowSize, int boardColSize, char *word)
{
	int	i, j;

	memset(occupy, 0, sizeof(occupy));
	for (i = 0; i < boardRowSize; i++) {
		for (j = 0; j < boardColSize; j++) {
			if (do_exist(board, boardRowSize, boardColSize,
					i, j, word))
				return(1);
		}
	}
	return(0);
}

#include <stdio.h>

int main(int argc, char *argv[])
{
	char	*r0 = "ABCE";
	char	*r1 = "SFCS";
	char	*r2 = "ADEE";
	char	*board[] = { r0, r1, r2 };
	printf("%d\n", exist(board, 3, 4, argv[1]));
	return(0);
}

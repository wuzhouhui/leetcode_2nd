#include <stdlib.h>

#define testbit(bit, i, j)	(bit[i][j >> 3] & (1 << (j & 7)))
#define setbit(bit, i, j)	(bit[i][j >> 3] |= (1 << (j & 7)))
#define clrbit(bit, i, j)	(bit[i][j >> 3] &= ~(1 << (j & 7)))

static int dead(int **board, int rowsz, int colsz, int row, int col)
{
	int	i, j, k;

	k = 0;
	for (i = row - 1; i <= row + 1; i++)
		for (j = col - 1; j <= col + 1; j++) {
			if (i < 0 || i >= rowsz || j < 0 || j >= colsz)
				continue;
			if (board[i][j])
				k++;
		}
	k--;
	if (k < 2 || k > 3)
		return(1);
	else
		return(0);
}

static int live(int **board, int rowsz, int colsz, int row, int col)
{
	int	i, j, k;

	k = 0;
	for (i = row - 1; i <= row + 1; i++)
		for (j = col - 1; j <= col + 1; j++) {
			if (i < 0 || i >= rowsz || j < 0 || j >= colsz)
				continue;
			if (board[i][j])
				k++;
		}
	if (k == 3)
		return(1);
	else
		return(0);
}

void gameOfLife(int **board, int boardRowSize, int boardColSize)
{
	char	**board2;
	int	t, i, j;

	board2 = malloc(boardRowSize * sizeof(char *));
	t = (boardColSize + 7) >> 3;
	for (i = 0; i < boardRowSize; i++)
		board2[i] = calloc(t, sizeof(char));
	for (i = 0; i < boardRowSize; i++)
		for (j = 0; j < boardColSize; j++) {
			if (board[i][j]) {
				if (dead(board, boardRowSize, boardColSize, i,
						j))
					clrbit(board2, i, j);
				else
					setbit(board2, i, j);
			} else {
				if (live(board, boardRowSize, boardColSize, i,
						j))
					setbit(board2, i, j);
				else
					clrbit(board2, i, j);
			}
		}
	for (i = 0; i < boardRowSize; i++)
		for (j = 0; j < boardColSize; j++) {
			if (board[i][j] && !testbit(board2, i, j))
				board[i][j] = 0;
			else if (!board[i][j] && testbit(board2, i, j))
				board[i][j] = 1;
		}
}

int main(void)
{
}

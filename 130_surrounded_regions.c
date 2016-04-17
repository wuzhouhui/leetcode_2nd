static void trans(char **board, int rowsz, int colsz, int r, int c)
{
	if (r < 0 || r >= rowsz || c < 0 || c >= colsz || board[r][c] != 'O')
		return;
	board[r][c] = '#';
	if (c != 0 && c != colsz - 1) {
		trans(board, rowsz, colsz, r - 1, c);
		trans(board, rowsz, colsz, r + 1, c);
	}
	if (r != 0 && r != rowsz - 1) {
		trans(board, rowsz, colsz, r, c - 1);
		trans(board, rowsz, colsz, r, c + 1);
	}
}

void solve(char **board, int boardRowSize, int boardColSize)
{
	int	i, j;

	for (i = 0; i < boardRowSize; i++) {
		if (board[i][0] == 'O')
			trans(board, boardRowSize, boardColSize, i, 0);
		if (board[i][boardColSize - 1] == 'O')
			trans(board, boardRowSize, boardColSize, i,
					boardColSize - 1);
	}
	for (i = 0; i < boardColSize; i++) {
		if (board[0][i] == 'O')
			trans(board, boardRowSize, boardColSize, 0, i);
		if (board[boardRowSize - 1][i] == 'O')
			trans(board, boardRowSize, boardColSize,
					boardRowSize - 1, i);
	}
	for (i = 0; i < boardRowSize; i++)
		for (j = 0; j < boardColSize; j++)
			if (board[i][j] == 'O')
				board[i][j] = 'X';
	for (i = 0; i < boardRowSize; i++)
		for (j = 0; j < boardColSize; j++)
			if (board[i][j] == '#')
				board[i][j] = 'O';
}

int main(void)
{
}

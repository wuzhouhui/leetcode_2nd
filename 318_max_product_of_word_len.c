#include <string.h>

struct lenbit {
	int	wordbit;
	int	len;
};

static int bit[] = {
	1 << 0, 1 << 1, 1 << 2, 1 << 3,
	1 << 4, 1 << 5, 1 << 6, 1 << 7,
	1 << 8, 1 << 9, 1 << 10, 1 << 11,
	1 << 12, 1 << 13, 1 << 14, 1 << 15,
	1 << 16, 1 << 17, 1 << 18, 1 << 19,
	1 << 20, 1 << 21, 1 << 22, 1 << 23,
	1 << 24, 1 << 25,
};

int maxProduct(char **words, int wordsSize)
{
	int	max, t;
	int	i, j;
	struct lenbit	wordbit[wordsSize];

	for (i = 0; i < wordsSize; i++) {
		wordbit[i].wordbit = 0;
		for (j = 0; words[i][j]; j++)
			wordbit[i].wordbit |= bit[words[i][j] - 'a'];
		wordbit[i].len = j;
	}
	max = 0;
	for (i = 0; i < wordsSize - 1; i++) {
		for (j = i + 1; j < wordsSize; j++) {
			if (wordbit[i].wordbit & wordbit[j].wordbit)
				continue;
			t = wordbit[i].len * wordbit[j].len;
			if (t > max)
				max = t;
		}
	}
	return(max);
}

#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("%d\n", maxProduct(argv + 1, argc - 1));
	return(0);
}

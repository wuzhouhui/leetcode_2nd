/*
 * accepted, but too slow.
 */
#include <string.h>
#include <stdlib.h>

static int *res, maxp, p;

static void add_ans(int n)
{
	if (!res) {
		maxp = 8;
		p = 0;
		res = malloc(maxp * sizeof(int));
	}
	if (p >= maxp) {
		maxp += 8;
		res = realloc(res, maxp * sizeof(int));
	}
	res[p++] = n;
	return;
}

static int match(char *word, char *s)
{
	while (*word && (*word == *s)) {
		word++;
		s++;
	}
	return(*word ? 0 : 1);
}

int *findSubstring(char *s, char **words, int wordsSize, int *returnSize)
{
	int	i, j, k, slen, wordlen;
	int	occupy[wordsSize];

	if (!wordsSize) {
		*returnSize = 0;
		return(0);
	}

	res = 0;
	p = 0;
	slen = strlen(s);
	wordlen = strlen(words[0]);
	for (i = 0; (slen - i) >= wordsSize * wordlen; i++) {
		memset(occupy, 0, sizeof(occupy));
		for (j = 0; j < wordsSize; j++) {
			for (k = 0; k < wordsSize; k++)
				if (!occupy[k] &&
						match(words[k], s + i + j * wordlen)) {
					occupy[k] = 1;
					break;
				}
			if (k >= wordsSize)
				break;
		}
		if (j >= wordsSize)
			add_ans(i);
	}

	*returnSize = p;
	return(res);
}

#include <stdio.h>

int main(void)
{
	char	*words[] = { "a", "b" };
	int	*res, n;

	res = findSubstring("aaa", words, 2, &n);
	while (n-- > 0)
		printf("%d\n", res[n]);
	return(0);
}

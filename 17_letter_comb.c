#include <stdlib.h>
#include <string.h>

#define STEP	16

static char	**ans, *oneperm;
static int	p, maxp, l;

static char *alphas[] = {
	"",
	"",
	"abc",
	"def",
	"ghi",
	"jkl",
	"mno",
	"pqrs",
	"tuv",
	"wxyz",
};

static void add_ans(void)
{
	if (oneperm[0] == 0)
		return;
	if (ans == NULL) {
		maxp = STEP;
		p = 0;
		ans = malloc(maxp * sizeof(char *));
	}
	if (p >= maxp) {
		maxp += STEP;
		ans = realloc(ans, maxp * sizeof(char *));
	}
	ans[p] = malloc(l);
	strcpy(ans[p], oneperm);
	p++;
}

static void do_comb(char *digits, int level)
{
	int	i;

	if (*digits == 0) {
		oneperm[level] = 0;
		add_ans();
		return;
	}
	if (*digits == '0' || *digits == '1') {
		do_comb(digits + 1, level);
		return;
	}
	for (i = 0; alphas[(*digits) - '0'][i]; i++) {
		oneperm[level] = alphas[(*digits) - '0'][i];
		do_comb(digits + 1, level + 1);
	}
	return;
}

char **letterCombinations(char *digits, int *returnSize)
{
	ans = 0;
	p   = 0;
	l = strlen(digits) + 1;
	oneperm = malloc(l);
	do_comb(digits, 0);
	*returnSize = p;
	free(oneperm);
	return(ans);
}

#include <stdio.h>

int main(int argc, char *argv[])
{
	int	n, i;
	char	**res;

	res = letterCombinations(argv[1], &n);
	for (i = 0; i < n; i++) 
		printf("%s\n", res[i]);
	return(0);
}

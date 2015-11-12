#include <stdlib.h>
#include <string.h>

#define STEP 8

static char ***res;
static int *col, p, maxp;
static struct part {
	int start;
	int len;
} *part;

static void add_ans(char *s, int n)
{
	int	i;

	if (!res) {
		maxp = STEP;
		res = malloc(maxp * sizeof(char **));
		col = malloc(maxp * sizeof(int));
	}
	if (p >= maxp) {
		maxp += STEP;
		res = realloc(res, maxp * sizeof(char **));
		col = realloc(col, maxp * sizeof(int));
	}
	res[p] = malloc(n * sizeof(char *));
	col[p] = n;
	for (i = 0; i < n; i++)
		res[p][i] = strndup(s + part[i].start, part[i].len);
	p++;
}

static int is_pal(char *s, int start, int end)
{
	while (start < end) {
		if (s[start++] == s[end--])
			continue;
		else
			return(0);
	}
	return(1);
}

static void do_part(char *s, int len, int level, int start)
{
	int	i;

	if (s[start] == 0) {
		add_ans(s, level);
		return;
	}

	part[level].start = start;
	for (i = start; i < len; i++) {
		if (!is_pal(s, start, i))
			continue;
		part[level].len = i - start + 1;
		do_part(s, len, level + 1, i + 1);
	}
}

char ***partition(char *s, int **columnSizes, int *returnSize)
{
	int len;

	len = strlen(s);
	if (len == 0) {
		*columnSizes = NULL;
		*returnSize = 0;
		return(NULL);
	}

	res = NULL;
	maxp = p = 0;
	col = NULL;
	part = calloc(len, sizeof(struct part));
	do_part(s, len, 0, 0);
	free(part);
	*columnSizes = col;
	*returnSize = p;
	return(res);
}

#include <stdio.h>

int main(void)
{
	int	*col, n;
	char ***res = partition("aab", &col, &n);
	return(0);
}

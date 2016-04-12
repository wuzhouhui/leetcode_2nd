#include <stdlib.h>

static int intcmp(const void *a, const void *b)
{
	return(*(int *)b - *(int *)a);
}

int hIndex(int *citations, int citationsSize)
{
	int	res, i;

	qsort(citations, citationsSize, sizeof(citations[0]), intcmp);
	for (res = i = 0; i < citationsSize; i++)
		if (citations[i] >= i + 1) {
			res++;
			continue;
		}
	return(res);
}

int main(void)
{
}

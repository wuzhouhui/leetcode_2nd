#include <string.h>
#include <stdlib.h>
#include <stdio.h>

static int intlen(int n)
{
	int	r;
	r = 0;
	do {
		n /= 10;
		r++;
	} while (n);
	return(r);
}

static int intcmp(const void *a, const void *b)
{
	static char s1[32], s2[32];
	int	i;

	sprintf(s1, "%d%d", *(int *)a, *(int *)b);
	sprintf(s2, "%d%d", *(int *)b, *(int *)a);
	for (i = 0; s1[i]; i++) {
		if (s1[i] > s2[i])
			return(-1);
		else if (s1[i] < s2[i])
			return(1);
	}
	return(0);
}

char *largestNumber(int *nums, int numsSize)
{
	if (!numsSize)
		return(strdup("0"));

	char	*res;
	int	sz, len;

	qsort(nums, numsSize, sizeof(nums[0]), intcmp);
	if (nums[0] == 0)
		return(strdup("0"));
	res = malloc(sizeof(*res));
	res[0] = 0;
	sz = 1;
	while (numsSize--) {
		len = intlen(*nums);
		sz += len;
		res = realloc(res, sz * sizeof(*res));
		sprintf(res, "%s%d", res, *nums);
		nums++;
	}
	return(res);
}

#include <stdio.h>

int main(int argc, char *argv[])
{
	int	x[] = { 0, 0, };
	printf("%s\n", largestNumber(x, sizeof(x) / sizeof(x[0])));
	return(0);
}

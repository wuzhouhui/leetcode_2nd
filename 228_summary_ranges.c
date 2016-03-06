#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define STEP 8

static char **res;
static int maxsz;

static void add_ans(int start, int end, int *p)
{
	static char buf[32];

	if (res == NULL) {
		maxsz = STEP;
		*p = 0;
		res = malloc(maxsz * sizeof(res[0]));
	}
	if (*p >= maxsz) {
		maxsz += STEP;
		res = realloc(res, maxsz * sizeof(res[0]));
	}
	if (start != end)
		snprintf(buf, sizeof(buf), "%d->%d", start, end);
	else
		snprintf(buf, sizeof(buf), "%d", start);
	res[*p] = strdup(buf);
	(*p)++;
}

char **summaryRanges(int *nums, int numsSize, int *returnSize)
{
	int	i, flag, start, end;

	i = 0;
	flag = 0;
	res = NULL;
	*returnSize = 0;
	for (i = 0; i < numsSize; i++) {
		if (flag == 0) {
			start = end = nums[i];
			flag = 1;
			continue;
		}
		if (nums[i] == nums[i - 1] + 1) {
			end = nums[i];
			continue;
		}
		add_ans(start, end, returnSize);
		start = end = nums[i];
	}

	if (flag)
		add_ans(start, end, returnSize);
	return(res);
}

int main(void)
{
	return(0);
}

#include <stdlib.h>

static int cmp(const void *a, const void *b)
{
	return(*(int *)a - *(int *)b);
}

int threeSumClosest(int *nums, int numsSize, int target)
{
	long long int mindiff, diff;
	int	tmp, sum, start, mid, end;

	qsort(nums, numsSize, sizeof(int), cmp);
	sum = nums[0] + nums[1] + nums[2];
	mindiff = llabs(sum - target);
	for (start = 0; start + 2 < numsSize; start++) {
		mid = start + 1;
		end = numsSize - 1;
		while (mid < end) {
			tmp = nums[start] + nums[mid] + nums[end];
			if (tmp < target)
				mid++;
			else if (tmp > target)
				end--;
			else
				return(tmp);
			diff = llabs(tmp - target);
			if (diff < mindiff) {
				mindiff = diff;
				sum = tmp;
			}
		}
	}
	return(sum);
}

#include <stdio.h>

int main(void)
{
	int	x[] = { -1, 2, 1, -4 };
	printf("%d\n", threeSumClosest(x, 4, 1));
	return(0);
}

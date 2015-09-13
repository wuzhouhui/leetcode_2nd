int removeDuplicates(int *nums, int numsSize)
{
	int	i, j, c;

	c = 0;
	j = -1;
	for (i = 0; i < numsSize; i++) {
		if (i == 0) {
			nums[++j] = nums[i];
			c = 1;
			continue;
		}
		if (nums[i] != nums[j]) {
			nums[++j] = nums[i];
			c = 1;
			continue;
		}
		if (c < 2) {
			nums[++j] = nums[i];
			c++;
			continue;
		}
	}
	return(j + 1);
}

#include <stdio.h>

int main(void)
{
	int	i, n;
	int	x[] = { 1, 2, 2};
	n = removeDuplicates(x, 3);
	for (i = 0; i < n; i++)
		printf("%d ", x[i]);
	printf("\n");
	return(0);
}

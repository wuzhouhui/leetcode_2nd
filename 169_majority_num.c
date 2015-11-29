int majorityElement(int *nums, int numsSize)
{
	int	i, c, n;

	n = nums[0];
	c = 1;
	for (i = 1; i < numsSize; i++) {
		if (nums[i] == n)
			c++;
		else if (--c == 0) {
			n = nums[i];
			c = 1;
		}
	}
	return(n);
}

#include <stdio.h>

int main(void)
{
	int	x[] = { 1, 1, 2, 2, 3, 3, 2, 2 , 2};
	printf("%d\n", majorityElement(x, sizeof(x) / sizeof(x[0])));
	return(0);
}

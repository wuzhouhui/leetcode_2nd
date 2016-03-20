#include <string.h>

int numSquares(int n)
{
	unsigned int nums[n + 1];
	int	i, j, t1, t2;

	memset(nums, 0xff, sizeof(nums));
	for (i = 1; i * i <= n; i++)
		nums[i * i] = 1;
	for (i = 1; i <= n; i++) {
		for (j = 0; i + j * j <= n; j++) {
			t1 = i + j * j;
			t2 = nums[i] + 1;
			if (t2 < nums[t1])
				nums[t1] = t2;
		}
	}
	return(nums[n]);
}

#include <stdio.h>

int main(void)
{
	int	i;
	for (i = 1; i < 15; i++)
		printf("%d\n", numSquares(i));
	return(0);
}

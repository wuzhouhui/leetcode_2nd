int jump(int *nums, int numsSize)
{
	int	i, max, next, res, p, t;

	if (numsSize < 2)
		return(0);

	p = 0;
	res = 0;
	while (1) {
		max = p;
		for (i = 1; i <= nums[p]; i++) {
			t = p + i;
			if (t >= numsSize - 1)
				return(res + 1);
			if (nums[t] == 0)
				continue;
			t = t + nums[t];
			if (t > max) {
				max = t;
				next = p + i;
			}
		}
		p = next;
		res++;
	}
	return(0);
}

#include <stdio.h>

int main(void)
{
	int	x[] = { 3, 2, 1 };
	printf("%d\n", jump(x, 3));
	return(0);
}

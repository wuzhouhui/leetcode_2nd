#ifndef bool
#define bool int
#endif

bool canJump(int *nums, int numsSize)
{
	if (numsSize < 2)
		return(1);

	int	max, p, t, next, i;

	p = 0;
	while (1) {
		max = -1;
		for (i = 1; i <= nums[p]; i++) {
			t = p + i;
			if (t >= numsSize - 1)
				return(1);
			t += nums[t];
			if (t > max) {
				max = t;
				next = p + i;
			}
		}
		if (max < 0)
			return(0);
		p = next;
	}
	return(0);
}

int main(void)
{
}

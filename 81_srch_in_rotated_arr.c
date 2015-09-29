#ifndef bool
#define bool int
#endif

bool search(int *nums, int numsSize, int target)
{
	if (!numsSize)
		return(0);

	int	l, r, m;
	l = 0;
	r = numsSize - 1;
	while (l <= r) {
		m = (l + r) / 2;
		if (nums[m] == target)
			return(1);
		if (nums[l] < nums[m]) {
			if (nums[l] <= target && target < nums[m])
				r = m - 1;
			else
				l = m + 1;
		} else if (nums[l] > nums[m]) {
			if (nums[m] < target && target <= nums[r])
				l = m + 1;
			else
				r = m - 1;
		} else {
			l++;
		}
	}
	return(0);
}

int main(void)
{
}

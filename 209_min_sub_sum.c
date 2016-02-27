int minSubArrayLen(int s, int *nums, int numsSize)
{
	int	left, right, t, min, l;

	if (!numsSize)
		return(0);

	left = right = 0;
	t = 0;
	min = 0;
	while (right < numsSize) {
		t += nums[right];
		while (t < s && (right + 1) < numsSize) {
			right++;
			t += nums[right];
		}
		if (t < s)
			return(min);
		while (left <= right) {
			t -= nums[left];
			if (t < s) {
				t += nums[left];
				break;
			}
			left++;
		}
		l = right - left + 1;
		if (min == 0)
			min = l;
		else if (l < min)
			min = l;
		right++;
	}
	return(min);
}

int main(void)
{
	int	x[] = { 2, 3, 1, 2, 4, 3, };
	return(minSubArrayLen(7, x, sizeof(x) / sizeof(x[0])));
}

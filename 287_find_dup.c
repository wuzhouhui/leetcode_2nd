int findDuplicate(int *nums, int numsSize)
{
	int	down, up, mid, i, k;

	down = 1;
	up = numsSize;
	while (down + 1 != up) {
		mid = (down + up) / 2;
		k = 0;
		for (i = 0; i < numsSize; i++)
			if (nums[i] <= mid && nums[i] >= down)
				k++;
		if (k <= (mid - down + 1))
			down = mid;
		else
			up = mid;
	}
	mid = k = 0;
	for (i = 0; i < numsSize; i++) {
		if (nums[i] == down)
			mid++;
		else if (nums[i] == up)
			k++;
	}
	if (k > mid)
		return(up);
	else
		return(down);
}

int main(void)
{
}

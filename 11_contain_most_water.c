int maxArea(int *height, int heightSize)
{
	if (heightSize <= 1)
		return(0);

	int	max, tmp;
	int	left, right;

	max = 0;
	left = 0;
	right = heightSize - 1;
	while (left < right) {
		if (height[left] < height[right]) {
			tmp = height[left] * (right - left);
			if (tmp > max)
				max = tmp;
			tmp = height[left];
			while (left < right && height[left] <= tmp)
				left++;
			continue;
		}

		tmp = height[right] * (right - left);
		if (tmp > max)
			max = tmp;
		tmp = height[right];
		while (left < right && height[right] <= tmp)
			right--;
		continue;
	}
	return(max);
}

int main(void)
{
}

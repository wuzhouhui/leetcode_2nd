int trap(int *height, int heightSize)
{
	if (heightSize < 3)
		return(0);

	int	leftmax[heightSize], rightmax[heightSize];
	int	i, max, h;

	max = height[0];
	for (i = 1; i < (heightSize - 1); i++) {
		leftmax[i] = max;
		if (height[i] > max)
			max = height[i];
	}
	max = height[heightSize - 1];
	for (i = heightSize - 2; i > 0; i--) {
		rightmax[i] = max;
		if (height[i] > max)
			max = height[i];
	}

	max = 0;
	for (i = 1; i < (heightSize - 1); i++) {
		h = leftmax[i] < rightmax[i] ? leftmax[i] : rightmax[i];
		if (h > height[i])
			max += h - height[i];
	}
	return(max);
}

#include <stdio.h>

int main(void)
{
	int x[] = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
	printf("%d\n", trap(x, 12));
	return(0);
}

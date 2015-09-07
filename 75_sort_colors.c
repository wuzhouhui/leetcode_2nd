#define RED	0
#define WHITE	1
#define BLUE	2

void sortColors(int *nums, int numsSize)
{
	int	i;
	static int c[3];

	c[0] = c[1] = c[2] = 0;
	for (i = 0; i < numsSize; i++)
		c[nums[i]]++;
	i = 0;
	while (c[RED]) {
		nums[i++] = RED;
		c[RED]--;
	}
	while (c[WHITE]) {
		nums[i++] = WHITE;
		c[WHITE]--;
	}
	while (c[BLUE]) {
		nums[i++] = BLUE;
		c[BLUE]--;
	}
}

int main(void)
{
}

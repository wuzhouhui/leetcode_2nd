#include <stdlib.h>
#include <string.h>

static void reverse(int *x, int n)
{
	int	i, t;

	for (i = 0; i < n / 2; i++) {
		t = x[i];
		x[i] = x[n - i - 1];
		x[n - i - 1] = t;
	}
}

int *plusOne(int *digits, int digitsSize, int *returnSize)
{
	int	i, c;
	int	*sum;

	sum = malloc((digitsSize + 1) * sizeof(int));
	memcpy(sum, digits, digitsSize * sizeof(int));
	reverse(sum, digitsSize);
	c = 1;
	for (i = 0; i < digitsSize; i++) {
		sum[i] += c;
		if (sum[i] > 9) {
			sum[i] -= 10;
			c = 1;
		} else {
			c = 0;
			break;
		}
	}
	if (c)
		sum[digitsSize++] = c;
	reverse(sum, digitsSize);
	*returnSize = digitsSize;
	return(sum);
}

int main(void)
{
}

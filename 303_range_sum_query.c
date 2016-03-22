#include <stdlib.h>

struct NumArray {
	int	*sumarr;
	int	*ptr;
	int	len;
};

struct NumArray *NumArrayCreate(int *nums, int numsSize)
{
	struct NumArray *numarr;
	int	i;

	numarr = malloc(sizeof(*numarr));
	numarr->len = numsSize;
	numarr->ptr = malloc((numsSize + 1) * sizeof(nums[0]));
	numarr->ptr[0] = 0;
	numarr->sumarr = numarr->ptr + 1;
	for (i = 0; i < numsSize; i++)
		numarr->sumarr[i] = nums[i] + numarr->sumarr[i - 1];
	return(numarr);
}

int sumRange(struct NumArray *numArray, int i, int j)
{
	return(numArray->sumarr[j] - numArray->sumarr[i - 1]);
}

void NumArrayFree(struct NumArray *numArray)
{
	free(numArray->ptr);
	free(numArray);
}

#include <stdio.h>

int main(void)
{
	int x[] = { -2, 0, 3, -5, 2, -1 };
	struct NumArray *p = NumArrayCreate(x, sizeof(x) / sizeof(x[0]));
	printf("%d %d %d\n", sumRange(p, 0, 2), sumRange(p, 2, 5),
			sumRange(p, 0, 5));
	NumArrayFree(p);
	return(0);
}

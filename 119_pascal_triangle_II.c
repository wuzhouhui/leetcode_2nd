#include <stdlib.h>

int *getRow(int rowIndex, int *returnSize)
{
	if (rowIndex < 0) {
		*returnSize = 0;
		return(0);
	}

	int	*t1, *t2, *t;
	int	i, j;

	rowIndex++;
	t1 = malloc(rowIndex * sizeof(int));
	t2 = malloc(rowIndex * sizeof(int));
	for (i = 1; i <= rowIndex; i++) {
		for (j = 0; j < i; j++) {
			if (j == 0 || j == i - 1)
				t2[j] = 1;
			else
				t2[j] = t1[j - 1] + t1[j];
		}
		t = t1;
		t1 = t2;
		t2 = t;
	}
	free(t2);
	*returnSize = rowIndex;
	return(t1);
}

#include <stdio.h>

int main(void)
{
	int	i, n, *r;

	r = getRow(0, &n);
	for (i = 0; i < n; i++)
		printf("%d ", r[i]);
	printf("\n");
	return(0);
}

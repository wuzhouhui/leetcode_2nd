#include <stdlib.h>

int minimumTotal(int **triangle, int triangleRowSize, int *triangleColSizes)
{
	int	*sum1, *sum2, *t, i, j;

	if (triangleRowSize <= 0)
		return(0);

	sum1 = malloc(triangleRowSize * sizeof(int));
	sum2 = malloc(triangleRowSize * sizeof(int));
	for (i = 0; i < triangleRowSize; i++) {
		if (i == 0)
			sum2[0] = triangle[0][0];
		else
			for (j = 0; j < i + 1; j++)
				if (j == 0)
					sum2[0] = sum1[0] + triangle[i][j];
				else if (j == i)
					sum2[j] = sum1[j - 1] + triangle[i][j];
				else
					sum2[j] = (sum1[j - 1] < sum1[j] ?
						sum1[j - 1] : sum1[j])
						+ triangle[i][j];
		t = sum1;
		sum1 = sum2;
		sum2 = t;
	}

	j = sum1[0];
	for (i = 0; i < triangleRowSize; i++)
		if (sum1[i] < j)
			j = sum1[i];
	free(sum1);
	free(sum2);
	return(j);
}

int main(void)
{
}

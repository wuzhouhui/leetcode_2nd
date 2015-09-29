#include <string.h>

void merge(int *nums1, int m, int *nums2, int n)
{
	int	t[m + n];
	int	i, j, k;

	i = j = k = 0;
	while (i < m && j < n) {
		if (nums1[i] < nums2[j])
			t[k++] = nums1[i++];
		else
			t[k++] = nums2[j++];
	}
	if (i < m)
		memcpy(t + k, nums1 + i, (m - i) * sizeof(int));
	if (j < n)
		memcpy(t + k, nums2 + j, (n - j) * sizeof(int));
	memcpy(nums1, t, (m + n) * sizeof(int));
	return;
}

int main(void)
{
}

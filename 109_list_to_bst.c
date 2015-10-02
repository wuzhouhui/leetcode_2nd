#include <stdlib.h>

struct ListNode {
	int	val;
	struct ListNode *next;
};

struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

static struct TreeNode *sortedArrayToBST(int *nums, int numsSize)
{
	if (!numsSize)
		return(0);

	int	mid;
	struct TreeNode *root;

	mid = numsSize / 2;
	root = malloc(sizeof(struct TreeNode));
	root->val = nums[mid];
	root->left = sortedArrayToBST(nums, mid);
	root->right = sortedArrayToBST(nums + mid + 1, numsSize - mid - 1);
	return(root);
}

static int *list2arr(struct ListNode *head, int *n)
{
	int	*arr, p, maxp;

	arr = 0;
	*n = 0;
	while (head) {
		if (!arr) {
			maxp = 8;
			arr = malloc(maxp * sizeof(int));
		}
		if (*n >= maxp) {
			maxp += 8;
			arr = realloc(arr, maxp * sizeof(int));
		}
		arr[(*n)++] = head->val;
		head = head->next;
	}
	return(arr);
}

struct TreeNode *sortedListToBST(struct ListNode *head)
{
	int	*arr, n;
	struct TreeNode *root;

	arr = list2arr(head, &n);
	root = sortedArrayToBST(arr, n);
	if (arr)
		free(arr);
	return(root);
}

int main(void)
{
}

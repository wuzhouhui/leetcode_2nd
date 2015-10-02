#include <stdlib.h>

struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct TreeNode *sortedArrayToBST(int *nums, int numsSize)
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

int main(void)
{
}

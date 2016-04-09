#include <limits.h>

struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

static int do_sum(const struct TreeNode *root, int *sum)
{
	if (!root)
		return(0);
	int	left, right, node, t, path;

	left = do_sum(root->left, sum);
	right = do_sum(root->right, sum);
	node = root->val;
	if ((t = root->val + left) > node)
		node = t;
	if ((t = root->val + right) > node)
		node = t;
	path = node;
	if ((t = root->val + left + right) > node)
		node = t;
	if (node > *sum)
		*sum = node;
	return(path);
}

int maxPathSum(struct TreeNode *root)
{
	int	sum = 0;
	if (root) {
		sum = INT_MIN;
		do_sum(root, &sum);
	}
	return(sum);
}

int main(void)
{
}

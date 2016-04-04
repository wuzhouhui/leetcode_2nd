/*
 * too slow, but accept.
 */

struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int rob(struct TreeNode *root)
{
	int	left, right, sum1, sum2;

	if (!root)
		return(0);

	/* get value of root */
	if (root->left)
		left = rob(root->left->left) + rob(root->left->right);
	else
		left = 0;
	if (root->right)
		right = rob(root->right->left) + rob(root->right->right);
	else
		right = 0;
	sum1 = left + right + root->val;

	/* don't get value of root */
	sum2 = rob(root->left) + rob(root->right);

	return(sum1 > sum2 ? sum1 : sum2);
}

int main(void)
{
}

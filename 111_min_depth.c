
struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int minDepth(struct TreeNode *root)
{
	if (!root)
		return(0);
	if (!root->left && !root->right)
		return(1);

	int	h1, h2;

	h1 = minDepth(root->left);
	h2 = minDepth(root->right);

	if (h1 && h2)
		return((h1 > h2 ? h2 : h1) + 1);
	if (h1)
		return(h1 + 1);
	return(h2 + 1);
}

int main(void)
{
}

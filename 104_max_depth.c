
struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int maxDepth(struct TreeNode *root)
{
	if (!root)
		return(0);

	int	hl, hr;

	hl = maxDepth(root->left);
	hr = maxDepth(root->right);
	return((hl > hr ? hl : hr) + 1);
}

int main(void)
{
}

struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct TreeNode *invertTree(struct TreeNode *root)
{
	struct TreeNode *t;

	if (!root)
		return(root);
	t = root->left;
	root->left = root->right;
	root->right = t;
	(void)invertTree(root->left);
	(void)invertTree(root->right);
	return(root);
}

int main(void)
{
}

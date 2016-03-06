struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

static int height(struct TreeNode *root, int lr)
{
	int	h;
	h = 0;
	while (root) {
		h++;
		if (lr)
			root = root->left;
		else
			root = root->right;
	}
	return(h);
}

int countNodes(struct TreeNode *root)
{
	if (!root)
		return(0);
	int	lh, rh;
	lh = height(root, 1);
	rh = height(root, 0);
	if (lh == rh)
		return((1 << lh) - 1);
	return(countNodes(root->left) + countNodes(root->right) + 1);
}

int main(void)
{
}

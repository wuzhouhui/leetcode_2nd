struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

static int now;

static int do_srch(struct TreeNode *root, int k, int *val)
{
	if (!root)
		return(0);
	if (do_srch(root->left, k, val))
		return(1);
	if (++now == k) {
		*val = root->val;
		return(1);
	}
	return(do_srch(root->right, k, val));
}

int kthSmallest(struct TreeNode *root, int k)
{
	now = 0;
	int	val;
	do_srch(root, k, &val);
	return(val);
}

int main(void)
{
}

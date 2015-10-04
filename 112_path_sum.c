
struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

#ifndef bool
#define bool int
#endif

static void do_hassum(struct TreeNode *root, int sum, int cur, int *r)
{
	if (*r || !root)
		return;

	cur += root->val;
	if (!root->left && !root->right) {
		if (sum == cur)
			*r = 1;
		return;
	}
	do_hassum(root->left, sum, cur, r);
	if (!(*r))
		do_hassum(root->right, sum, cur, r);
	return;
}

bool hasPathSum(struct TreeNode *root, int sum)
{
	int	r;

	r = 0;
	do_hassum(root, sum, 0, &r);
	return(r);
}

int main(void)
{
}

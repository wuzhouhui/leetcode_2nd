
struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

#ifndef bool
#define bool int
#endif

static int height(struct TreeNode *root, int *r)
{
	if (!root || !(*r))
		return(0);

	int	h1, h2;

	h1 = height(root->left, r);
	if (!r)
		return(0);
	h2 = height(root->right, r);
	if (!r)
		return(0);
	if ((h1 - h2 > 1) || (h2 - h1 > 1)) {
		*r = 0;
		return(0);
	}
	return((h1 > h2 ? h1 : h2) + 1);
}

bool isBalanced(struct TreeNode *root)
{
	int	r;

	r = 1;
	height(root, &r);
	return(r);
}

int main(void)
{
}

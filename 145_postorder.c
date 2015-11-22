#include <stdlib.h>

struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

static int *res, p, maxp;

static void add(int val)
{
	if (!res) {
		maxp = 8;
		p = 0;
		res = malloc(maxp * sizeof(int));
	}
	if (p >= maxp) {
		maxp += 8;
		res = realloc(res, maxp * sizeof(int));
	}
	res[p++] = val;
}

static void postorder(struct TreeNode *root)
{
	if (!root)
		return;
	postorder(root->left);
	postorder(root->right);
	add(root->val);
}

int *postorderTraversal(struct TreeNode *root, int *returnSize)
{
	res = 0;
	p = 0;
	postorder(root);
	*returnSize = p;
	return(res);
}

int main(void)
{
	return(0);
}

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
		res = malloc(maxp * sizeof(int));
	}
	if (p >= maxp) {
		maxp += 8;
		res = realloc(res, maxp * sizeof(int));
	}
	res[p++] = val;
}

static void inorder(struct TreeNode *root)
{
	if (!root)
		return;
	inorder(root->left);
	add(root->val);
	inorder(root->right);
}

int *inorderTraversal(struct TreeNode *root, int *returnSize)
{
	res = 0;
	p = 0;
	inorder(root);
	*returnSize = p;
	return(res);
}

int main(void)
{
}

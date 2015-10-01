#include <stdlib.h>

#ifndef bool
#define bool int
#endif

struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

static int *trav, p, maxp;

static void add(int v)
{
	if (!trav) {
		maxp = 8;
		trav = malloc(maxp * sizeof(int));
	}
	if (p >= maxp) {
		maxp += 8;
		trav = realloc(trav, maxp * sizeof(int));
	}
	trav[p++] = v;
}

static void inorder(struct TreeNode *root)
{
	if (!root)
		return;
	inorder(root->left);
	add(root->val);
	inorder(root->right);
}

bool isValidBST(struct TreeNode *root)
{
	int	i, ret;

	trav = 0;
	p = 0;
	inorder(root);
	for (i = 1; i < p; i++)
		if (trav[i - 1] >= trav[i]) {
			ret = 0;
			goto out;
		}
	ret = 1;
out:
	if (trav)
		free(trav);
	return(ret);
}

int main(void)
{
}

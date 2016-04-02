#include <stdlib.h>

struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct TreeNode *buildTree(int *preorder, int preorderSize, int *inorder,
		int inorderSize)
{
	if (inorderSize <= 0)
		return(NULL);

	int	i;
	struct TreeNode *root;

	for (i = 0; i < inorderSize; i++)
		if (inorder[i] == preorder[0])
			break;
	root = malloc(sizeof(*root));
	root->val = preorder[0];
	root->left = buildTree(preorder + 1, i, inorder, i);
	root->right = buildTree(preorder + i + 1, inorderSize - i - 1,
			inorder + i + 1, inorderSize - i - 1);
	return(root);
}

int main(void)
{
	int	pre[] = { 1, 2, 3, };
	int	 in[] = { 2, 1, 3, };
	buildTree(pre, 3, in, 3);
	return(0);
}

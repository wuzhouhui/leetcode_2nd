#include <stdlib.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct TreeNode *buildTree(int *inorder, int inorderSize, int *postorder,
		int postorderSize)
{
	if (postorderSize <= 0)
		return(0);

	int	i;
	struct TreeNode *root;

	for (i = 0; i < postorderSize; i++)
		if (inorder[i] == postorder[postorderSize - 1])
			break;
	root = malloc(sizeof(*root));
	root->val = inorder[i];
	root->left = buildTree(inorder, i, postorder, i);
	root->right = buildTree(inorder + i + 1, postorderSize - i - 1,
			postorder + i, postorderSize - i - 1);
	return(root);
}

int main(void)
{
	int	 in[] = { 2, 1, 3, };
	int    post[] = { 2, 3, 1, };
	buildTree(in, 3, post, 3);
	return(0);
}

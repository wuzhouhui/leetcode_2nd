#include <stdlib.h>
#include <string.h>

#define MAX_DEPTH	128

static char path[MAX_DEPTH];

struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

static void do_sum(struct TreeNode *root, int *sum, int depth)
{
	if (!root)
		return;
	path[depth] = root->val + '0';
	if (!root->left && !root->right)
		*sum += atoi(path);
	else {
		do_sum(root->left, sum, depth + 1);
		do_sum(root->right, sum, depth + 1);
	}
	path[depth] = 0;
}

int sumNumbers(struct TreeNode *root)
{
	int	sum;

	sum = 0;
	memset(path, 0, sizeof(path));
	do_sum(root, &sum, 0);
	return(sum);
}

int main(void)
{
}


struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct TreeNode *tail;

static void do_flatten(struct TreeNode *root)
{
	if (!root)
		return;
	struct TreeNode *left = root->left;
	struct TreeNode *right = root->right;
	root->left = 0;
	tail->right = root;
	tail = root;
	do_flatten(left);
	do_flatten(right);
}

void flatten(struct TreeNode *root)
{
	if (!root)
		return;
	struct TreeNode *left = root->left;
	struct TreeNode *right = root->right;
	root->left = 0;
	tail = root;
	do_flatten(left);
	do_flatten(right);
	tail->right = 0;
}

int main(void)
{
}

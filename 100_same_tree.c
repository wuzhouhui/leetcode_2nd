
struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

#ifndef bool
#define bool int
#endif

static void is_same(struct TreeNode *p, struct TreeNode *q, int *r)
{
	if (!(*r))
		return;
	if ((!p && q) || (p && !q)) {
		*r = 0;
		return;
	}
	if (!p && !q)
		return;
	is_same(p->left, q->left, r);
	if (p->val != q->val) {
		*r = 0;
		return;
	}
	is_same(p->right, q->right, r);
}

bool isSameTree(struct TreeNode *p, struct TreeNode *q)
{
	int	r;

	r = 1;
	is_same(p, q, &r);
	return(r);
}

int main(void)
{
}

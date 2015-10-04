
struct TreeLinkNode {
	int	val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
};

void connect(struct TreeLinkNode *root)
{
	if (!root)
		return;

	struct TreeLinkNode *par, *t;

	par = root;
	root->next = 0;
	root = root->left;
	while (root) {
		t = root;
		while (par) {
			t->next = par->right;
			t = t->next;
			if (!(par = par->next)) {
				t->next = 0;
			} else {
				t->next = par->left;
				t = t->next;
			}
		}
		par = root;
		root = root->left;
	}
	return;
}

int main(void)
{
}

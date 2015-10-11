
struct TreeLinkNode {
	int	val;
	struct TreeLinkNode *left, *right, *next;
};

void connect(struct TreeLinkNode *root)
{
	if (!root)
		return;

	struct TreeLinkNode *p1, *p2, *parent, *head;

	root->next = 0;
	parent = root;
	while (parent) {
		p1 = 0;
		while (parent) {
			if ((p1 = parent->left))
				break;
			if ((p1 = parent->right)) {
				parent = parent->next;
				break;
			}
			parent = parent->next;
		}
		if (!p1)
			break;
		head = p1;

		while (1) {
			p2 = 0;
			while (parent && !p2) {
				if (parent->left && parent->left != p1) {
					p2 = parent->left;
					break;
				}
				if (parent->right) {
					p2 = parent->right;
					parent = parent->next;
					break;
				}
				parent = parent->next;
			}
			p1->next = p2;
			p1 = p2;
			if (!p1)
				break;
		}
		parent = head;
	}
}

int main(void)
{
}

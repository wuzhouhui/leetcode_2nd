
#include <stdlib.h>

struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct list {
	struct TreeNode *node;
	struct list *next;
};

static struct list *stack;

static void push(struct TreeNode *node)
{
	struct list *t = malloc(sizeof(*t));
	t->node = node;
	t->next = stack;
	stack = t;
}

static void pop(void)
{
	struct list *t = stack;
	stack = stack->next;
	free(t);
}

static void cp_list(struct list **list)
{
	struct list *t, *head;

	head = NULL;
	while (stack) {
		t = stack;
		stack = stack->next;
		t->next = head;
		head = t;
	}
	*list = head;
}

static void free_list(struct list **list)
{
	struct list *t;
	while (*list) {
		t = *list;
		*list = (*list)->next;
		free(t);
	}
}

static void do_path(struct TreeNode *root, struct TreeNode *p,
		struct list **list)
{
	if (root == NULL)
		return;
	push(root);
	if (root == p) {
		cp_list(list);
		return;
	}
	do_path(root->left, p, list);
	if (*list)
		return;
	do_path(root->right, p, list);
	if (*list)
		return;
	pop();
}

struct TreeNode *lowestCommonAncestor(struct TreeNode *root,
		struct TreeNode *p, struct TreeNode *q)
{
	struct list *l1, *l2, *t1, *t2;
	struct TreeNode *node;

	stack = NULL;
	l1 = l2 = NULL;
	node = NULL;
	do_path(root, p, &l1);
	do_path(root, q, &l2);
	t1 = l1;
	t2 = l2;
	while (t1 && t2) {
		if (t1->node != t2->node)
			break;
		node = t1->node;
		t1 = t1->next;
		t2 = t2->next;
	}
	free_list(&l1);
	free_list(&l2);
	return(node);
}

int main(void)
{
}

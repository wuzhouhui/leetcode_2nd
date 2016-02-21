#include <stdlib.h>

#ifndef bool
#define bool int
#endif

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct stack {
	struct TreeNode *val;
	struct stack *next;
};

struct BSTIterator {
	struct stack *stack;
};

struct BSTIterator *bstIteratorCreate(struct TreeNode *root)
{
	struct BSTIterator *i;
	struct stack *t;

	i = malloc(sizeof(*i));
	i->stack = 0;
	while (root) {
		t = malloc(sizeof(*t));
		t->val = root;
		t->next = i->stack;
		i->stack = t;
		root = root->left;
	}
	return(i);
}

/** @return whether we have a next smallest number */
bool bstIteratorHasNext(struct BSTIterator *iter)
{
	if (!iter)
		return(0);
	return(iter->stack != NULL);
}

/** @return the next smallest number */
int bstIteratorNext(struct BSTIterator *iter)
{
	struct stack *t;
	struct TreeNode *r;
	int	ret;

	if (!iter || !iter->stack)
		return(0);

	t = iter->stack;
	iter->stack = t->next;
	ret = t->val->val;
	r = t->val->right;
	free(t);
	while (r) {
		t = malloc(sizeof(t));
		t->val = r;
		t->next = iter->stack;
		iter->stack = t;
		r = r->left;
	}
	return(ret);
}

/** Deallocates memory previously allocated for the iterator */
void bstIteratorFree(struct BSTIterator *iter)
{
	struct stack *t;

	if (!iter)
		return;
	while (iter->stack) {
		t = iter->stack;
		iter->stack = t->next;
		free(t);
	}
	free(iter);
}

/**
 * Your BSTIterator will be called like this:
 * struct BSTIterator *i = bstIteratorCreate(root);
 * while (bstIteratorHasNext(i)) printf("%d\n", bstIteratorNext(i));
 * bstIteratorFree(i);
 */
int main(void)
{
}

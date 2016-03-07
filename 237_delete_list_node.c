#include <stdlib.h>

struct ListNode {
	int	val;
	struct ListNode *next;
};

void deleteNode(struct ListNode *node)
{
	if (!node || !node->next)
		return;
	struct ListNode **pptr = &node;
	while ((*pptr)->next) {
		(*pptr)->val = (*pptr)->next->val;
		pptr = &(*pptr)->next;
	}
	free(*pptr);
	*pptr = NULL;
}

int main(void)
{
}

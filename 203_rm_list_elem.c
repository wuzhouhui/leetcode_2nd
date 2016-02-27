#include <stdlib.h>

struct ListNode {
	int	val;
	struct ListNode *next;
};

struct ListNode *removeElements(struct ListNode *head, int val)
{
	struct ListNode **pptr, *ptr;
	pptr = &head;

	while (*pptr) {
		if ((*pptr)->val != val) {
			pptr = &(*pptr)->next;
			continue;
		}
		ptr = *pptr;
		*pptr = ptr->next;
		free(ptr);
	}
	return(head);
}

int main(void)
{
}

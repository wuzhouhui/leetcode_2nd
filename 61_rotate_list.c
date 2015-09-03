struct ListNode {
	int	val;
	struct ListNode *next;
};

struct ListNode *rotateRight(struct ListNode *head, int k)
{
	struct ListNode *p, *ptr;
	struct ListNode **pptr;
	int	n;

	for (n = 0, pptr = &head; *pptr; pptr = &(*pptr)->next)
		n++;
	if (!n || !(k %= n))
		return(head);

	for (ptr = head; k > 0; k--)
		ptr = ptr->next;
	for (p = head; ptr->next;) {
		p= p->next;
		ptr = ptr->next;
	}
	ptr->next = head;
	head = p->next;
	p->next = 0;
	return(head);
}

#include <stdlib.h>

int main(void)
{
	struct ListNode *head = malloc(sizeof(struct ListNode));
	head->val = 1;
	head->next = calloc(1, sizeof(struct ListNode));
	head->next->val = 2;
	rotateRight(head, 1);
	return(0);
}

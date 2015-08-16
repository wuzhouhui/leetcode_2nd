#include <stdlib.h>

struct ListNode {
	int	val;
	struct ListNode *next;
};

struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
	struct ListNode **left, **right, *tmp;
	int	i;

	if (n == 1) {
		for (left = &head; (*left)->next; left = &(*left)->next)
			;
		free(*left);
		*left = NULL;
		return(head);
	}

	/* n > 1 */
	for (right = &head, i = 1; i <= (n - 1); i++)
		right = &(*right)->next;
	left = &head;
	while ((*right)->next) {
		right = &(*right)->next;
		left = &(*left)->next;
	}
	tmp = *left;
	*left = tmp->next;
	free(tmp);
	return(head);
}

int main(void)
{
}

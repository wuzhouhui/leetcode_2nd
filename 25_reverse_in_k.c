struct ListNode {
	int	val;
	struct ListNode *next;
};

struct ListNode *reverseKGroup(struct ListNode *head, int k)
{
	if (!k || k == 1 || !head || !head->next)
		return(head);

	struct ListNode **newheadpp, *stack, *newhead, *tmp;
	struct ListNode *start;
	int	i;

	newhead = 0;
	newheadpp = &newhead;
	stack = 0;

	while (head) {
		start = head;
		for (i = 1; i < k; i++)
			if (head)
				head = head->next;
			else 
				break;

		if (!head)
			break;

		head = head->next;
		for (i = 1; i <= k; i++) {
			tmp = start;
			start = start->next;
			tmp->next = stack;
			stack = tmp;
		}
		*newheadpp = stack;
		while (stack->next)
			stack = stack->next;
		newheadpp = &stack->next;
		stack = 0;
	}

	if (start)
		*newheadpp = start;
	return(newhead);
}

#include <stdlib.h>

int main(void)
{
	struct ListNode *head = malloc(sizeof(struct ListNode));
	head->val = 1;
	head->next = malloc(sizeof(struct ListNode));
	head->next->val = 2;
	head->next->next = 0;
	reverseKGroup(head, 2);
	return(0);
}

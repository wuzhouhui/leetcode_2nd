#include <stdlib.h>

struct ListNode {
	int	val;
	struct ListNode *next;
};

struct ListNode *deleteDuplicates(struct ListNode *head)
{
	if (!head || !head->next)
		return(head);

	struct ListNode *prev, *cur;

	prev = head;
	cur = head->next;
	while (cur) {
		if (cur->val == prev->val) {
			prev->next = cur->next;
			free(cur);
			cur = prev->next;
			continue;
		}
		prev = cur;
		cur = cur->next;
	}
	return(head);
}

int main(void)
{
}

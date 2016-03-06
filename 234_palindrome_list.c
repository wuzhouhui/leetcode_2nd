#include <stdlib.h>

#ifndef bool
#define bool int
#endif

struct ListNode {
	int	val;
	struct ListNode *next;
};

bool isPalindrome(struct ListNode *head)
{
	struct ListNode *head2, *t, *t2;
	int	same;

	t = head;
	head2 = NULL;
	while (t) {
		t2 = malloc(sizeof(*t2));
		t2->val = t->val;
		t2->next = head2;
		head2 = t2;
		t = t->next;
	}
	same = 1;
	while (head2) {
		if (head->val != head2->val)
			same = 0;
		head = head->next;
		t = head2;
		head2 = head2->next;
		free(t);
	}
	return(same);
}

int main(void)
{
}

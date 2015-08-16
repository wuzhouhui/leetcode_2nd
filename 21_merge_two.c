#include <stdlib.h>

struct ListNode {
	int	val;
	struct ListNode *next;
};

struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2)
{
	struct ListNode *newhead, *newtail, *t;

	newhead = NULL;
	while (l1 && l2) {
		t = malloc(sizeof(struct ListNode));
		t->next = NULL;
		if (l1->val < l2->val) {
			t->val = l1->val;
			l1 = l1->next;
		} else {
			t->val = l2->val;
			l2 = l2->next;
		}
		if (!newhead) {
			newhead = newtail = t;
		} else {
			newtail->next = t;
			newtail = t;
		}
	}

	while (l1) {
		t = malloc(sizeof(struct ListNode));
		t->next = NULL;
		t->val = l1->val;
		l1 = l1->next;
		if (!newhead) {
			newhead = newtail = t;
		} else {
			newtail->next = t;
			newtail = t;
		}
	}
	while (l2) {
		t = malloc(sizeof(struct ListNode));
		t->next = NULL;
		t->val = l2->val;
		l2 = l2->next;
		if (!newhead) {
			newhead = newtail = t;
		} else {
			newtail->next = t;
			newtail = t;
		}
	}
	return(newhead);
}

int main(void)
{
}

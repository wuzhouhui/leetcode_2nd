#include <stdlib.h>

struct ListNode {
	int	val;
	struct ListNode *next;
};

struct ListNode *deleteDuplicates(struct ListNode *head)
{
	struct ListNode *newhead, *newtail, *tmp, *t;
	int	addable;

	tmp = 0;
	addable = 0;
	newhead = 0;
	while (head) {
		t = head;
		head = head->next;
		t->next = 0;
		if (!tmp) {
			tmp = t;
			addable = 1;
			continue;
		}

		if (tmp->val != t->val) {
			if (addable) {
				if (!newhead) {
					newhead = newtail = tmp;
				} else {
					newtail->next = tmp;
					newtail = tmp;
				}
			} else {
				free(tmp);
			}
			tmp = t;
			addable = 1;
		} else {
			free(tmp);
			tmp = t;
			addable = 0;
		}
	}

	if (tmp && addable) {
		if (!newhead) {
			newhead = newtail = tmp;
		} else {
			newtail->next = tmp;
			newtail = tmp;
		}
	}
	return(newhead);
}

int main(void)
{
}

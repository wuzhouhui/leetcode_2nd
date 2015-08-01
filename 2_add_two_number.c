#include <stdlib.h>

struct ListNode {
	int	val;
	struct ListNode *next;
};

struct ListNode *addTwoNumbers(struct ListNode *l1,
		struct ListNode *l2)
{
	int	c, tmpsum;
	struct ListNode *sum, *tail;

	c = 0;
	sum = NULL;
	while (l1 && l2) {
		tmpsum = l1->val + l2->val + c;
		c = 0;
		if (tmpsum >= 10) {
			c = 1;
			tmpsum -= 10;
		}
		if (sum == NULL) {
			sum = tail = malloc(sizeof(*sum));
			tail->val = tmpsum;
			tail->next = NULL;
		} else {
			tail->next = malloc(sizeof(*sum));
			tail->next->val = tmpsum;
			tail->next->next = NULL;
			tail = tail->next;
		}
		l1 = l1->next;
		l2 = l2->next;
	}
	while (l1) {
		tmpsum = l1->val + c;
		c = 0;
		if (tmpsum >= 10) {
			c = 1;
			tmpsum -= 10;
		}
		if (sum == NULL) {
			sum = tail = malloc(sizeof(*sum));
			tail->val = tmpsum;
			tail->next = NULL;
		} else {
			tail->next = malloc(sizeof(*sum));
			tail->next->val = tmpsum;
			tail->next->next = NULL;
			tail = tail->next;
		}
		l1 = l1->next;
	}
	while (l2) {
		tmpsum = l2->val + c;
		c = 0;
		if (tmpsum >= 10) {
			c = 1;
			tmpsum -= 10;
		}
		if (sum == NULL) {
			sum = tail = malloc(sizeof(*sum));
			tail->val = tmpsum;
			tail->next = NULL;
		} else {
			tail->next = malloc(sizeof(*sum));
			tail->next->val = tmpsum;
			tail->next->next = NULL;
			tail = tail->next;
		}
		l2 = l2->next;
	}
	if (c) {
		tail->next = malloc(sizeof(*sum));
		tail->next->val = 1;
		tail->next->next = NULL;
		tail = tail->next;
	} else if (sum == NULL) {
		sum = malloc(sizeof(*sum));
		sum->val = 0;
		sum->next = NULL;
	}
	return(sum);
}

int main(void)
{
}

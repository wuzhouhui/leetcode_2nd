struct ListNode {
	int	val;
	struct ListNode *next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA,
		struct ListNode *headB)
{
	int	ca, cb, i;
	struct ListNode *p;

	for (ca = 0, p = headA; p; p = p->next)
		ca++;
	for (cb = 0, p = headB; p; p = p->next)
		cb++;
	if (ca < cb) {
		cb -= ca;
		for (i = 1; i <= cb; i++)
			headB = headB->next;
	} else if (ca > cb) {
		ca -= cb;
		for (i = 1; i <= ca; i++)
			headA = headA->next;
	}

	while (headA && headA != headB) {
		headA = headA->next;
		headB = headB->next;
	}
	return(headA);
}

int main(void)
{
}

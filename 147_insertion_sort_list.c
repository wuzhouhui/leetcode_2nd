struct ListNode {
	int	val;
	struct ListNode *next;
};

struct ListNode *insertionSortList(struct ListNode *head)
{
	struct ListNode *p, *next, **hp;

	if (!head || !head->next)
		return(head);

	p = head->next;
	head->next = 0;
	while (p) {
		next = p->next;
		hp = &head;
		while (*hp && p->val > (*hp)->val)
			hp = &(*hp)->next;
		p->next = *hp;
		*hp = p;
		p = next;
	}

	return(head);
}

int main(void)
{
}

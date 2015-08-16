
struct ListNode {
	int	val;
	struct ListNode *next;
};

struct ListNode *swapPairs(struct ListNode *head)
{
	if (!head || !head->next)
		return(head);
	
	struct ListNode *p1, *p2, **prev;

	p1 = head;
	p2 = head->next;
	prev = &head;
	while (p2) {
		*prev = p2;
		p1->next = p2->next;
		p2->next = p1;

		prev = &p1->next;
		if (p1->next)
			p1 = p1->next;
		else 
			break;
		p2 = p1->next;
	}

	return(head);
}

int main(void)
{
}

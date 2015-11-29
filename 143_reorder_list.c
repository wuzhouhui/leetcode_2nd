struct ListNode {
	int	val;
	struct ListNode *next;
};

void reorderList(struct ListNode *head)
{
	int	c, i;
	struct ListNode *p, *h1, *h2, *t;

	for (p = head, c = 0; p; p = p->next)
		c++;

	h1 = 0;
	for (i = 1; i <= c / 2; i++) {
		p = head;
		head = head->next;
		p->next = 0;
		if (!h1)
			h1 = t = p;
		else {
			t->next = p;
			t = p;
		}
	}

	h2 = 0;
	while (head) {
		p = head;
		head = head->next;
		p->next = h2;
		h2 = p;
	}

	head = 0;
	while (h1) {
		p = h1;
		h1 = h1->next;
		if (!head)
			head = t = p;
		else {
			t->next = p;
			t = p;
		}
		t->next = h2;
		t = t->next;
		h2 = h2->next;
	}
	if (c % 2)
		if (!head)
			head = h2;
		else
			t->next = h2;

	return;
}

int main(void)
{
	struct ListNode node = { 1, 0 };
	reorderList(&node);
	return(0);
}

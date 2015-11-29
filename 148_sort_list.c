struct ListNode {
	int	val;
	struct ListNode *next;
};

struct ListNode *sortList(struct ListNode *head)
{
	if (!head || !head->next)
		return(head);

	int	flag;
	struct ListNode *h1, *h2, *t1, *t2, *p;

	h1 = h2 = 0;
	flag = 1;
	while (head) {
		p = head;
		head = head->next;
		p->next = 0;
		if (flag) {
			if (!h1)
				h1 = t1 = p;
			else {
				t1->next = p;
				t1 = p;
			}
		} else {
			if (!h2)
				h2 = t2 = p;
			else {
				t2->next = p;
				t2 = p;
			}
		}
		flag = !flag;
	}

	h1 = sortList(h1);
	h2 = sortList(h2);

	t1 = 0;
	while (h1 && h2) {
		if (h1->val < h2->val) {
			p = h1;
			h1 = h1->next;
			p->next = 0;
		} else {
			p = h2;
			h2 = h2->next;
			p->next = 0;
		}
		if (!t1)
			t1 = t2 = p;
		else {
			t2->next = p;
			t2 = p;
		}
	}

	if (h1)
		if (!t1)
			t1 = t2 = h1;
		else {
			t2->next = h1;
			t2 = p;
		}
	if (h2)

		if (!t1)
			t1 = t2 = h2;
		else {
			t2->next = h2;
			t2 = p;
		}
	return(t1);
}

int main(void)
{
}

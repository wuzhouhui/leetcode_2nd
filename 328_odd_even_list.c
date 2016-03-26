struct ListNode {
	int	val;
	struct ListNode *next;
};

struct ListNode *oddEvenList(struct ListNode *head)
{
	struct ListNode *odd, *even;
	struct ListNode **t1, **t2, *t;
	int	i;

	odd = even = 0;
	t1 = &odd;
	t2 = &even;
	i = 1;
	while (head) {
		t = head;
		head = head->next;
		if (i) {
			*t1 = t;
			t1 = &t->next;
		} else {
			*t2 = t;
			t2 = &t->next;
		}
		i = !i;
	}
	*t2 = 0;
	*t1 = even;
	return(odd);
}

int main(void)
{
}

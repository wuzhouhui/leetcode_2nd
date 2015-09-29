struct ListNode {
	int	val;
	struct ListNode *next;
};

struct ListNode *reverseBetween(struct ListNode *head, int m, int n)
{
	if (!head || !head->next || m == n)
		return(head);

	struct ListNode *stack, *tail, *t, *stack_tail, *tmphead;
	int	i;

	i = 1;
	tmphead = head;
	head = 0;
	stack = 0;
	while (1) {
		t = tmphead;
		if (tmphead)
			tmphead = tmphead->next;
		if (i < m) {
			if (!head) {
				head = tail = t;
			} else {
				tail->next = t;
				tail = t;
			}
		} else if (i <= n) {
			if (!stack)
				stack_tail = t;
			t->next = stack;
			stack = t;
		} else {
			break;
		}
		if (++i > n)
			break;
	}
	if (head)
		tail->next = stack;
	else
		head = stack;
	stack_tail->next = tmphead;
	return(head);
}

int main(void)
{
}

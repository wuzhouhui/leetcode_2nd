struct ListNode {
	int	val;
	struct ListNode *next;
};

struct ListNode *reverseList(struct ListNode *head)
{
	struct ListNode *new, *t;

	new = 0;
	while (head) {
		t = head;
		head = head->next;
		t->next = new;
		new = t;
	}
	return(new);
}

int main(void)
{
}

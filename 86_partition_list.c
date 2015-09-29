struct ListNode {
	int	val;
	struct ListNode *next;
};

struct ListNode *partition(struct ListNode *head, int x)
{
	struct ListNode *lesshead, *lesstail, *greathead, *greattail;
	struct ListNode *t;

	lesshead = greathead = 0;
	while (head) {
		t = head;
		head = head->next;
		t->next = 0;
		if (t->val < x) {
			if (!lesshead) {
				lesshead = lesstail = t;
			} else {
				lesstail->next = t;
				lesstail = t;
			}
		} else {
			if (!greathead) {
				greathead = greattail = t;
			} else {
				greattail->next = t;
				greattail = t;
			}
		}
	}

	if (!lesshead)
		lesshead = greathead;
	else
		lesstail->next = greathead;
	return(lesshead);
}

int main(void)
{
}

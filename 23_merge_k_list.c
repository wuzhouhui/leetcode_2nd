struct ListNode {
	int	val;
	struct ListNode *next;
};

struct ListNode *mergeKLists(struct ListNode **lists, int listsSize)
{
	int	mid;
	struct ListNode *newhead, **headpp;
	struct ListNode *left, *right;

	if (!listsSize)
		return(0);
	if (listsSize == 1)
		return(lists[0]);
	mid = listsSize / 2;

	left = mergeKLists(lists, mid);
	right = mergeKLists(lists + mid, listsSize - mid);

	newhead = 0;
	headpp = &newhead;
	while (left && right) {
		if (left->val < right->val) {
			*headpp = left;
			left = left->next;
			headpp = &(*headpp)->next;
		} else {
			*headpp = right;
			right = right->next;
			headpp = &(*headpp)->next;
		}
	}
	if (left)
		*headpp = left;
	if (right)
		*headpp = right;
	return(newhead);
}

int main(void)
{
}

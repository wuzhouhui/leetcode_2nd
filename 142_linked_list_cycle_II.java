import java.util.*;

class ListNode {
    int val;
    ListNode next;
    ListNode(int x) {
        val = x;
        next = null;
    }
}

class Solution {
    public ListNode detectCycle(ListNode head) {
        Map<ListNode, ListNode> map = new HashMap<>();
        ListNode p = null;
        while (head != null) {
            p = map.get(head);
            if (p != null)
                break;
            else
                map.put(head, head);
            head = head.next;
        }
        return(p);
    }
}

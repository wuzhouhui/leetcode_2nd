import java.util.*;

class RandomListNode {
    int label;
    RandomListNode next, random;
    RandomListNode(int x) { this.label = x; }
}

class Solution {
    public RandomListNode copyRandomList(RandomListNode head) {
        Map<RandomListNode, RandomListNode> map = new HashMap<>();
        RandomListNode newhead = null;
        RandomListNode newtail = null;
        RandomListNode t1 = null;
        RandomListNode t2 = null;

        t1 = head;
        while (t1 != null) {
            t2 = new RandomListNode(t1.label);
            if (newhead == null)
                newhead = newtail = t2;
            else {
                newtail.next = t2;
                newtail = t2;
            }
            map.put(t1, t2);
            t1 = t1.next;
        }

        t1 = head;
        t2 = newhead;
        while (t1 != null) {
            if (t1.random == null)
                t2.random = null;
            else
                t2.random = map.get(t1.random);
            t1 = t1.next;
            t2 = t2.next;
        }
        return newhead;
    }
}

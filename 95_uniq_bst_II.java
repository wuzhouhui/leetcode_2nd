import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

class Solution {
    public List<TreeNode> generateTrees(int n) {
        return do_gen(1, n);
    }

    private List<TreeNode> do_gen(int start, int end) {
        List<TreeNode> roots = new LinkedList<>();
        if (start > end) {
            roots.add(null);
            return roots;
        }

        for (int i = start; i <= end; i++) {
            List<TreeNode> lefts = do_gen(start, i - 1);
            List<TreeNode> rights = do_gen(i + 1, end);
            Iterator<TreeNode> iterL = lefts.iterator();
            while (iterL.hasNext()) {
                TreeNode left = iterL.next();
                Iterator<TreeNode> iterR = rights.iterator();
                while (iterR.hasNext()) {
                    TreeNode node = new TreeNode(i);
                    node.left = left;
                    node.right = iterR.next();
                    roots.add(node);
                }
            }
        }
        return roots;
    }
}

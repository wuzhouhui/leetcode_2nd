import java.util.*;

class UndirectedGraphNode {
    int label;
    List<UndirectedGraphNode> neighbors;
    UndirectedGraphNode(int x) {
        label = x;
        neighbors = new ArrayList<UndirectedGraphNode>();
    }
}

class Solution {
    private Map<UndirectedGraphNode, UndirectedGraphNode>
        map = new HashMap<>();
    public UndirectedGraphNode cloneGraph(UndirectedGraphNode node) {
        if (node == null)
            return null;

        UndirectedGraphNode newnode = map.get(node);
        if (newnode != null)
            return newnode;

        newnode = new UndirectedGraphNode(node.label);
        map.put(node, newnode);
        for (int i = 0; i < node.neighbors.size(); i++)
            newnode.neighbors.add(cloneGraph(node.neighbors.get(i)));
        return newnode;
    }
}

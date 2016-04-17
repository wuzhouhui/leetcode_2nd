import java.util.*;

class Solution {
    public List<Integer> diffWaysToCompute(String input) {
        List<Integer> res = new LinkedList<>();
        for (int i = 0; i < input.length(); i++) {
            char c = input.charAt(i);
            if (c != '+' && c != '-' && c != '*')
                continue;
            List<Integer> l = diffWaysToCompute(input.substring(0, i));
            List<Integer> r = diffWaysToCompute(input.substring(i + 1));
            for (int j = 0; j < l.size(); j++) {
                for (int k = 0; k < r.size(); k++) {
                    switch (c) {
                    case '+': res.add(l.get(j) + r.get(k)); break;
                    case '-': res.add(l.get(j) - r.get(k)); break;
                    case '*': res.add(l.get(j) * r.get(k)); break;
                    }
                }
            }
        }
        if (res.size() == 0)
            res.add(Integer.parseInt(input));
        return res;
    }
}

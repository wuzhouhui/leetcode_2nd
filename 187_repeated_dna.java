import java.util.*;

class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
        List<String> res = new LinkedList<>();
        HashSet<Integer> tmp = new HashSet<>();
        HashSet<Integer> added = new HashSet<>();
        int hash = 0;
        for (int i = 0; i < s.length(); i++) {
            switch (s.charAt(i)) {
            case 'A': hash = (hash << 2) + 0; break;
            case 'T': hash = (hash << 2) + 1; break;
            case 'C': hash = (hash << 2) + 2; break;
            case 'G': hash = (hash << 2) + 3; break;
            }
            if (i < 9)
                continue;
            hash &= (1 << 20) - 1;
            if (tmp.contains(hash) && !added.contains(hash)) {
                added.add(hash);
                res.add(s.substring(i - 9, i + 1));
            } else
                tmp.add(hash);
        }
        return res;
    }
}

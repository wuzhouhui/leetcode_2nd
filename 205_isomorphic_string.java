import java.util.*;

class Solution {
    public boolean isIsomorphic(String s, String t) {
        Map<Character, Character> map = new HashMap<>();
        char    c;

        for (int i = 0; i < s.length(); i++) {
            if (map.containsKey(s.charAt(i))) {
                c = map.get(s.charAt(i));
                if (c != t.charAt(i))
                    return false;
            } else {
                map.put(s.charAt(i), t.charAt(i));
            }
        }
        map.clear();
        for (int i = 0; i < t.length(); i++) {
            if (map.containsKey(t.charAt(i))) {
                c = map.get(t.charAt(i));
                if (c != s.charAt(i))
                    return false;
            } else {
                map.put(t.charAt(i), s.charAt(i));
            }
        }
        return true;
    }
}

import java.util.*;

class Solution {
    public String minWindow(String s, String t) {
        Map<Character, Integer> map = new HashMap<>();
        for (int i = 0; i < t.length(); i++) {
            Integer n = map.get(t.charAt(i));
            if (n == null)
                map.put(t.charAt(i), -1);
            else
                map.put(t.charAt(i), --n);
        }
        int left = t.length();
        int min = s.length() + 1;
        int start = 0, end = 0;

        int i, j;
        i = j = 0;
        Integer n;
        while (j < s.length()) {
            n = map.get(s.charAt(j));
            if (n == null) {
                j++;
                continue;
            }
            map.put(s.charAt(j), ++n);
            if (n <= 0)
                left--;
            if (left != 0) {
                j++;
                continue;
            }
            while (i <= j) {
                n = map.get(s.charAt(i));
                if (n == null) {
                    i++;
                    continue;
                }
                map.put(s.charAt(i), --n);
                if (n >= 0) {
                    i++;
                    continue;
                }
                left++;
                n = j - i + 1;
                if (n < min) {
                    min = n;
                    start = i;
                    end = j;
                }
                i++;
                break;
            }
            if (i > j)
                return t;
            j++;
        }
        if (min <= s.length())
            return s.substring(start, end + 1);
        else
            return "";
    }
    public static void main(String[] args) {
        System.out.println(new Solution().minWindow(args[0], args[1]));
    }
}

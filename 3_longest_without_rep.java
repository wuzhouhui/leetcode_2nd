import java.util.*;

class Solution {
    public int lengthOfLongestSubstring(String s) {
        if (s.length() < 2)
            return s.length();

        Map<Character, Integer> map = new HashMap<>();
        map.put(s.charAt(0), 1);
        int maxlenth = 1;
        int left = 0;
        int right = 1;
        while (right < s.length()) {
            Integer n = map.get(s.charAt(right));
            if (n == null || n == 0) {
                int tmp = right - left + 1;
                if (tmp > maxlenth)
                    maxlenth = tmp;
                map.put(s.charAt(right), 1);
                right++;
            } else {
                map.put(s.charAt(right), 2);
                while (left < right) {
                    n = map.get(s.charAt(left));
                    if (--n == 0) {
                        map.put(s.charAt(left), 0);
                        left++;
                    } else {
                        map.put(s.charAt(left), 1);
                        left++;
                        break;
                    }
                }
                right++;
            }
        }
        return maxlenth;
    }
    public static void main(String[] args) {
        System.out.println(new Solution().lengthOfLongestSubstring(args[0]));
    }
}

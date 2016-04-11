import java.util.*;

class Solution {
    public int longestConsecutive(int[] nums) {
        int max = 0;
        HashSet<Integer> set = new HashSet<>();

        for (int i = 0; i < nums.length; i++)
            set.add(nums[i]);
        for (int i = 0; i < nums.length; i++) {
            int c = 1;
            int t = nums[i] - 1;
            while (set.contains(t)) {
                c++;
                set.remove(t);
                t--;
            }
            t = nums[i] + 1;
            while (set.contains(t)) {
                c++;
                set.remove(t);
                t++;
            }
            if (c > max)
                max = c;
        }
        return max;
    }
}

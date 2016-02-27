import java.util.*;

class Solution {
    public static int[] square = { 0, 1, 4, 9, 16, 25, 36, 49, 64, 81 };
    public boolean isHappy(int n) {
        Map<Integer, Integer> map = new HashMap<>();
        int sum;
        while (true) {
            sum = 0;
            while (n != 0) {
                sum += Solution.square[n % 10];
                n /= 10;
            }
            if (map.containsKey(sum))
                return false;
            if (sum == 1)
                return true;
            map.put(sum, sum);
            n = sum;
        }
    }
}

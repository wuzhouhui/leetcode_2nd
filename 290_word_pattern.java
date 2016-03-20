import java.util.*;

class Solution {
    public boolean wordPattern(String pattern, String str) {
        Map<Character, String> map = new HashMap<>();
        String[] words = str.split(" ");
        for (int i = 0; i < pattern.length(); i++) {
            if (i >= words.length)
                return false;
            Character c = pattern.charAt(i);
            if (!map.containsKey(c)) {
                map.put(c, words[i]);
            } else {
                if (!words[i].equals(map.get(c)))
                    return false;
            }
        }

        Map<String, Character> map1 = new HashMap<>();
        for (int i = 0; i < words.length; i++) {
            if (i >= pattern.length())
                return false;
            if (!map1.containsKey(words[i])) {
                map1.put(words[i], pattern.charAt(i));
            } else {
                if (map1.get(words[i]) != pattern.charAt(i))
                    return false;
            }
        }
        return true;
    }
}

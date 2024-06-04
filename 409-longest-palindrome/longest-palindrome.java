class Solution {
    public int longestPalindrome(String s) {
        int n = s.length();
        int[] lowerCount = new int[26]; 
        int[] upperCount = new int[26]; 

        for (int i = 0; i < n; i++) {
            char ch = s.charAt(i);
            if (Character.isLowerCase(ch)) {
                lowerCount[ch - 'a']++;
            } else {
                upperCount[ch - 'A']++;
            }
        }

        int count = 0;
        for (int freq : lowerCount) {
            count += 2 * (freq / 2); 
        }
        for (int freq : upperCount) {
            count += 2 * (freq / 2);
        }

        if (n > count) {
            count++;
        }

        return count;
    }
}

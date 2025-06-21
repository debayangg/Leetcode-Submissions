class Solution {
    public int minimumDeletions(String word, int k) {
        HashMap<Character, Integer> freq = new HashMap<>();
        for (char c : word.toCharArray()) {
            freq.put(c, freq.getOrDefault(c, 0) + 1);
        }

        List<Integer> freqs = new ArrayList<>(freq.values());
        int ans = Integer.MAX_VALUE;

        for (int target = 1; target <= 100000; target++) {
            int deletions = 0;
            for (int f : freqs) {
                if (f < target) {
                    deletions += f; // delete all
                } else if (f > target + k) {
                    deletions += f - (target + k); // reduce to (target + k)
                }
                // else: f in [target, target + k] → do nothing
            }
            ans = Math.min(ans, deletions);
        }

        return ans;
    }
}

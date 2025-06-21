class Solution {
    public int minimumDeletions(String word, int k) {
        HashMap<Character, Integer> freqMap = new HashMap<>();
        for (char c : word.toCharArray()) {
            freqMap.put(c, freqMap.getOrDefault(c, 0) + 1);
        }

        List<Integer> freqs = new ArrayList<>(freqMap.values());
        Collections.sort(freqs);  // O(m log m), m ≤ 26

        int totalChars = 0;
        for (int f : freqs) totalChars += f;

        int minDeletions = Integer.MAX_VALUE;

        for (int i = 0; i < freqs.size(); i++) {
            int maxAllowed = freqs.get(i) + k;

            int deletions = 0;
            // Delete all frequencies before i entirely (cannot increase them)
            for (int j = 0; j < i; j++) {
                deletions += freqs.get(j);
            }

            // Delete the extra part of all frequencies > maxAllowed
            for (int j = i + 1; j < freqs.size(); j++) {
                if (freqs.get(j) > maxAllowed) {
                    deletions += freqs.get(j) - maxAllowed;
                }
            }

            minDeletions = Math.min(minDeletions, deletions);
        }

        return minDeletions;
    }
}

class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int n = s1.size();
        int m = s2.size();

        if (n > m) return false;

        vector<int> s1Count(26, 0);
        vector<int> s2Count(26, 0);

        for (int i = 0; i < n; i++) {
            s1Count[s1[i] - 'a']++;
            s2Count[s2[i] - 'a']++;
        }

        int matches = 0;

        for (int i = 0; i < 26; i++) {
            if (s1Count[i] == s2Count[i])
                matches++;
        }

        int l = 0;

        for (int r = n; r < m; r++) {

            if (matches == 26)
                return true;

            int index = s2[r] - 'a';
            s2Count[index]++;

            if (s2Count[index] == s1Count[index])
                matches++;
            else if (s2Count[index] == s1Count[index] + 1)
                matches--;

            index = s2[l] - 'a';
            s2Count[index]--;

            if (s2Count[index] == s1Count[index])
                matches++;
            else if (s2Count[index] == s1Count[index] - 1)
                matches--;

            l++;
        }

        return matches == 26;
    }
};
class Solution {
private: 
    bool checkequal(int a[26], int b[26]) {
        for(int i = 0; i < 26; i++) {
            if(a[i] != b[i]) {
                return false; 
            }
        }
        return true; 
    }

public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;

        int count1[26] = {0}; 
        int count2[26] = {0};

        // Count frequencies for s1 and the first window of s2
        for(int i = 0; i < s1.length(); i++) {
            count1[s1[i] - 'a']++;
            count2[s2[i] - 'a']++;
        }

        // Check if the initial window matches
        if(checkequal(count1, count2)) return true;

        // Slide the window across s2
        for(int i = s1.length(); i < s2.length(); i++) {
            // Add the character entering the window
            count2[s2[i] - 'a']++;
            // Remove the character leaving the window
            count2[s2[i - s1.length()] - 'a']--;

            // Check if the current window is a match
            if(checkequal(count1, count2)) return true;
        }

        return false;
    } 
}; 
class Solution {
public:
    int maxVowels(string s, int k) {
        string vowels = "aeiou";
        int currentVowels = 0;
        for(int i =0; i<k;i++){
            if(vowels.find(s[i]) != string::npos){
                currentVowels++;
            }
        }
        int maxVowels = currentVowels;
        for(int i = k;i<s.length();i++){
            if(vowels.find(s[i]) != string::npos){
                currentVowels++;
            }
            if(vowels.find(s[i-k]) != string::npos){
                currentVowels--;
            }
            if(currentVowels > maxVowels){
                maxVowels = currentVowels;
            }
        }
        return maxVowels;
    }
};
class Solution {
public:
    int hammingDistance(int x, int y) {
        //C++ standard library provides __builtin_popcount, which counts the number of set bits in an integer using hardware acceleration.
        return __builtin_popcount(x^y);
    }
};
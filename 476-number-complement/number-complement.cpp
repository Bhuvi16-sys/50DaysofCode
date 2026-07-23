class Solution {
public:
    int findComplement(int num) {
        // Total bits in unsigned int is 32.
        // Number of active bits = 32 - leading zeros
        int activeBits = 32 - __builtin_clz(num);
        
        // Create mask with `activeBits` ones.
        // (1ULL << activeBits) - 1 produces `activeBits` 1s without overflow.
        unsigned int mask = (1ULL << activeBits) - 1;
        
        return num ^ mask;
    }
};
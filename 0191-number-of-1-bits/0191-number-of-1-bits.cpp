class Solution {
public:
    // time/space: O(8)/O(2 ^ 4)
    int hammingWeight(uint32_t n) {
        // divide and conquer
        int count = 0;
        for (int i = 0; i < 8; i++) {
            count += uint4_bits[n & 0b1111];
            n >>= 4;
        }
        return count;
    }
private:
    // build the pre-computed table for the `4-bit` integers
    const vector<int> uint4_bits = {
        0,      // 0b0000
        1,      // 0b0001
        1,      // 0b0010
        2,      // 0b0011
        1,      // 0b0100
        2,      // 0b0101
        2,      // 0b0110
        3,      // 0b0111
        1,      // 0b1000
        2,      // 0b1001
        2,      // 0b1010
        3,      // 0b1011
        2,      // 0b1100
        3,      // 0b1101
        3,      // 0b1110
        4,      // 0b1111
    };
};
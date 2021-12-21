class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && !(n & (n-1));
    }
};

/*
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && !(n & (n-1));
    }
};

        return n > 0 and n & (n-1) == 0
Time Complexity : O(1)
Space Complexity : O(1)

✔️ Solution - VI (Math)

Only a power of 2 will be able to divide a larger power of 2. Thus, we can take the largest power of 2 for our given range and check if n divides it

C++

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 and (1 << 31) % n == 0;
    }
};
*/
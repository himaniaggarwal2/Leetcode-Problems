class Solution {
public:
    int findComplement(int num) {
        int temp = num;
    int count = 0;
    
    while(temp!=0){  //find count
        temp = temp >> 1;
        count++;
    }
    
    int mask = pow(2, count-1); // to avoid overflow
    mask = mask + (mask-1);
    
    return num ^ mask;
    }
};
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if(sum % 3 != 0) return false;
        int x = sum/3, preSum = 0, count = 0;
        for(int i = 0; i < arr.size(); i++)
        {
            preSum += arr[i];
            if(preSum == x)
                x += sum/3, count++;
        }
        return count >= 3;
    }
};
class Solution {
public:
    int missingNumber(vector<int>& arr) {
        long long n = arr.size() + 1;
        long long total = n * (n + 1) / 2;
        long long sum = 0;

        for(int x : arr)
            sum += x;

        return total - sum;
    }
};

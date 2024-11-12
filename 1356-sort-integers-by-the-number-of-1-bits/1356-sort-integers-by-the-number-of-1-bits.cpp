class Solution {
public:
    // int countdigit(int a) {
    //     int count = 0;
    //     while (a != 0) {
    //         if (a & 1 == 1)
    //             count++;
    //         a >>= 1;
    //     }
    //     return count;
    // }
    vector<int> sortByBits(vector<int>& arr) {
        auto comparator = [&](int& a, int& b) {
            int first = __builtin_popcount(a);
            int second = __builtin_popcount(b);
            if (first == second)
                return a < b;
            return first < second;
        };
        sort(arr.begin(), arr.end(), comparator);
        return arr;
    }
};
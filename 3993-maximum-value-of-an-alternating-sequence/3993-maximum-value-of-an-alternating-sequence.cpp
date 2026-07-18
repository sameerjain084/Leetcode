class Solution {
public:
    long long maximumValue(int n, int s, int m) {

        if (n == 1)
            return s;

        long long peaks = n / 2;

        return max((long long)s,
                   (long long)s + peaks * (m - 1LL) + 1);
    }
};
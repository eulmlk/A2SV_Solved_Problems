class Solution {
public:
    int mySqrt(int x) {
        return getSqrt(x, 0, x / 2 + 1);
    }

private:
    int getSqrt(int x, int left, int right) {
        if (left > right)
            return right;

        int mid = left + (right - left) / 2;
        long square = (long)mid * (long)mid;

        if (square == x)
            return mid;

        if (square > x)
            return getSqrt(x, left, mid - 1);

        return getSqrt(x, mid + 1, right);
    }
};
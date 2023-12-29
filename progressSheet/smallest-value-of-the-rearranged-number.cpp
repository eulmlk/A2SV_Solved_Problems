class Solution {
public:
    long long smallestNumber(long long num) {
        if (num == 0)
            return 0;
        
        if (num < 0)
            return -largestNumber(-num);
        
        int counts[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        while (num) {
            ++counts[num % 10];
            num /= 10;
        }

        long long result = 0;
        int i = 1;
        for (; i < 10; ++i) {
            if (counts[i]) {
                --counts[i];
                result *= 10;
                result += i;
                break;
            }
        }

        while (counts[0]--)
            result *= 10;
        
        while (i < 10) {
            while (counts[i]--) {
                result *= 10;
                result += i;
            }
            ++i;
        }

        return result;
    }

private:
    long long largestNumber(long long num) {
        int counts[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        while (num) {
            ++counts[num % 10];
            num /= 10;
        }

        long long result = 0;
        for (int i = 9; i >= 0; --i) {
            while (counts[i]--) {
                result *= 10;
                result += i;
            }
        }

        return result;
    }
};
#include <iostream>
#include <unordered_map>
using namespace std;

/*
    LeetCode 1742. 盒子中小球的最大数量
*/

class Solution1 {
public:
    int countBalls(int lowLimit, int highLimit) {
        unordered_map<int, int> count;
        for (int i = lowLimit ; i <= highLimit; i++) {
            int sum = 0;
            int tmp = i;
            while(tmp) {
                sum += tmp % 10;
                tmp /= 10;
            }
            count[sum]++;
        }
        auto max = count.begin();
        for (auto i = count.begin(); i != count.end(); i++) {
            if (i->second > max->second) max = i;
        }
        return max->second;
    }
};

class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        int count[45] = {0};
        for (int i = lowLimit ; i <= highLimit; i++) {
            int x = i;
            int sum = 0;
            while(x) {
                sum += x % 10;
                x /= 10;
            }
            count[sum]++;
        }
        int max = 0;
        for (int i = 1; i <= 45; i++) {
            if (count[i] > count[max]) max = i;
        }
        return count[max];
    }
};

int main() {
    
    return 0;
}
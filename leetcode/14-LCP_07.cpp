#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

/*
    LeetCode LCP 07. 传递信息
*/

class Solution1 {
public:
    int ret;
    int numWays(int n, vector<vector<int>>& relation, int k) {
        ret = 0;
        getWays(n, relation, k, 0, 0);
        return ret;
    }

    void getWays(int n, vector<vector<int>>& relation, int k, int index, int count) {
        if (count == k) {
            if (index == n-1) {
                ret++;
            }
            return;
        } else if (count < k) {
            count++;
            for (int i = 0; i < relation.size(); i++) {
                if (relation[i][0] == index) {
                    getWays(n, relation, k, relation[i][1], count);
                }
            }
        }
    }
};

class Solution2 {
public:
    int matrix[10][10];
    int N;

    int dfs(int u, int k) {
        if (k == 0) {
            return (u == N-1) ? 1 : 0; 
        }
        int sum = 0;
        for (int i = 0; i < N; i++) {
            if (matrix[u][i]) {
                sum += dfs(i, k-1);
            }
        }
        return sum;
    }

    int numWays(int n, vector<vector<int>>& relation, int k) {
        memset(matrix, 0, sizeof(matrix));
        for (int i = 0 ; i < relation.size(); i++) {
            int u = relation[i][0];
            int v = relation[i][1];
            matrix[u][v] = 1;
        }
        N = n;
        return dfs(0, k);
    }
};

class Solution {
public:
    vector<int> edges[10];
    int N;

    int dfs(int u, int k) {
        if (k == 0) {
            return (u == N-1) ? 1 : 0; 
        }
        int sum = 0;
        for (int i = 0; i < edges[u].size(); i++) {
            sum += dfs(edges[u][i], k-1);
        }
        return sum;
    }

    int numWays(int n, vector<vector<int>>& relation, int k) {
        N = n;
        for (int i = 0; i < N; i++) {
            edges[i].clear();
        }
        for (int i = 0; i < relation.size(); i++) {
            int u = relation[i][0];
            int v = relation[i][1];
            edges[u].push_back(v);
        }
        return dfs(0, k);
    }
};

int main() {
    
    return 0;
}
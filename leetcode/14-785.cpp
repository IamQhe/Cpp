#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

/*
    LeetCode 785. 判断二分图
*/

class Solution {
public:
    int matrix[100][100];
    int n;
    int color[101];

    bool dfs(int u, bool flag) {
        if (color[u] != 0 ) {
            return color[u] == flag;
        } else {
            color[u] = flag;
            bool ret = true;
            for (int i = 0; i < n; i++) {
                if (matrix[u][i] == 1) {
                    if (!dfs(i, !flag)) {
                        ret = false;
                    }
                }
            }
            return ret;
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        memset(color, false, sizeof(color));
        memset(matrix, 0, sizeof(matrix));
        n = graph.size();
        for (int i = 0; i < n; i++) {
            int size = graph[i].size();
            for (int j = 0; j < size; j++) {
                int u = graph[i][j];
                matrix[i][u] = 1;
            }
        }

        bool flag = true;
        for (int i = 0; i < n; i++) {
            if (color[i] == 0) {
                if (!dfs(i, false)) {
                    flag = false;
                    break;
                }
            }
        }
        return flag;
    }
};

int main() {
    
    return 0;
}
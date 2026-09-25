#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

/*
    LeetCode 547. 省份数量
*/

class Solution1 {
public:
    bool group[201];
    int currentGroup;
    int N;

    void dfs(int u, vector<vector<int>>& isConnected) {
        if (group[u] != 0) return; 
        group[u] = true;
        for (int i = 0; i < N; i++) {
            if (isConnected[u][i] == 1) {
                dfs(i, isConnected);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        N = isConnected.size();
        currentGroup = 0;
        memset(group, 0, sizeof(group));
        for (int i = 0; i < N; i++) {
            if (group[i] == false) {
                dfs(i, isConnected);
                currentGroup++;
            }   
        }
        return currentGroup;
    }
};

class Solution {
public:
    bool color[201];
    int currentGroup;
    int N;
    vector<int> edges[201];

    void dfs(int u) {
        if (color[u] != 0) return; 
        color[u] = true;
        for(int i = 0; i < edges[u].size(); i++) {
            dfs(edges[u][i]);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        N = isConnected.size();
        currentGroup = 0;
        memset(color, false, sizeof(color));
        for(int i = 0; i < N; i++) {
            edges[i].clear();
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (isConnected[i][j]) {
                    edges[i].push_back(j);
                }
            }
        }
        for (int i = 0; i < N; i++) {
            if (color[i] == false) {
                dfs(i);
                currentGroup++;
            }   
        }
        return currentGroup;
    }
};

int main() {
    
    return 0;
}
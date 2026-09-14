#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

/*
    LeetCode 785. 判断二分图
    tips: 判断是否有奇环（环的顶点数为偶数），有则不为二分图
*/

class Solution {
public:
    int color[101];

    bool isBipartite(vector<vector<int>>& graph) {
        memset(color, -1, sizeof(color));
        int n = graph.size();

        while(1) {
            int u = -1;
            for(int i = 0; i < n; i++) {
                if (color[i] == -1) {
                    u = i;
                    break;
                }
            }
            if (u == -1) {
                break;
            }

            color[u] = 0;
            queue<int> q;
            q.push(u);
            while(!q.empty()) {
                u = q.front();
                q.pop();
                for(int i = 0; i < graph[u].size(); i++) {
                    int v = graph[u][i];
                    if (color[v] != -1) {
                        if (color[v] == color[u]) {
                            return false;
                        } 
                    }else {
                        color[v] = 1 - color[u];
                        q.push(v);
                    }
                }
            }
        }
        return true;
    }
};

int main() {
    
    return 0;
}
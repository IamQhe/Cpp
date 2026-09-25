#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
    LeetCode 面试题 16.02. 单词频率
*/

class WordsFrequency {
private:
    unordered_map<string, int> count;

public:
    
    WordsFrequency(vector<string>& book) {
        for (int i = 0; i < book.size(); i++) {
            count[book[i]]++;
        }
    }
    
    int get(string word) {
        return count[word];
    }
};

/**
 * Your WordsFrequency object will be instantiated and called as such:
 * WordsFrequency* obj = new WordsFrequency(book);
 * int param_1 = obj->get(word);
 */

int main() {
    
    return 0;
}
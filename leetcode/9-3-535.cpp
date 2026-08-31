#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

/*
    LeetCode 535. TinyURL 的加密与解密
*/

class Solution {

private:
string CHAR = "0123456789abcdefghijklmnopqrstuvwxyz";
unordered_map<string, string> longToShort;  
unordered_map<string, string> shortToLong; 
int counter = 10000000;

public:
    string toBase62(int code) {
        string ret = "";
        while(code) {
            ret += code % 62;
            code /= 62;
        }

        while(ret.size() < 6) {
            ret = "0" + ret;
        }
        return ret;
    }

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (longToShort.find(longUrl) != longToShort.end()) {
            return longToShort[longUrl];
        }

        string shortCode = toBase62(counter++);

        shortToLong[shortCode] = longUrl;
        longToShort[longUrl] = shortCode;

        return shortCode;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return shortToLong[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

int main() {
    Solution s;
    string enS = s.encode("https://leetcode.com/problems/design-tinyurl");
    cout << enS << endl;
    string deS = s.decode(enS);
    cout << deS << endl;
    return 0;
}
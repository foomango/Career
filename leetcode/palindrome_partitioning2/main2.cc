/*
 * =====================================================================================
 *
 *       Filename:  main2.cc
 *
 *    Description:  http://foomango.blog.163.com/blog/static/218098074201386103118218/
 *
 *        Version:  1.0
 *        Created:  09/06/2013 10:25:18 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  WangFengwei (mn), foomango@gmail.com
 *        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
 *
 * =====================================================================================
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int minCut(string s) {
        if (s.size() <= 1) {
            return 0;
        }

        bool *isPalindrome = new bool[s.size() * s.size()];
        size_t *cutNum = new size_t[s.size()];

        // Initialize isPalindrome
        fill(isPalindrome, isPalindrome + s.size() * s.size(), false);
        for (int i = 0; i < s.size(); ++i) {
            // 以s[i]为对称中心
            for (int j = 0; i - j >= 0 && i + j < s.size(); ++j) {
                if(s.at(i - j) == s.at(i + j)) {
                    *(isPalindrome + (i - j) * s.size() + (i + j)) = true;
                }
                else {
                    break;
                }
            }

            // 以s[i]和s[i + 1]为对称中心
            for (int j = 0; i - j >= 0 && i + j + 1 < s.size(); ++j) {
                if (s.at(i - j) == s.at(i + j + 1)) {
                    *(isPalindrome + (i - j) * s.size() + (i + j + 1)) = true;
                }
                else {
                    break;
                }
            }
        }

        // Caculate cutNum
        fill(cutNum, cutNum + s.size(), s.size() - 1);
        for (int i = 0; i < s.size(); ++i) {
            if (isPalindrome[i]) {
                cutNum[i] = 0;
            }
            else {
                for (int j = i - 1; j >= 0; --j) {
                    if (isPalindrome[(j + 1) * s.size() + i])
                        cutNum[i] = min(cutNum[i], cutNum[j] + 1);
                }
            }
        }

        int ret = cutNum[s.size() - 1];
        delete[] cutNum;
        delete[] isPalindrome;

        return ret;
    }
};

int main(int argc, char *argv[]) 
{
    Solution s;
    cout << "a:" << s.minCut("a") << endl;
    cout << "aa:" << s.minCut("aa") << endl;
    cout << "abbaddcc:" << s.minCut("abbaddcc") << endl;
    cout << "abac:" << s.minCut("abac") << endl;
    cout << "ababababababababababababcbabababababababababababa:" << s.minCut("ababababababababababababcbabababababababababababa") << endl;
    return 0;
}

// Given a string s, find the length of the longest substring without duplicate characters.



#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int left = 0,maxLength = 0, n = s.length();
      unordered_set<char>mp;
      for(int right = 0; right < n;right++){
        while(mp.find(s[right]) != mp.end()){
          mp.erase(s[left]);
          left++;
        }
        mp.insert(s[right]);
        maxLength = max(maxLength, right - left + 1);
      }
      return maxLength;
    }
};

int main() {
  Solution solution;
  string s = "abccab";
  cout<<"The length of the longest substring without duplicate characters is : "<<solution.lengthOfLongestSubstring(s)<<endl;

  s = "bbbb";
  cout<<"The length of the longest substring without duplicate characters is : "<<solution.lengthOfLongestSubstring(s)<<endl;
}

using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

class LongestSubstringKDistinct {
 public:
  static int findLength(const string& str, int k) {
    int maxLength = 0;
    int windowStart = 0;
    unordered_map<char, int> charFrequencyMap;
    for(int windowEnd=0;windowEnd<str.size();++windowEnd){
      charFrequencyMap[str[windowEnd]]++;
      while ((int)charFrequencyMap.size() > k) {
        char leftChar = str[windowStart];
        charFrequencyMap[leftChar]--;
        if (charFrequencyMap[leftChar] == 0) {
          charFrequencyMap.erase(leftChar);
        }
        windowStart++; // shrink the window
      }
      maxLength = max(maxLength, windowEnd - windowStart + 1);
    }
      
    return maxLength;
  }
};
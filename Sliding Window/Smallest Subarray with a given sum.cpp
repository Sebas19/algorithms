using namespace std;

#include <iostream>
#include <limits>
#include <vector>

class MinSizeSubArraySum {
 public:
  static int findMinSubArray(int S, const vector<int>& arr) {
    int len = 100000;
    int windowStart=0;
    int windowSum=0;
    for(int windowEnd=0;windowEnd<arr.size();++windowEnd){
      windowSum += arr[windowEnd];
      while (windowSum >= S) {
        len = min(len, windowEnd - windowStart + 1);
        windowSum -= arr[windowStart];  
        windowStart++;                  
      }
    }
    return len;
  }
};
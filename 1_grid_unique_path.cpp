
#include<bits/stdc++.h>
using namespace std;

/*There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.

Input: m = 3, n = 7
Output: 28

1 <= m, n <= 100
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        
        int p = m+n-2;
        int q = m-1;
        double ans = 1;
        
        for(int i=1;i<=q;i++)
        {
            ans = ans*(p-q+i)/i;
        }
        return (int)ans;
        
    }
};
int main()
{
	Solution s;
	cout<<s.uniquePaths(3,7);
	return 0;
}


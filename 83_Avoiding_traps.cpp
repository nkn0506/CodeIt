/*
Given an array of 'N' elements 'OBSTACLES', where each element represents the coordinate of the obstacle on a straight line. We start jumping from point 0 and we need to reach the end of the line avoiding all the obstacles which are present on the line. The length of every jump should be the same. For example, if we jump from 0 to 3, the jump is of 3 units hence the next jump should also be of 3 units that is from 3 to 6 and so on.
Find the minimum length of the jump so that we can reach the end of the line avoiding all obstacles.

1 <= T <= 50
1 <= N <= 1000
1 <= OBSTACLES[i] <= 10 ^ 6

Where ‘T’ is the total number of test cases, ‘N’ denotes the number of obstacles on the straight line, and ‘OBSTACLES[i]’ denotes the coordinates of obstacles on the straight line.

Time limit: 1 sec.
Sample Input 1:
2
5
5 3 6 7 9
5
5 8 9 13 14
Sample Output 1:
4
6
*/

#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<fstream>
#include<iomanip>
#include<bits/stdc++.h>
using namespace std;
int avoidTraps(vector<int>& ob, int n) 
{
    // Write your code here.
    sort(ob.begin(),ob.end());
    int x = ob[0];
    int y = x+1;
    int i;
    bool flag = true;
    while(flag)
    {
        flag = false;
        for(auto i: ob)
        {
            if(i%y==0)
            {
                y=y+1;
                flag = true;
                break;
            }
        }
    }
    return y;    
}



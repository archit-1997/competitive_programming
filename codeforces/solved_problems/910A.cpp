/*A frog lives on the axis Ox and needs to reach home which is in the point n. She starts from the point 1. The frog can jump to the right at a distance not more than d. So, after she jumped from the point x she can reach the point x + a, where a is an integer from 1 to d.

For each point from 1 to n is known if there is a lily flower in it. The frog can jump only in points with a lilies. Guaranteed that there are lilies in the points 1 and n.

Determine the minimal number of jumps that the frog needs to reach home which is in the point n from the point 1. Consider that initially the frog is in the point 1. If the frog can not reach home, print -1.
Input

The first line contains two integers n and d (2 ≤ n ≤ 100, 1 ≤ d ≤ n - 1) — the point, which the frog wants to reach, and the maximal length of the frog jump.

The second line contains a string s of length n, consisting of zeros and ones. If a character of the string s equals to zero, then in the corresponding point there is no lily flower. In the other case, in the corresponding point there is a lily flower. Guaranteed that the first and the last characters of the string s equal to one.
Output

If the frog can not reach the home, print -1.

In the other case, print the minimal number of jumps that the frog needs to reach the home which is in the point n from the point 1.
Examples
Input
Copy

8 4
10010101

Output
Copy

2

Input
Copy

4 2
1001

Output
Copy

-1

Input
Copy

8 4
11100101

Output
Copy

3

Input
Copy

12 3
101111100101

Output
Copy

4

Note

In the first example the from can reach home in two jumps: the first jump from the point 1 to the point 4 (the length of the jump is three), and the second jump from the point 4 to the point 8 (the length of the jump is four).

In the second example the frog can not reach home, because to make it she need to jump on a distance three, but the maximum length of her jump equals to two.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int 

int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n,d;   cin>>n>>d;
    string s;   cin>>s;
    ll count=0,i=0;
    while(i<n-1 && count<=n)
    {
        if(s[i]=='1')
        {
            i+=d;
            count++;
        }
        else
            i--;
    }
    
    if(count>=n)
        cout<<-1;
    else
        cout<<count<<endl;
    
    return 0;
}

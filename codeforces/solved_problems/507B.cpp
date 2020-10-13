/*Amr loves Geometry. One day he came up with a very interesting problem.

Amr has a circle of radius r and center in point (x, y). He wants the circle center to be in new position (x', y').

In one step Amr can put a pin to the border of the circle in a certain point, then rotate the circle around that pin by any angle and finally remove the pin.

Help Amr to achieve his goal in minimum number of steps.
Input

Input consists of 5 space-separated integers r, x, y, x' y' (1 ≤ r ≤ 105,  - 105 ≤ x, y, x', y' ≤ 105), circle radius, coordinates of original center of the circle and coordinates of destination center of the circle respectively.
Output

Output a single integer — minimum number of steps required to move the center of the circle to the destination point.
Examples
Input
Copy

2 0 0 0 4

Output
Copy

1

Input
Copy

1 1 1 4 4

Output
Copy

3

Input
Copy

4 5 6 5 6

Output
Copy

0

Note

In the first sample test the optimal way is to put a pin at point (0, 2) and rotate the circle by 180 degrees counter-clockwise (or clockwise, no matter).
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
#define ld long double

int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ld r,x,y,x1,y1;
    
    cin>>r>>x>>y>>x1>>y1;
    
    if(x==x1 && y==y1)
    {
        cout<<0<<endl;
        return 0;
    }
    
    ld dis=sqrt(pow(x1-x,2)+pow(y1-y,2));
    
    //cout<<"dis "<<dis<<endl;
    
    ld seg=dis/(2*r);
    
    //cout<<"seg "<<seg<<endl;
    
    ll round=int(seg);
    
    if(round==seg)
        cout<<round<<endl;
    else
        cout<<round+1<<endl;
    
    
    return 0;
}

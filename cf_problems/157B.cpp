/*One day, as Sherlock Holmes was tracking down one very important criminal, he found a wonderful painting on the wall. This wall could be represented as a plane. The painting had several concentric circles that divided the wall into several parts. Some parts were painted red and all the other were painted blue. Besides, any two neighboring parts were painted different colors, that is, the red and the blue color were alternating, i. e. followed one after the other. The outer area of the wall (the area that lied outside all circles) was painted blue. Help Sherlock Holmes determine the total area of red parts of the wall.

Let us remind you that two circles are called concentric if their centers coincide. Several circles are called concentric if any two of them are concentric.
Input

The first line contains the single integer n (1 ≤ n ≤ 100). The second line contains n space-separated integers ri (1 ≤ ri ≤ 1000) — the circles' radii. It is guaranteed that all circles are different.
Output

Print the single real number — total area of the part of the wall that is painted red. The answer is accepted if absolute or relative error doesn't exceed 10 - 4.
Examples
Input
Copy

1
1

Output
Copy

3.1415926536

Input
Copy

3
1 4 2

Output
Copy

40.8407044967

Note

In the first sample the picture is just one circle of radius 1. Inner part of the circle is painted red. The area of the red part equals π × 12 = π.

In the second sample there are three circles of radii 1, 4 and 2. Outside part of the second circle is painted blue. Part between the second and the third circles is painted red. Part between the first and the third is painted blue. And, finally, the inner part of the first circle is painted red. Overall there are two red parts: the ring between the second and the third circles and the inner part of the first circle. Total area of the red parts is equal (π × 42 - π × 22) + π × 12 = π × 12 + π = 13π
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
#define M_PI 3.14159265358979323846

int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;   cin>>n;
    vector<ll> v;

    for(ll i=0;i<n;i++)
    {
        ll num;cin>>num;
        v.push_back(num);
    }
    
    sort(v.begin(),v.end());
    
    if(n==1)
    {
        double ans=M_PI*v[0]*v[0];
        cout<<ans<<endl;
    }
    else
    {
        double ans=0;
        for(ll i=n-1;i>=1;i=i-2)
        {
            double v1=M_PI*v[i]*v[i];
            double v2=M_PI*v[i-1]*v[i-1];
            ans=ans+(v1-v2);
        }
        
        if(n%2)
            ans+=(M_PI*v[0]*v[0]);
        
        cout<<ans<<endl;
    }
    
    return 0;
}

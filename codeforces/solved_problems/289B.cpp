/*Little penguin Polo has an n × m matrix, consisting of integers. Let's index the matrix rows from 1 to n from top to bottom and let's index the columns from 1 to m from left to right. Let's represent the matrix element on the intersection of row i and column j as aij.

In one move the penguin can add or subtract number d from some matrix element. Find the minimum number of moves needed to make all matrix elements equal. If the described plan is impossible to carry out, say so.
Input

The first line contains three integers n, m and d (1 ≤ n, m ≤ 100, 1 ≤ d ≤ 104) — the matrix sizes and the d parameter. Next n lines contain the matrix: the j-th integer in the i-th row is the matrix element aij (1 ≤ aij ≤ 104).
Output

In a single line print a single integer — the minimum number of moves the penguin needs to make all matrix elements equal. If that is impossible, print "-1" (without the quotes).
Examples
Input
Copy

2 2 2
2 4
6 8

Output
Copy

4

Input
Copy

1 2 7
6 7

Output
Copy

-1
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int 

int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll r,c,d;   cin>>r>>c>>d;
    
    vector<ll> v;
    ll check;
    for(ll i=0;i<(r*c);i++)
    {
        ll num; cin>>num;
        if(i==0)
            check=num%d;
        else if(check!=(num%d))
        {
            cout<<-1<<endl;
            return 0;
        }
        v.push_back(num);
    }
    
    ll m,s=(r*c);
    //cout<<"s : "<<s<<endl;
    
    if(s%2==1)
        m=(s+1)/2;
    else
        m=s/2;
        //cout<<"m : "<<m<<endl;
        
    sort(v.begin(),v.end());
        
    ll median=v[m-1];
    //cout<<"median : "<<median<<endl;
    
    ll count=0;
    
    for(ll i=0;i<s;i++)
    {
        ll c=abs(v[i]-median)/d;
        count+=c;
    }
    
    cout<<count<<endl;
    
    return 0;
}

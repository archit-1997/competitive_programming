/*n participants of the competition were split into m teams in some manner so that each team has at least one participant. After the competition each pair of participants from the same team became friends.

Your task is to write a program that will find the minimum and the maximum number of pairs of friends that could have formed by the end of the competition.
Input

The only line of input contains two integers n and m, separated by a single space (1 ≤ m ≤ n ≤ 109) — the number of participants and the number of teams respectively.
Output

The only line of the output should contain two integers kmin and kmax — the minimum possible number of pairs of friends and the maximum possible number of pairs of friends respectively.
Examples
Input
Copy

5 1

Output
Copy

10 10

Input
Copy

3 2

Output
Copy

1 1

Input
Copy

6 3

Output
Copy

3 6

Note

In the first sample all the participants get into one team, so there will be exactly ten pairs of friends.

In the second sample at any possible arrangement one team will always have two participants and the other team will always have one participant. Thus, the number of pairs of friends will always be equal to one.

In the third sample minimum number of newly formed friendships can be achieved if participants were split on teams consisting of 2 people, maximum number can be achieved if participants were split on teams of 1, 1 and 4 people.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int 

ll large(ll n,ll m)
{
    ll val=(n-m+1);
    ll ans=(val*(val-1))/2;
    return ans;
}

ll small(ll n,ll m)
{
    if(n%m==0)
    {
        ll mem=n/m;
        ll val=(mem*(mem-1))/2;
        ll ans=val*m;
        return ans;
    }
    else
    {
        ll diff=n%m;
        ll same=m-diff;
        
        ll val1=n/m;
        ll ans1=(val1*(val1-1))/2;
        
        ll val2=val1+1;
        ll ans2=(val2*(val2-1))/2;
        
        ll ans=ans1*same + ans2*diff;
        
        return ans;
    }
}

int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n,m; cin>>n>>m;
    //max value;
    
    
    if(m==1)
    {
        ll ans=(n*(n-1))/2;
        
        cout<<ans<<" "<<ans<<endl;
    }
    else
    {
        ll max=large(n,m);
        ll min=small(n,m);
        cout<<min<<" "<<max<<endl;
    }
    
    return 0;
}

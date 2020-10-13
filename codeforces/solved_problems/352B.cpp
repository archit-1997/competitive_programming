/*One day Jeff got hold of an integer sequence a1, a2, ..., an of length n. The boy immediately decided to analyze the sequence. For that, he needs to find all values of x, for which these conditions hold:

    x occurs in sequence a.
    Consider all positions of numbers x in the sequence a (such i, that ai = x). These numbers, sorted in the increasing order, must form an arithmetic progression. 

Help Jeff, find all x that meet the problem conditions.
Input

The first line contains integer n (1 ≤ n ≤ 105). The next line contains integers a1, a2, ..., an (1 ≤ ai ≤ 105). The numbers are separated by spaces.
Output

In the first line print integer t — the number of valid x. On each of the next t lines print two integers x and px, where x is current suitable value, px is the common difference between numbers in the progression (if x occurs exactly once in the sequence, px must equal 0). Print the pairs in the order of increasing x.
Examples
Input
Copy

1
2

Output
Copy

1
2 0

Input
Copy

8
1 2 1 3 1 2 1 5

Output
Copy

4
1 2
2 4
3 0
5 0

Note

In the first test 2 occurs exactly once in the sequence, ergo p2 = 0.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int 

int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;   cin>>n;
    map<ll,vector<ll>> m;

    for(ll i=0;i<n;i++)
    {
        ll num;cin>>num;
        m[num].push_back(i);
    }
    //cout<<m.size()<<endl;
    
    ll count=0;
    
    for(auto it=m.begin();it!=m.end();it++)
    {
        ll s=(it->second).size();
        if(s==1)
            count++;
        else
        {
            vector<ll> v1=it->second;
            ll d=v1[1]-v1[0],flag=0;
            for(ll i=0;i<v1.size()-1;i++)
            {
                ll diff=v1[i+1]-v1[i];
                if(diff!=d)
                {
                    flag=1;
                    break;
                }
            }
            if(!flag)
                count++;
        }
    }
    
    cout<<count<<endl;
    
    if(count!=0)
    {
    for(auto it=m.begin();it!=m.end();it++)
    {
        ll s=(it->second).size();
        if(s==1)
            cout<<it->first<<" "<<0<<endl;
        else
        {
            vector<ll> v1=it->second;
            ll d=v1[1]-v1[0],flag=0;
            for(ll i=0;i<v1.size()-1;i++)
            {
                ll diff=v1[i+1]-v1[i];
                if(diff!=d)
                {
                    flag=1;
                    break;
                }
            }
            if(!flag)
                cout<<it->first<<" "<<d<<endl;
        }
    }
    }
        
    
    return 0;
}

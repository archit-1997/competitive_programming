/*Vasya is going to the Olympics in the city Ntown by train. The boy wants to read the textbook to prepare for the Olympics. He counted that he needed k hours for this. He also found that the light in the train changes every hour. The light is measured on a scale from 0 to 100, where 0 is very dark, and 100 is very light.

Vasya has a train lighting schedule for all n hours of the trip — n numbers from 0 to 100 each (the light level in the first hour, the second hour and so on). During each of those hours he will either read the whole time, or not read at all. He wants to choose k hours to read a book, not necessarily consecutive, so that the minimum level of light among the selected hours were maximum. Vasya is very excited before the upcoming contest, help him choose reading hours.
Input

The first input line contains two integers n and k (1 ≤ n ≤ 1000, 1 ≤ k ≤ n) — the number of hours on the train and the number of hours to read, correspondingly. The second line contains n space-separated integers ai (0 ≤ ai ≤ 100), ai is the light level at the i-th hour.
Output

In the first output line print the minimum light level Vasya will read at. In the second line print k distinct space-separated integers b1, b2, ..., bk, — the indexes of hours Vasya will read at (1 ≤ bi ≤ n). The hours are indexed starting from 1. If there are multiple optimal solutions, print any of them. Print the numbers bi in an arbitrary order.
Examples
Input
Copy

5 3
20 10 30 40 10

Output
Copy

20
1 3 4 

Input
Copy

6 5
90 20 35 40 60 100

Output
Copy

35
1 3 4 5 6 

Note

In the first sample Vasya should read at the first hour (light 20), third hour (light 30) and at the fourth hour (light 40). The minimum light Vasya will have to read at is 20.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool compare(const pair<ll,ll> &a,const pair<ll,ll> &b)
{
    if(a.first==b.first)
        return a.second<b.second;
    
    return a.first>b.first;
}

int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    ll n,k;   cin>>n>>k;
    vector<pair<ll,ll>> v(n);

    for(ll i=0;i<n;i++)
    {
        ll num;cin>>num;
        v[i]=make_pair(num,i);
    }
    
    
    sort(v.begin(),v.end(),compare);
    
    vector<ll> ans(k);
    
    for(ll i=0;i<k;i++)
    {
        ans[i]=v[i].second;
    }
    cout<<v[k-1].first<<endl;
    sort(ans.begin(),ans.end());
    
    for(ll i=0;i<k;i++)
        cout<<ans[i]+1<<" ";
    
    return 0;
}


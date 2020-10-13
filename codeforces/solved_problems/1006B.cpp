/*Polycarp is practicing his problem solving skill. He has a list of n problems with difficulties a1,a2,…,an, respectively. His plan is to practice for exactly k days. Each day he has to solve at least one problem from his list. Polycarp solves the problems in the order they are given in his list, he cannot skip any problem from his list. He has to solve all n problems in exactly k

days.

Thus, each day Polycarp solves a contiguous sequence of (consecutive) problems from the start of the list. He can't skip problems or solve them multiple times. As a result, in k
days he will solve all the n

problems.

The profit of the j
-th day of Polycarp's practice is the maximum among all the difficulties of problems Polycarp solves during the j-th day (i.e. if he solves problems with indices from l to r during a day, then the profit of the day is maxl≤i≤rai). The total profit of his practice is the sum of the profits over all k

days of his practice.

You want to help Polycarp to get the maximum possible total profit over all valid ways to solve problems. Your task is to distribute all n
problems between k

days satisfying the conditions above in such a way, that the total profit is maximum.

For example, if n=8,k=3
and a=[5,4,2,6,5,1,9,2], one of the possible distributions with maximum total profit is: [5,4,2],[6,5],[1,9,2]. Here the total profit equals 5+6+9=20

.
Input

The first line of the input contains two integers n
and k (1≤k≤n≤2000

) — the number of problems and the number of days, respectively.

The second line of the input contains n
integers a1,a2,…,an (1≤ai≤2000

) — difficulties of problems in Polycarp's list, in the order they are placed in the list (i.e. in the order Polycarp will solve them).
Output

In the first line of the output print the maximum possible total profit.

In the second line print exactly k
positive integers t1,t2,…,tk (t1+t2+⋯+tk must equal n), where tj means the number of problems Polycarp will solve during the j

-th day in order to achieve the maximum possible total profit of his practice.

If there are many possible answers, you may print any of them.
Examples
Input
Copy

8 3
5 4 2 6 5 1 9 2

Output
Copy

20
3 2 3

Input
Copy

5 1
1 1 1 1 1

Output
Copy

1
5

Input
Copy

4 2
1 2000 2000 2

Output
Copy

4000
2 2

Note

The first example is described in the problem statement.

In the second example there is only one possible distribution.

In the third example the best answer is to distribute problems in the following way: [1,2000],[2000,2]
. The total profit of this distribution is 2000+2000=4000.
*/

//Archit Singh
//20168018
//Bachelor Of Technology
//Information Technology
//Motilal Nehru National Institute Of Technology

#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main()
{
	//Fast I/O
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n,k; cin>>n>>k;
	vector<ll>  A;
	vector<pair<ll,ll>> v;
	
	for(ll i=0;i<n;i++)
	{
	    ll num; cin>>num;
	    A.push_back(num);
	    v.push_back({num,i});
	}
	
	sort(v.begin(),v.end());
	
// 	for(ll i=0;i<n;i++)
// 	    cout<<v[i].first<<" "<<v[i].second<<endl;
	
	vector<ll> index;
	ll c=0;
	ll last=n-1;
	ll sum=0;
	while(c<k)
	{
	    index.push_back(v[last].second);
	    sum+=v[last].first;
	    last--;
	    c++;
	}
	
	cout<<sum<<endl;

    sort(index.begin(),index.end());
    // for(ll i=0;i<index.size();i++)
    //     cout<<index[i]<<" ";
    // cout<<endl;
    vector<ll> ans;
    ll prev=-1;
    for(ll i=0;i<index.size()-1;i++)
    {
        ll d=index[i]-prev;
        ans.push_back(d);
        prev=index[i];
    }
    ll d=(n-1)-prev;
    ans.push_back(d);
    
    for(ll i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    
	
	return 0;
}

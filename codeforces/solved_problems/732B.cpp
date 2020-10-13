/*Recently a dog was bought for Polycarp. The dog's name is Cormen. Now Polycarp has a lot of troubles. For example, Cormen likes going for a walk.

Empirically Polycarp learned that the dog needs at least k walks for any two consecutive days in order to feel good. For example, if k = 5 and yesterday Polycarp went for a walk with Cormen 2 times, today he has to go for a walk at least 3 times.

Polycarp analysed all his affairs over the next n days and made a sequence of n integers a1, a2, ..., an, where ai is the number of times Polycarp will walk with the dog on the i-th day while doing all his affairs (for example, he has to go to a shop, throw out the trash, etc.).

Help Polycarp determine the minimum number of walks he needs to do additionaly in the next n days so that Cormen will feel good during all the n days. You can assume that on the day before the first day and on the day after the n-th day Polycarp will go for a walk with Cormen exactly k times.

Write a program that will find the minumum number of additional walks and the appropriate schedule — the sequence of integers b1, b2, ..., bn (bi ≥ ai), where bi means the total number of walks with the dog on the i-th day.
Input

The first line contains two integers n and k (1 ≤ n, k ≤ 500) — the number of days and the minimum number of walks with Cormen for any two consecutive days.

The second line contains integers a1, a2, ..., an (0 ≤ ai ≤ 500) — the number of walks with Cormen on the i-th day which Polycarp has already planned.
Output

In the first line print the smallest number of additional walks that Polycarp should do during the next n days so that Cormen will feel good during all days.

In the second line print n integers b1, b2, ..., bn, where bi — the total number of walks on the i-th day according to the found solutions (ai ≤ bi for all i from 1 to n). If there are multiple solutions, print any of them.
Examples
Input
Copy

3 5
2 0 1

Output
Copy

4
2 3 2

Input
Copy

3 1
0 0 0

Output
Copy

1
0 1 0

Input
Copy

4 6
2 4 3 5

Output
Copy

0
2 4 3 5
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
	
	ll d,t; cin>>d>>t;
	vector<ll> hr;
	for(ll i=0;i<d;i++)
	{
	    ll num; cin>>num;
	    hr.push_back(num);
	}
	
	ll sum=0;
	
	for(ll i=1;i<d;i++)
	{
	    ll add=hr[i]+hr[i-1];
	    if(add<t)
	    {
	        ll diff=t-add;
	        sum+=diff;
	        hr[i]+=diff;
	    }
	}
	
	cout<<sum<<endl;
	for(ll i=0;i<d;i++)
	    cout<<hr[i]<<" ";
	
	cout<<endl;
	
	
	return 0;
}

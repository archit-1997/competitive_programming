/*Vanya wants to pass n exams and get the academic scholarship. He will get the scholarship if the average grade mark for all the exams is at least avg. The exam grade cannot exceed r. Vanya has passed the exams and got grade ai for the i-th exam. To increase the grade for the i-th exam by 1 point, Vanya must write bi essays. He can raise the exam grade multiple times.

What is the minimum number of essays that Vanya needs to write to get scholarship?
Input

The first line contains three integers n, r, avg (1 ≤ n ≤ 105, 1 ≤ r ≤ 109, 1 ≤ avg ≤ min(r, 106)) — the number of exams, the maximum grade and the required grade point average, respectively.

Each of the following n lines contains space-separated integers ai and bi (1 ≤ ai ≤ r, 1 ≤ bi ≤ 106).
Output

In the first line print the minimum number of essays.
Examples
Input
Copy

5 5 4
5 2
4 7
3 1
3 2
2 5

Output
Copy

4

Input
Copy

2 5 4
5 2
5 2

Output
Copy

0

Note

In the first sample Vanya can write 2 essays for the 3rd exam to raise his grade by 2 points and 2 essays for the 4th exam to raise his grade by 1 point.

In the second sample, Vanya doesn't need to write any essays as his general point average already is above average.
*/

//Chochu Singh
#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int compare(const pair<ll,ll> &a, const pair<ll,ll> &b)
{
    if(a.second==b.second)
        return a.first<b.first;
    else
        return a.second<b.second;
}

int main()
{
	//Fast I/O
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n,r,avg;	cin>>n>>r>>avg;
	vector<pair<ll,ll>> v;
	ll sum=0;
	for(ll i=0;i<n;i++)
	{
		ll a,b; cin>>a>>b;
		sum+=a;
		v.push_back({a,b});
	}
	
	sort(v.begin(),v.end(),compare);
	
// 	for(ll i=0;i<n;i++)
// 	    cout<<v[i].first<<" "<<v[i].second<<endl;
// 	cout<<"------------"<<endl;
    
    ll ans=0,index=0;
    
    while(sum<n*avg)
    {
        ll c=min(n*avg-sum,r-v[index].first);
        sum+=c;
        
        ans+=c*v[index].second;
        index++;
    }
    
    cout<<ans<<endl;
	
	return 0;
}

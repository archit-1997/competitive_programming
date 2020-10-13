/*Another programming contest is over. You got hold of the contest's final results table. The table has the following data. For each team we are shown two numbers: the number of problems and the total penalty time. However, for no team we are shown its final place.

You know the rules of comparing the results of two given teams very well. Let's say that team a solved pa problems with total penalty time ta and team b solved pb problems with total penalty time tb. Team a gets a higher place than team b in the end, if it either solved more problems on the contest, or solved the same number of problems but in less total time. In other words, team a gets a higher place than team b in the final results' table if either pa > pb, or pa = pb and ta < tb.

It is considered that the teams that solve the same number of problems with the same penalty time share all corresponding places. More formally, let's say there is a group of x teams that solved the same number of problems with the same penalty time. Let's also say that y teams performed better than the teams from this group. In this case all teams from the group share places y + 1, y + 2, ..., y + x. The teams that performed worse than the teams from this group, get their places in the results table starting from the y + x + 1-th place.

Your task is to count what number of teams from the given list shared the k-th place.
Input

The first line contains two integers n and k (1 ≤ k ≤ n ≤ 50). Then n lines contain the description of the teams: the i-th line contains two integers pi and ti (1 ≤ pi, ti ≤ 50) — the number of solved problems and the total penalty time of the i-th team, correspondingly. All numbers in the lines are separated by spaces.
Output

In the only line print the sought number of teams that got the k-th place in the final results' table.
Examples
Input
Copy

7 2
4 10
4 10
4 10
3 20
2 1
2 1
1 10

Output
Copy

3

Input
Copy

5 4
3 1
3 1
5 3
3 1
3 1

Output
Copy

4

Note

The final results' table for the first sample is:

    1-3 places — 4 solved problems, the penalty time equals 10
    4 place — 3 solved problems, the penalty time equals 20
    5-6 places — 2 solved problems, the penalty time equals 1
    7 place — 1 solved problem, the penalty time equals 10 

The table shows that the second place is shared by the teams that solved 4 problems with penalty time 10. There are 3 such teams.

The final table for the second sample is:

    1 place — 5 solved problems, the penalty time equals 3
    2-5 places — 3 solved problems, the penalty time equals 1 

The table shows that the fourth place is shared by the teams that solved 3 problems with penalty time 1. There are 4 such teams.
*/

//Chochu Singh
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double
#define line cout<<"-------------"<<endl;
#define F first
#define S second
#define P pair<ll,ll>

bool compare(const pair<ll,ll> &a, const pair<ll,ll> &b)
{
    if(a.F==b.F)
        return a.S<b.S;
    else
        return a.F>b.F;
}

int main()
{
	//Fast I/O
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n,k; cin>>n>>k;
	
	vector<pair<ll,ll>> v;
	
	for(ll i=0;i<n;i++)
	{
	    ll a,b; cin>>a>>b;
	    v.push_back({a,b});
	}
	
	if(k>n)
	{
	    cout<<0;
	    return 0;
	}
	else if(n==1)
	{
	    cout<<1;
	    return 0;
	}
	
	sort(v.begin(),v.end(),compare);
	
// 	for(ll i=0;i<n;i++)
// 	    cout<<v[i].F<<" "<<v[i].S<<endl;
	
// 	line;
	
	//count-->number of teams   pos-->the value of k
    
    P p=v[0];
    ll i=0,total=0;
    
    while(i<n)
    {
        ll count=0;
        while((p.F==v[i].F && p.S==v[i].S) && i<n)
        {
            count++;
            i++;
        }
        total+=count;
        if(k<=total)
        {
            cout<<count;
            return 0;
        }
        else
        {
            count=0;
            p=v[i];
        }
        
    }
	
	
	return 0;
}

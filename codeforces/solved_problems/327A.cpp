/*Iahub got bored, so he invented a game to be played on paper.

He writes n integers a1, a2, ..., an. Each of those integers can be either 0 or 1. He's allowed to do exactly one move: he chooses two indices i and j (1 ≤ i ≤ j ≤ n) and flips all values ak for which their positions are in range [i, j] (that is i ≤ k ≤ j). Flip the value of x means to apply operation x = 1 - x.

The goal of the game is that after exactly one move to obtain the maximum number of ones. Write a program to solve the little game of Iahub.
Input

The first line of the input contains an integer n (1 ≤ n ≤ 100). In the second line of the input there are n integers: a1, a2, ..., an. It is guaranteed that each of those n values is either 0 or 1.
Output

Print an integer — the maximal number of 1s that can be obtained after exactly one move.
Examples
Input
Copy

5
1 0 0 1 0

Output
Copy

4

Input
Copy

4
1 0 0 1

Output
Copy

4

Note

In the first case, flip the segment from 2 to 5 (i = 2, j = 5). That flip changes the sequence, it becomes: [1 1 1 0 1]. So, it contains four ones. There is no way to make the whole sequence equal to [1 1 1 1 1].

In the second case, flipping only the second and the third element (i = 2, j = 3) will turn all numbers into 1.
*/

//Chochu Singh
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double
#define line cout<<"-------------"<<endl;
#define F first
#define S second

int main()
{
	//Fast I/O
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n;	cin>>n;
	vector<ll> v;
	
	for(ll i=0;i<n;i++)
	{
		ll num;	cin>>num;
		v.push_back(num);
	}
	
	ll start=0,end=0,s=0;
	
	vector<ll> arr=v;
	for(ll i=0;i<n;i++)
	{
	    if(arr[i]==1)
	        arr[i]=-1;
	    else
	        arr[i]=1;
	}
	
	ll meh=0,msf=INT_MIN;
	
	for(ll i=0;i<n;i++)
	{
	    meh+=arr[i];
	    if(msf<meh)
	    {
	        msf=meh;
	        start=s;
	        end=i;
	    }
	    
	    if(meh<0)
	    {
	       meh=0;
	       s=i+1;
	    }
	    
	}
	
	for(ll i=start;i<=end;i++)
	{
	    if(v[i]==0)
	        v[i]=1;
	    else
	        v[i]=0;
	}
	
	ll ans=count(v.begin(),v.end(),1);
	
	cout<<ans;
	
	
	return 0;
}

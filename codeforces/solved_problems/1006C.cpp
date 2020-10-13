/*You are given an array 𝑑1,𝑑2,…,𝑑𝑛 consisting of 𝑛

integer numbers.

Your task is to split this array into three parts (some of which may be empty) in such a way that each element of the array belongs to exactly one of the three parts, and each of the parts forms a consecutive contiguous subsegment (possibly, empty) of the original array.

Let the sum of elements of the first part be 𝑠𝑢𝑚1
, the sum of elements of the second part be 𝑠𝑢𝑚2 and the sum of elements of the third part be 𝑠𝑢𝑚3. Among all possible ways to split the array you have to choose a way such that 𝑠𝑢𝑚1=𝑠𝑢𝑚3 and 𝑠𝑢𝑚1

is maximum possible.

More formally, if the first part of the array contains 𝑎
elements, the second part of the array contains 𝑏 elements and the third part contains 𝑐

elements, then:

𝑠𝑢𝑚1=∑1≤𝑖≤𝑎𝑑𝑖,
𝑠𝑢𝑚2=∑𝑎+1≤𝑖≤𝑎+𝑏𝑑𝑖,
𝑠𝑢𝑚3=∑𝑎+𝑏+1≤𝑖≤𝑎+𝑏+𝑐𝑑𝑖.

The sum of an empty array is 0

.

Your task is to find a way to split the array such that 𝑠𝑢𝑚1=𝑠𝑢𝑚3
and 𝑠𝑢𝑚1

is maximum possible.
Input

The first line of the input contains one integer 𝑛
(1≤𝑛≤2⋅105) — the number of elements in the array 𝑑

.

The second line of the input contains 𝑛
integers 𝑑1,𝑑2,…,𝑑𝑛 (1≤𝑑𝑖≤109) — the elements of the array 𝑑

.
Output

Print a single integer — the maximum possible value of 𝑠𝑢𝑚1
, considering that the condition 𝑠𝑢𝑚1=𝑠𝑢𝑚3

must be met.

Obviously, at least one valid way to split the array exists (use 𝑎=𝑐=0
and 𝑏=𝑛

).
Examples
Input
Copy

5
1 3 1 1 4

Output
Copy

5

Input
Copy

5
1 3 2 1 4

Output
Copy

4

Input
Copy

3
4 1 2

Output
Copy

0

Note

In the first example there is only one possible splitting which maximizes 𝑠𝑢𝑚1
: [1,3,1],[ ],[1,4]

.

In the second example the only way to have 𝑠𝑢𝑚1=4
is: [1,3],[2,1],[4]

.

In the third example there is only one way to split the array: [ ],[4,1,2],[ ]
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
	
	
	ll ans=0,l=-1,r=n,ls=0,rs=0;
	
	while(l<r)
	{
	    if(ls<rs)
	   {
	        l++;
	        ls+=v[l];
	   }
	   else if(ls>rs)
	   {
	       r--;
	       rs+=v[r];
	   }
	   else
	   {
	       ans=l;
	       l++;
	       r--;
	       ls+=v[l];
	       rs+=v[r];
	   }
	}
	
	ll sum=0;
	cout<<ans<<endl;
	
	for(ll i=0;i<=ans;i++)
	    sum+=v[i];
	    
    cout<<sum<<endl;
	
	return 0;
}
.

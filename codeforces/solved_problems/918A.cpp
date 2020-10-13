/*Eleven wants to choose a new name for herself. As a bunch of geeks, her friends suggested an algorithm to choose a name for her. Eleven wants her name to have exactly n characters.

Her friend suggested that her name should only consist of uppercase and lowercase letters 'O'. More precisely, they suggested that the i-th letter of her name should be 'O' (uppercase) if i is a member of Fibonacci sequence, and 'o' (lowercase) otherwise. The letters in the name are numbered from 1 to n. Fibonacci sequence is the sequence f where

    f1 = 1,
    f2 = 1,
    fn = fn - 2 + fn - 1 (n > 2). 

As her friends are too young to know what Fibonacci sequence is, they asked you to help Eleven determine her new name.
Input

The first and only line of input contains an integer n (1 ≤ n ≤ 1000).
Output

Print Eleven's new name on the first and only line of output.
Examples
Input
Copy

8

Output
Copy

OOOoOooO

Input
Copy

15

Output
Copy

OOOoOooOooooOoo
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
	
	vector<ll>v(1000);
	v[0]=1;
	v[1]=1;
	
	unordered_map<ll,ll> hash;
	hash[1]=1;
	ll index=2;
	while(1)
	{
	    ll num=v[index-1]+v[index-2];
	    if(num>1000)
	        break;
	    else
	    {
	        v[index]=num;
	        index++;
	        hash[num]=1;
	    }
	}
	
	ll n;   cin>>n;
	string ans;
	
	for(ll i=1;i<=n;i++)
	{
	    if(hash[i])
	        ans=ans+'O';
	    else
	        ans=ans+'o';
	}
	
	cout<<ans;
	
	
	return 0;
}

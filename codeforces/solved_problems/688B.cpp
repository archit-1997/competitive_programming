/*Pari has a friend who loves palindrome numbers. A palindrome number is a number that reads the same forward or backward. For example 12321, 100001 and 1 are palindrome numbers, while 112 and 1021 are not.

Pari is trying to love them too, but only very special and gifted people can understand the beauty behind palindrome numbers. Pari loves integers with even length (i.e. the numbers with even number of digits), so she tries to see a lot of big palindrome numbers with even length (like a 2-digit 11 or 6-digit 122221), so maybe she could see something in them.

Now Pari asks you to write a program that gets a huge integer n from the input and tells what is the n-th even-length positive palindrome number?
Input

The only line of the input contains a single integer n (1 ≤ n ≤ 10100 000).
Output

Print the n-th even-length palindrome number.
Examples
Input
Copy

1

Output
Copy

11

Input
Copy

10

Output
Copy

1001

Note

The first 10 even-length palindrome numbers are 11, 22, 33, ... , 88, 99 and 1001.
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
#define PP pair<pair<ll,ll>,ll>
#define V vector<ll>
#define VP vector<pair<ll,ll>>
#define VS vector<string>
#define VV vector<vector<ll>> 
#define VVP vector<vector<pair<ll,ll>>> 
#define pb push_back
#define pf push_front
#define PQ priority_queue<ll>
#define PQ_G priority_queue<ll,vector<ll>,greater<ll>>
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);

int main()
{
	FAST;
	
	string s;   cin>>s;
	string rev=s;
	reverse(rev.begin(),rev.end());
	
	s=s+rev;
	
	cout<<s<<endl;
	
	return 0;
}

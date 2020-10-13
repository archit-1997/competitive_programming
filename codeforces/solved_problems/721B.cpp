/*Vanya is managed to enter his favourite site Codehorses. Vanya uses n distinct passwords for sites at all, however he can't remember which one exactly he specified during Codehorses registration.

Vanya will enter passwords in order of non-decreasing their lengths, and he will enter passwords of same length in arbitrary order. Just when Vanya will have entered the correct password, he is immediately authorized on the site. Vanya will not enter any password twice.

Entering any passwords takes one second for Vanya. But if Vanya will enter wrong password k times, then he is able to make the next try only 5 seconds after that. Vanya makes each try immediately, that is, at each moment when Vanya is able to enter password, he is doing that.

Determine how many seconds will Vanya need to enter Codehorses in the best case for him (if he spends minimum possible number of second) and in the worst case (if he spends maximum possible amount of seconds).
Input

The first line of the input contains two integers n and k (1 ≤ n, k ≤ 100) — the number of Vanya's passwords and the number of failed tries, after which the access to the site is blocked for 5 seconds.

The next n lines contains passwords, one per line — pairwise distinct non-empty strings consisting of latin letters and digits. Each password length does not exceed 100 characters.

The last line of the input contains the Vanya's Codehorses password. It is guaranteed that the Vanya's Codehorses password is equal to some of his n passwords.
Output

Print two integers — time (in seconds), Vanya needs to be authorized to Codehorses in the best case for him and in the worst case respectively.
Examples
Input
Copy

5 2
cba
abc
bb1
abC
ABC
abc

Output
Copy

1 15

Input
Copy

4 100
11
22
1
2
22

Output
Copy

3 4

Note

Consider the first sample case. As soon as all passwords have the same length, Vanya can enter the right password at the first try as well as at the last try. If he enters it at the first try, he spends exactly 1 second. Thus in the best case the answer is 1. If, at the other hand, he enters it at the last try, he enters another 4 passwords before. He spends 2 seconds to enter first 2 passwords, then he waits 5 seconds as soon as he made 2 wrong tries. Then he spends 2 more seconds to enter 2 wrong passwords, again waits 5 seconds and, finally, enters the correct password spending 1 more second. In summary in the worst case he is able to be authorized in 15 seconds.

Consider the second sample case. There is no way of entering passwords and get the access to the site blocked. As soon as the required password has length of 2, Vanya enters all passwords of length 1 anyway, spending 2 seconds for that. Then, in the best case, he immediately enters the correct password and the answer for the best case is 3, but in the worst case he enters wrong password of length 2 and only then the right one, spending 4 seconds at all.
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
	
	ll n,k;	cin>>n>>k;
	
	unordered_map<int,int> hash;
	
	for(ll i=0;i<n;i++)
	{
		string s;   cin>>s;
		ll len=s.size();
		hash[len]++;
	}
	
	string s;   cin>>s;
	ll l=s.size();
	
	ll min=0,max=0;
	
	for(ll i=1;i<l;i++)
	    min+=hash[i];
	
	ll wmin=min/k;
	ll ans_min=min+(wmin*5)+1;
	max+=(min+hash[l]-1);
	ll wmax=max/k;
	ll ans_max=max+(wmax*5)+1;
	
	cout<<ans_min<<" "<<ans_max;
	
	return 0;
}

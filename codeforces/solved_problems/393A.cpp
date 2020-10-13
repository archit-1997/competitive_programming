/*Alice likes word "nineteen" very much. She has a string s and wants the string to contain as many such words as possible. For that reason she can rearrange the letters of the string.

For example, if she has string "xiineteenppnnnewtnee", she can get string "xnineteenppnineteenw", containing (the occurrences marked) two such words. More formally, word "nineteen" occurs in the string the number of times you can read it starting from some letter of the string. Of course, you shouldn't skip letters.

Help her to find the maximum number of "nineteen"s that she can get in her string.

Input
The first line contains a non-empty string s, consisting only of lowercase English letters. The length of string s doesn't exceed 100.

Output
Print a single integer — the maximum number of "nineteen"s that she can get in her string.

Examples
inputCopy
nniinneetteeeenn
outputCopy
2
inputCopy
nneteenabcnneteenabcnneteenabcnneteenabcnneteenabcii
outputCopy
2
inputCopy
nineteenineteen
outputCopy
2
*/


//Archit Singh
#include <bits/stdc++.h>
using namespace std;

#define 	ll 				long long int
#define 	ld 				long double
#define 	line 			cout<<"-------------"<<endl;
#define 	f 				first
#define 	s 				second
#define 	mp(a,b) 		make_pair(a,b)
#define 	p 				pair<ll,ll>
#define 	pp 				pair<pair<ll,ll>,ll>
#define 	v 				vector<ll>
#define 	vp 				vector<pair<ll,ll>>
#define 	vs 				vector<string>
#define 	vv 				vector<vector<ll>>
#define 	vvp 			vector<vector<pair<ll,ll>>>
#define 	pb 				push_back
#define 	pf 				push_front
#define 	pqb				priority_queue<ll>
#define 	pqs 			priority_queue<ll,V,greater<ll>>
#define 	FOR(i,a,b) 		for(ll i=a;i<b;i++)
#define 	setbits(x)		__builtin_popocount(x)
#define 	zrobits(x)		__builtin_ctzll(x)
#define 	mod				1000000007
#define 	inf				1e18
#define 	ps(x,y)			fixed<<setprecision(y)<<x
#define 	ma(arr,n,type)	type *arr=new type[n]
#define 	w(x)			ll x; cin>>x; while(x--)

void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
}

int main()
{

	init();

	string s; 	cin >> s;

	ll len = s.size();

	v V(4, 0);

	FOR(i, 0, len)
	{
		if (s[i] == 'n')
			V[0]++;
		else if (s[i] == 'i')
			V[1]++;
		else if (s[i] == 'e')
			V[2]++;
		else if (s[i] == 't')
			V[3]++;
	}

	ll ans = V[1];
	ans = min(ans, V[3]);
	ans = min(ans, (V[0] - 1) / 2);
	ans = min(ans, V[2] / 3);

	cout << ans;

	return 0;
}
//Archit Singh
//architsingh456@gmail.com
//GitHub : archit-1997

#include <bits/stdc++.h>
using namespace std;

#define ll		long long int
#define ld		long double
#define line	cout<<"-------------"<<endl;
#define F		first
#define S		second
#define P		pair<ll,ll>
#define PP		pair<pair<ll,ll>,ll>
#define V		vector<ll>
#define VP  	vector<pair<ll,ll>>
#define VS  	vector<string>
#define VV  	vector<vector<ll>>
#define VVP   	vector<vector<pair<ll,ll>>>
#define pb  	push_back
#define pf  	push_front
#define PQ  	priority_queue<ll>
#define PQ_G   	priority_queue<ll,vector<ll>,greater<ll>>
#define line    cout<<"-------------"<<endl;
#define mod 	1000000007
#define inf 	1e18

#define setbits(x)		__builtin_popcount(x)
#define zerobits(x) 	__builtin_ctzll(x)
#define ps(x,y) 		fixed<<setprecision(y)<<x
#define w(x)    		ll x; cin>>x; while(x--)
#define FOR(i,a,b) 		for(ll i=a;i<b;i++)
#define ma(arr,n,type)  type *arr=new type[n]

void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
}

ll precedence(char ch) {
	switch (ch) {
	case '*':
	case '/':
	case '%':
		return 2;
	case '+':
	case '-':
		return 1;
	case '^':
		return 3;
	default:
		return -1;
	}

}

int main()
{

	init();

	w(x) {
		ll n;	cin >> n;
		string s;	cin >> s;
		stack<char> st;

		string ans = "";

		FOR(i, 0, n) {
			//if the scanned character is an operand
			if (s[i] >= 'A' && s[i] <= 'Z')
				ans = ans + s[i];
			//if the scanned character is an operator
			else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '%' || s[i] == '^') {
				if (st.empty() || st.top() == '(' || precedence(s[i]) > precedence(st.top()))
					st.push(s[i]);
				else {
					while (!st.empty()) {
						//stop if you encounter a parenthesis
						if (st.top() == '(') {
							st.push(s[i]);
							break;
						}
						if (precedence(st.top()) >= precedence(s[i])) {
							ans = ans + st.top();
							st.pop();
							if (st.empty()) {
								st.push(s[i]);
								break;
							}
						}
						else {
							st.push(s[i]);
							break;
						}

					}
				}

			}
			//if this is an opening parenthesis
			else if (s[i] == '(') {
				st.push(s[i]);
			}
			//if this is a closing parenthesis
			else if (s[i] == ')') {
				while (!st.empty() && st.top() != '(')
				{
					ans = ans + st.top();
					st.pop();
				}
				if (st.top() == '(')
					st.pop();
			}
		}

		//print while the stack is not empty
		while (!st.empty()) {
			ans = ans + st.top();
			st.pop();
		}

		cout << ans << endl;
	}

	return 0;
}
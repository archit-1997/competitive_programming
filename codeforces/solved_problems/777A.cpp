/*Bomboslav likes to look out of the window in his room and watch lads outside playing famous shell game. The game is played by two persons: operator and player. Operator takes three similar opaque shells and places a ball beneath one of them. Then he shuffles the shells by swapping some pairs and the player has to guess the current position of the ball.

Bomboslav noticed that guys are not very inventive, so the operator always swaps the left shell with the middle one during odd moves (first, third, fifth, etc.) and always swaps the middle shell with the right one during even moves (second, fourth, etc.).

Let's number shells from 0 to 2 from left to right. Thus the left shell is assigned number 0, the middle shell is 1 and the right shell is 2. Bomboslav has missed the moment when the ball was placed beneath the shell, but he knows that exactly n movements were made by the operator and the ball was under shell x at the end. Now he wonders, what was the initial position of the ball?
Input

The first line of the input contains an integer n (1 ≤ n ≤ 2·109) — the number of movements made by the operator.

The second line contains a single integer x (0 ≤ x ≤ 2) — the index of the shell where the ball was found after n movements.
Output

Print one integer from 0 to 2 — the index of the shell where the ball was initially placed.
Examples
Input
Copy

4
2

Output
Copy

1

Input
Copy

1
1

Output
Copy

0

Note

In the first sample, the ball was initially placed beneath the middle shell and the operator completed four movements.

    During the first move operator swapped the left shell and the middle shell. The ball is now under the left shell.
    During the second move operator swapped the middle shell and the right one. The ball is still under the left shell.
    During the third move operator swapped the left shell and the middle shell again. The ball is again in the middle.
    Finally, the operators swapped the middle shell and the right shell. The ball is now beneath the right shell. 
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
	
	ll n;	cin>>n;
	
	ll ball;    cin>>ball;
	n%=6;
	
	V v(3,0);
	v[ball]=1;
	
	for(ll i=n;i>0;i--)
	{
	    if(i%2==0)  //even
	        swap(v[1],v[2]);
	    else
	        swap(v[0],v[1]);
	}
	
	for(ll i=0;i<3;i++)
	{
	    if(v[i]==1)
	    {
	        cout<<i;
	        return 0;
	    }
	}
	
	return 0;
}

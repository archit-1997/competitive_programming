/*Nauuo is a girl who loves playing chess.

One day she invented a game by herself which needs 𝑛
chess pieces to play on a 𝑚×𝑚 chessboard. The rows and columns are numbered from 1 to 𝑚. We denote a cell on the intersection of the 𝑟-th row and 𝑐-th column as (𝑟,𝑐)

.

The game's goal is to place 𝑛
chess pieces numbered from 1 to 𝑛 on the chessboard, the 𝑖-th piece lies on (𝑟𝑖,𝑐𝑖), while the following rule is satisfied: for all pairs of pieces 𝑖 and 𝑗, |𝑟𝑖−𝑟𝑗|+|𝑐𝑖−𝑐𝑗|≥|𝑖−𝑗|. Here |𝑥| means the absolute value of 𝑥

.

However, Nauuo discovered that sometimes she couldn't find a solution because the chessboard was too small.

She wants to find the smallest chessboard on which she can put 𝑛

pieces according to the rules.

She also wonders how to place the pieces on such a chessboard. Can you help her?
Input

The only line contains a single integer 𝑛
(1≤𝑛≤1000

) — the number of chess pieces for the game.
Output

The first line contains a single integer — the minimum value of 𝑚
, where 𝑚

is the length of sides of the suitable chessboard.

The 𝑖
-th of the next 𝑛 lines contains two integers 𝑟𝑖 and 𝑐𝑖 (1≤𝑟𝑖,𝑐𝑖≤𝑚) — the coordinates of the 𝑖

-th chess piece.

If there are multiple answers, print any.
Examples
Input
Copy

2

Output
Copy

2
1 1
1 2

Input
Copy

4

Output
Copy

3
1 1
1 3
3 1
3 3
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
	
	cout<<n/2+1<<endl;
	
	ll x=1,y=1;
	cout<<x<<" "<<y<<endl;
	for(ll i=1;i<n;i++)
	{
	    if(x>y)
	        ++y;
	    else
	        ++x;
	    
	    cout<<x<<" "<<y<<endl;
	}
	
	
	return 0;
}

/*Gerald got a very curious hexagon for his birthday. The boy found out that all the angles of the hexagon are equal to . Then he measured the length of its sides, and found that each of them is equal to an integer number of centimeters. There the properties of the hexagon ended and Gerald decided to draw on it.

He painted a few lines, parallel to the sides of the hexagon. The lines split the hexagon into regular triangles with sides of 1 centimeter. Now Gerald wonders how many triangles he has got. But there were so many of them that Gerald lost the track of his counting. Help the boy count the triangles.
Input

The first and the single line of the input contains 6 space-separated integers a1, a2, a3, a4, a5 and a6 (1 ≤ ai ≤ 1000) — the lengths of the sides of the hexagons in centimeters in the clockwise order. It is guaranteed that the hexagon with the indicated properties and the exactly such sides exists.
Output

Print a single integer — the number of triangles with the sides of one 1 centimeter, into which the hexagon is split.
Examples
Input
Copy

1 1 1 1 1 1

Output
Copy

6

Input
Copy

1 2 1 2 1 2

Output
Copy

13
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
	
	ll a1,a2,a3,a4,a5,a6;
	cin>>a1>>a2>>a3>>a4>>a5>>a6;
	ll area=pow((a1+a2+a3),2);
	ll sub=pow(a1,2)+pow(a3,2)+pow(a5,2);
	
	cout<<area-sub;
	
	return 0;
}

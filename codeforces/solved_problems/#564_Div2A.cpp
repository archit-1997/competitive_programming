/*Nauuo is a girl who loves writing comments.

One day, she posted a comment on Codeforces, wondering whether she would get upvotes or downvotes.

It's known that there were 𝑥
persons who would upvote, 𝑦 persons who would downvote, and there were also another 𝑧 persons who would vote, but you don't know whether they would upvote or downvote. Note that each of the 𝑥+𝑦+𝑧

people would vote exactly one time.

There are three different results: if there are more people upvote than downvote, the result will be "+"; if there are more people downvote than upvote, the result will be "-"; otherwise the result will be "0".

Because of the 𝑧
unknown persons, the result may be uncertain (i.e. there are more than one possible results). More formally, the result is uncertain if and only if there exist two different situations of how the 𝑧

persons vote, that the results are different in the two situations.

Tell Nauuo the result or report that the result is uncertain.
Input

The only line contains three integers 𝑥
, 𝑦, 𝑧 (0≤𝑥,𝑦,𝑧≤100

), corresponding to the number of persons who would upvote, downvote or unknown.
Output

If there is only one possible result, print the result : "+", "-" or "0".

Otherwise, print "?" to report that the result is uncertain.
Examples
Input
Copy

3 7 0

Output
Copy

-

Input
Copy

2 0 1

Output
Copy

+

Input
Copy

1 1 0

Output
Copy

0

Input
Copy

0 0 1

Output
Copy

?

Note

In the first example, Nauuo would definitely get three upvotes and seven downvotes, so the only possible result is "-".

In the second example, no matter the person unknown downvotes or upvotes, Nauuo would get more upvotes than downvotes. So the only possible result is "+".

In the third example, Nauuo would definitely get one upvote and one downvote, so the only possible result is "0".

In the fourth example, if the only one person upvoted, the result would be "+", otherwise, the result would be "-". There are two possible results, so the result is uncertain.
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
	
	ll x,y,z;   cin>>x>>y>>z;
	
	ll res=x-y;
	
	if(z==0)
	{
	    if(res>0)
	        cout<<"+";
	    else if(res<0)
	        cout<<"-";
	    else
	        cout<<0;
	}
	else
	{
	    if(res<0)
	    {
	        ll cur=res+z;
	        if(cur<0)
	            cout<<"-";
	        else
	            cout<<"?";
	    }
	    else if(res>0)
	    {
	        ll cur=res-z;
	        if(cur>0)
	            cout<<"+";
	        else
	            cout<<"?";
	    }
	    else
	        cout<<"?";
	}
	
	
	return 0;
}

/*Kevin has just recevied his disappointing results on the USA Identification of Cows Olympiad (USAICO) in the form of a binary string of length n. Each character of Kevin's string represents Kevin's score on one of the n questions of the olympiad—'1' for a correctly identified cow and '0' otherwise.

However, all is not lost. Kevin is a big proponent of alternative thinking and believes that his score, instead of being the sum of his points, should be the length of the longest alternating subsequence of his string. Here, we define an alternating subsequence of a string as a not-necessarily contiguous subsequence where no two consecutive elements are equal. For example, {0, 1, 0, 1}, {1, 0, 1}, and {1, 0, 1, 0} are alternating sequences, while {1, 0, 0} and {0, 1, 0, 1, 1} are not.

Kevin, being the sneaky little puffball that he is, is willing to hack into the USAICO databases to improve his score. In order to be subtle, he decides that he will flip exactly one substring—that is, take a contiguous non-empty substring of his score and change all '0's in that substring to '1's and vice versa. After such an operation, Kevin wants to know the length of the longest possible alternating subsequence that his string could have.
Input

The first line contains the number of questions on the olympiad n (1 ≤ n ≤ 100 000).

The following line contains a binary string of length n representing Kevin's results on the USAICO.
Output

Output a single integer, the length of the longest possible alternating subsequence that Kevin can create in his string after flipping a single substring.
Examples
Input
Copy

8
10000011

Output
Copy

5

Input
Copy

2
01

Output
Copy

2

Note

In the first sample, Kevin can flip the bolded substring '10000011' and turn his string into '10011011', which has an alternating subsequence of length 5: '10011011'.

In the second sample, Kevin can flip the entire string and still have the same score.
*/

//Archit Singh
//20168018
//Bachelor Of Technology
//Information Technology
//Motilal Nehru National Institute Of Technology

#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main()
{
	//Fast I/O
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n;	cin>>n;
    string s;   cin>>s;
    ll count=1;
    
    for(ll i=1;i<n;i++)
    {
        if(s[i-1]!=s[i])
            count++;
    }
    
    ll ans=min(count+2,n);
    
    cout<<ans<<endl;
	
	
	return 0;
}

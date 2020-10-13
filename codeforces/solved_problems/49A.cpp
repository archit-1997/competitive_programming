/*Vasya plays the sleuth with his friends. The rules of the game are as follows: those who play for the first time, that is Vasya is the sleuth, he should investigate a "crime" and find out what is happening. He can ask any questions whatsoever that can be answered with "Yes" or "No". All the rest agree beforehand to answer the questions like that: if the question’s last letter is a vowel, they answer "Yes" and if the last letter is a consonant, they answer "No". Of course, the sleuth knows nothing about it and his task is to understand that.

Unfortunately, Vasya is not very smart. After 5 hours of endless stupid questions everybody except Vasya got bored. That’s why Vasya’s friends ask you to write a program that would give answers instead of them.

The English alphabet vowels are: A, E, I, O, U, Y

The English alphabet consonants are: B, C, D, F, G, H, J, K, L, M, N, P, Q, R, S, T, V, W, X, Z
Input

The single line contains a question represented by a non-empty line consisting of large and small Latin letters, spaces and a question mark. The line length does not exceed 100. It is guaranteed that the question mark occurs exactly once in the line — as the last symbol and that the line contains at least one letter.
Output

Print answer for the question in a single line: YES if the answer is "Yes", NO if the answer is "No".

Remember that in the reply to the question the last letter, not the last character counts. I. e. the spaces and the question mark do not count as letters.
Examples
Input
Copy

Is it a melon?

Output
Copy

NO

Input
Copy

Is it an apple?

Output
Copy

YES

Input
Copy

  Is     it a banana ?

Output
Copy

YES

Input
Copy

Is   it an apple  and a  banana   simultaneouSLY?

Output
Copy

YES
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
	
	string s;
	getline(cin,s);
	s.pop_back();
	
	ll n=s.size();
	ll i=n-1;
	
	while(s[i]==' ')
	    i--;
	char ch=toupper(s[i]);
	if(ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U' || ch=='Y')
	    cout<<"YES";
	else
	    cout<<"NO";
	
	return 0;
}

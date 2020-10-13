/*You are given string s. Your task is to determine if the given string s contains two non-overlapping substrings "AB" and "BA" (the substrings can go in any order).
Input

The only line of input contains a string s of length between 1 and 105 consisting of uppercase Latin letters.
Output

Print "YES" (without the quotes), if string s contains two non-overlapping substrings "AB" and "BA", and "NO" otherwise.
Examples
Input
Copy

ABA

Output
Copy

NO

Input
Copy

BACFAB

Output
Copy

YES

Input
Copy

AXBYBXA

Output
Copy

NO

Note

In the first sample test, despite the fact that there are substrings "AB" and "BA", their occurrences overlap, so the answer is "NO".

In the second sample test there are the following occurrences of the substrings: BACFAB.

In the third sample test there is no substring "AB" nor substring "BA".
*/

#include<iostream>
using namespace std;
int main(){
		string s; cin>>s;
		if(s.find("AB")!=-1 && s.find("BA",s.find("AB")+2)!=-1 || s.find("BA")!=-1 && s.find("AB",s.find("BA")+2)!=-1)cout<<"YES";
		else cout<<"NO";
}

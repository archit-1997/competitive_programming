/*Once little Vasya read an article in a magazine on how to make beautiful handmade garland from colored paper. Vasya immediately went to the store and bought n colored sheets of paper, the area of each sheet is 1 square meter.

The garland must consist of exactly m pieces of colored paper of arbitrary area, each piece should be of a certain color. To make the garland, Vasya can arbitrarily cut his existing colored sheets into pieces. Vasya is not obliged to use all the sheets to make the garland.

Vasya wants the garland to be as attractive as possible, so he wants to maximize the total area of ​​m pieces of paper in the garland. Calculate what the maximum total area of ​​the pieces of paper in the garland Vasya can get.
Input

The first line contains a non-empty sequence of n (1 ≤ n ≤ 1000) small English letters ("a"..."z"). Each letter means that Vasya has a sheet of paper of the corresponding color.

The second line contains a non-empty sequence of m (1 ≤ m ≤ 1000) small English letters that correspond to the colors of the pieces of paper in the garland that Vasya wants to make.
Output

Print an integer that is the maximum possible total area of the pieces of paper in the garland Vasya wants to get or -1, if it is impossible to make the garland from the sheets he's got. It is guaranteed that the answer is always an integer.
Examples
Input
Copy

aaabbac
aabbccac

Output
Copy

6

Input
Copy

a
z

Output
Copy

-1

Note

In the first test sample Vasya can make an garland of area 6: he can use both sheets of color b, three (but not four) sheets of color a and cut a single sheet of color c in three, for example, equal pieces. Vasya can use the resulting pieces to make a garland of area 6.

In the second test sample Vasya cannot make a garland at all — he doesn't have a sheet of color z.*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int 

int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s1,s2;
    cin>>s1>>s2;
    
    unordered_map<char,int> store,mala;
    
    for(ll i=0;i<s1.size();i++)
        store[s1[i]]++;
    
    for(ll i=0;i<s2.size();i++)
        mala[s2[i]]++;
        
    ll count=0;
    
    for(auto it=mala.begin();it!=mala.end();it++)
    {
        char ch=it->first;
        
        if(store[ch]==0)
        {
            cout<<-1<<endl;
            return 0;
        }
        else
        {
            if(store[ch]>=mala[ch])
                count+=mala[ch];
            else
                count+=store[ch];
        }
    }
    if(count==0)
        cout<<-1<<endl;
    else
        cout<<count<<endl;
    
    return 0;
}

//this is the kmp algorithm with optimized complexity
#include<bits/stdc++.h> 
using namespace std;

int main(){

    string s;cin>>s;
    int n=s.size();

    vector<int> pi(n,0);

    //by definition, pi[0]=0
    int i,j;
    for(i=1;i<n;i++){
        j=pi[i-1];
        while(j>0 && s[i]!=s[j])
        //this statement will take us to the previous length of the longest common prefix which was also a suffix
            j=pi[j-1];
        if(s[i]==s[j])
            j++;
        pi[i]=j;
    }

    for(int i=0;i<n;i++)
        cout<<pi[i];

    return 0;
}
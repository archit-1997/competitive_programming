/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : fenwickTree.cpp
 * @created     : Sunday Aug 08, 2021 18:22:56 IST
 */

#include <bits/stdc++.h>
using namespace std;

void init(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}

int findNextIndex(int index){
    return (index+(index&-index));
}

int findParent(int index){
    return (index-(index&-index));
}

void constructTree(vector<int> &ft,int val,int index){
    int n=ft.size();
    
    //if we have gone out of bounds
    if(index>=n)
        return;

    ft[index]+=val;
    //find the next index
    int nextIndex=findNextIndex(index);
    constructTree(ft,val,nextIndex);
}

int findSum(vector<int> &ft,int index){
    if(index<=0)
        return 0;
    //find the parent of index
    int parIndex=findParent(index);
    return ft[index]+findSum(ft,parIndex);
}

int main(){

    init();

    int n;cin>>n;

    vector<int> v(n);

    for(int i=0;i<n;i++)
        cin>>v[i];

    //construct a fenwick tree
    vector<int> ft(n+1,0);

    //construct the fenwick tree
    for(int i=1;i<n+1;i++){
        constructTree(ft,v[i-1],i);
    }

    //respond to the sum and update queries
    //0 : sum (index : find the prefix sum from 0 to index)
    //1 : update (index,val : set index i=val)
    int q;cin>>q;
    for(int i=0;i<q;i++){
        int choice;cin>>choice;
        if(choice){
            //this is a sum query
            int index;cin>>index;
            //pass index+1 to the fenwick tree
            int ans=findSum(ft,index+1);
            cout<<ans<<"\n";
        }
        else{
            //this is an update query
            int index,val;cin>>index>>val;
            //find the difference that you have to update
            int diff=v[index]-val;
            //add this diff from the index
            constructTree(ft,v[index-1],index);
        }
    }

    return 0;
}

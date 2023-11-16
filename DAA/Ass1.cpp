#include<bits/stdc++.h>
using namespace std;

int fibo(int n){
   int prev=0;
   int cur=1;
   for(int i=2;i<=n;i++){

    int next=prev+cur;
    prev=cur;
    cur=next;
   }

//    for(int i=0;i<=n;i++){
//     if(i==0 or i==1){
//         cout<<i<<" ";
//     }
//     else{
//         int nxt=prev+cur;
//          prev=cur;
//          cur=nxt;
//         cout<<nxt<<" ";
//     }
//    }
   return cur;
}


int rfibo(int n){
   if(n==0 or n==1){
    return n;
   }
   return rfibo(n-1)+rfibo(n-2);
}

int main(){
    int n;
    cout<<"enter number"<<endl;
    cin>>n;
    cout<<"ifibo "<<fibo(n)<<endl;
// for(int i=0;i<=n;i++){
//    cout<< rfibo(i)<<" ";
// }
// cout<<endl;
    cout<<"rfibo "<<rfibo(n);
}
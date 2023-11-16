#include<bits/stdc++.h>
using namespace std;

bool issafe(int **arr,int x,int y,int n){
    
    for(int row=0;row<x;row++){
        if (arr[row][y]==1)
        return false;
    }

    int row=x;
    int col=y;

    while(row>=0 and col>=0){
        if(arr[row][col]==1){
            return false;
        }
        row--;
        col--;
    }
 row=x;
 col=y;

    while(row>=0 and col<n){
        if(arr[row][col]==1){
            return false;
        }
        row--;
        col++;
    }
    return true;
}


void printboard(int **arr,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]==1){
                cout<<"Q";
            }
            else
            cout<<"-";
            cout<<" ";
        }
        cout<<endl;
    }
}

bool nqueen(int **arr,int row,int n){

if(row==n){
    printboard(arr,n);
    return true;
}
    for(int col=0;col<n;col++){
        if(issafe(arr,row,col,n)){
            arr[row][col]=1;
           if (nqueen(arr,row+1,n))
           {return true;}
            arr[row][col]=0;
        }
    }
    return false;
}



int main(){
    int n;
    cin>>n;
    int **arr=new int*[n];
    for(int i=0;i<n;i++){
        arr[i]=new int[n];
        for(int j=0;j<n;j++){
            arr[i][j]=0;
        }
    }
    nqueen(arr,0, n);
    return 0;
}
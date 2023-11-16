#include<bits/stdc++.h>
using namespace std;

int partition(int arr[],int low,int high){
    int pivot=arr[high];
    int i=low-1;

    for(int j=low;j<high;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}

int randompar(int arr[],int low,int high){
    int randindex=low+(rand()%(high-low));
    swap(arr[randindex],arr[high]);
    return partition(arr,low,high);
}
void quick(int arr[],int low,int high){
    if (low < high)
    {
    int pivot=partition(arr,low,high);
    quick(arr,low,pivot-1);
    quick(arr,pivot+1,high);
    }
}

void rquick(int arr[],int low,int high){
    if (low < high)
    {
    int pivot=randompar(arr,low,high);
    rquick(arr,low,pivot-1);
    rquick(arr,pivot+1,high);
    }
}
int main(){
int n;
cin>>n;
int arr[n],a[n],b[n];
for(int i=0;i<n;i++){
    cin>>arr[i];
    a[i]=arr[i];
    b[i]=arr[i];
}

quick(a,0,n-1);
for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
}
cout<<endl;
rquick(b,0,n-1);
for(int i=0;i<n;i++){
    cout<<b[i]<<" ";
}
    return 0;

}
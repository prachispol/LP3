#include<bits/stdc++.h>
using namespace std;

struct MinHeapNode
{
  char data;
  int freq;
  MinHeapNode *left , *right;
  MinHeapNode(char data,int freq)
  {
      left = right = NULL;
      this->data = data;
      this->freq = freq;
  }
};

void printCodes(struct MinHeapNode *root,string str)
{
    if(root == NULL)
    {
        return;
    }
    if(root->data !='$')
    {
        cout<<root->data << " :" << str <<endl;
    }
    printCodes(root->left , str +"0");
    printCodes(root->right, str +"1");
}

struct Compare{
    bool operator()(MinHeapNode *a,MinHeapNode *b)
    {
        return(a->freq > b->freq);
    }
};

void HuffmanCode(char data[],int freq[],int size)
{
  struct MinHeapNode *left,*right,*temp;
  priority_queue<MinHeapNode *,vector<MinHeapNode *>,Compare>minHeap;
  
  for(int i=0;i<size;i++)
  {
      minHeap.push(new MinHeapNode(data[i],freq[i]));
  }
  
  while(minHeap.size() !=1)
  {
      left = minHeap.top();
      minHeap.pop();
      right = minHeap.top();
      minHeap.pop();
      temp = new MinHeapNode('$',left->freq + right->freq);
      temp->left  = left;
      temp->right = right;
      minHeap.push(temp);
      
  }
  printCodes(minHeap.top()," ");
}

int main()
{
    cout<<"Enter the number of Character :"<<endl;
    int n;
    cin>>n;
    cout<<"Enter the Characters :" <<endl;
    char data[n];
    for(int i=0;i<n;i++)
    {
        cin>>data[i];
    }
    cout<<"Enter the frequency of each Character : "<<endl;
    int freq[n];
    for(int i=0;i<n;i++)
    {
        cin>>freq[i];
    }
    HuffmanCode(data,freq,n);
    return 0;
    
    
}
/*Write a program to perform binary search on an unsorted 
random list of at least 5000 elements. The key 
element should be user input. Use the Divide & Conquer 
method to implement this program*/
#include<iostream>
#include<algorithm>
using namespace std;
int binarySearch(int arr[],int key,int low,int end)
{
if(low<=end)
{
    int mid=low +(end-low)/2;
    if(arr[mid]==key)
    {
    return mid;
    }
    if(arr[mid]>key)
    {
    return binarySearch(arr,key,low,mid-1);
    }
    return binarySearch(arr,key,mid+1,end);
}
    return -1;
}
int main()
{
//taking size as input
cout<<"Size of array"<<endl;
int size;
cin>>size;
int arr[size];
cout<<"elements of array"<<endl;
for(int i=0;i<size;i++)
{
    arr[i] = rand()%1000;
    cout<<arr[i]<<" ";
}
cout<<"\nenter key which you want to search"<<endl;
int key;
cin>>key;

int result=binarySearch(arr,key, 0,size-1);
if(result== -1)
{
cout<<"element not found"<<endl;
}
else{
cout<<"element found at "<<result<<endl;
}
return 0;
}
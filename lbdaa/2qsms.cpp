/*
Implementation the following algorithm using Divide & Conquer method.
(a)Merge sort
(b) Quick Sort
Also display execution time for different size of input and perform the analysis.
*/

#include <bits/stdc++.h>

using namespace std;

void merge(int*arr,int start,int end)
{
     int mid=start+(end-start)/2;
    
     // since we are going to merge two arrays we will create two tempapry arrays

     // the first temp array to store the half values i.e till mid and the second temp array to store the values from mid to end 

    // size of the temp arrays
     int len1= mid-start+1;
     int len2=end-mid;

    //creating the temp arrays

    int *first=new int[len1];
    int *second=new int[len2];

    // coping values into the temporary arrays
    int mainArrayIndex=start;
    for(int i=0;i<len1;i++)
    {
        first[i]=arr[mainArrayIndex++];
       
    }

    mainArrayIndex=mid+1;

    for(int i=0;i<len2;i++)
    {
        second[i]=arr[mainArrayIndex++];
      
    }

    //merging two sorted arrays

    int index1=0;
    int index2=0;
    mainArrayIndex=start;

    while(index1<len1 && index2<len2)
    {
        if(first[index1]<second[index2])
        {
           arr[mainArrayIndex++] = first[index1++];

        }

        else{
                        arr[mainArrayIndex++] = second[index2++];
           
        }   
    }

    while(index1<len1)
    {
         arr[mainArrayIndex++] = first[index1++];
        
    }

     while(index2<len2)
    {
         arr[mainArrayIndex++] = second[index2++];

    }    
    delete []first;
    delete []second;
}


void mergesort(int arr[],int start,int end)
{

        // base case 
        if(start>=end)
        {
            return;
        }
    int mid=start+(end-start)/2;

        // recalling the function for the left part of the array
        mergesort(arr,start,mid);

        // recalling the fucntion for the right part of the array
        mergesort(arr,mid+1,end);

        //calling the merge fucntion
        merge(arr,start,end);

    
}

void print(int*arr,int size)
{
      for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<endl;
    }
}

int main()
{
    time_t start, end;
    time(&start);
    ios_base::sync_with_stdio(false);
    //taking size as input
    cout<<"Size of array"<<endl;
    int size;
    cin>>size;
    int arr[size];
    cout<<"elements of array"<<endl;
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    
cout<<"given array is"<<endl;
 print(arr,size);

mergesort(arr,0,size-1);

cout<<"sorted array is"<<endl;
    print(arr,size);

 
    /*for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<endl;
    }*/
   
   time(&end);
    double time_taken = double(end - start);
    cout <<"Time taken by program is : "<< fixed
         << time_taken << setprecision(5);
    cout <<" sec "<< endl;
    return 0;

}










/* QUICK SORT*//*
Implementation the following algorithm using Divide & Conquer method.
(a)Merge sort
(b) Quick Sort
Also display execution time for different size of input and perform the analysis.
*/

// #include<bits/stdc++.h>

// using namespace std;

// void swap(int* a, int* b) 
// { 
//     int t = *a; 
//     *a = *b; 
//     *b = t; 
// } 
  
// /* This function takes last element as pivot, places 
// the pivot element at its correct position in sorted 
// array, and places all smaller (smaller than pivot) 
// to left of pivot and all greater elements to right 
// of pivot */
// int partition (int arr[], int low, int high) 
// { 
//     int pivot = arr[high]; // pivot 
//     int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
  
//     for (int j = low; j <= high - 1; j++) 
//     { 
//         // If current element is smaller than the pivot 
//         if (arr[j] < pivot) 
//         { 
//             i++; // increment index of smaller element 
//             swap(&arr[i], &arr[j]); 
//         } 
//     } 
//     swap(&arr[i + 1], &arr[high]); 
//     return (i + 1); 
// } 
  
// /* The main function that implements QuickSort 
// arr[] --> Array to be sorted, 
// low --> Starting index, 
// high --> Ending index */
// void quickSort(int arr[], int low, int high) 
// { 
//     if (low < high) 
//     { 
//         /* pi is partitioning index, arr[p] is now 
//         at right place */
//         int pi = partition(arr, low, high); 
  
//         // Separately sort elements before 
//         // partition and after partition 
//         quickSort(arr, low, pi - 1); 
//         quickSort(arr, pi + 1, high); 
//     } 
// } 
   


// void print(int*arr,int size)
// {
//       for(int i=0;i<size;i++)
//     {
//         cout<<arr[i]<<endl;
//     }
// }

// int main()
// {
//     time_t start, end;
//     time(&start);
//     ios_base::sync_with_stdio(false);

//     //taking size as input
//     cout<<"Size of array"<<endl;
//     int size;
//     cin>>size;
//     int arr[size];
//     cout<<"elements of array"<<endl;
//     for(int i=0;i<size;i++)
//     {
//         cin>>arr[i];
//     }

// cout<<"given array is"<<endl;
//  print(arr,size);

// quickSort(arr,0,size-1);

// cout<<"Sorted Array is"<<endl;
// print(arr,size);

//      /*for(int i=0;i<size;i++)
//     {
//         cout<<arr[i]<<endl;
//     }*/
   
//    time(&end);
//     double time_taken = double(end - start);
//     cout <<"Time taken by program is : "<< fixed
//          << time_taken << setprecision(5);
//     cout <<" sec "<< endl;
//     return 0;

// }
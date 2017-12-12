



	
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
/*******************************************************************************
 * This program is intended to combine two fixed array elements
 * and put them into a dynamic array,after the the sorting.
 * and copy the element to a new fixed array.
 
The correct output is supposed to be the following:
===============================================================================
Creating some fixed array.
Creating some new dynamic array.
Fill dynamic array with first two fixed array.
Copy the sorted dynamic array into a new fixed array.
Print result
1
2
3
4
5
6
7
8
9
10
New array is sorted.
================================================================================
 
 
 * 
 * There are some problems with this program, use valgrind to check the program 
 * and you should fix the program with no errors and memory leak.
 * 
 * 
 * 
 * ***************************************************************************/
 
 
 
using namespace std;
 
int main()
{
     
    cout<<"Creating some fixed array."<<endl;
    int fixed_array1 [3]={1,2,3};
    int fixed_array2 [7]={10,9,8,7,6,5,4};
    int fixed_array3 [10];
   
    cout<<"Creating some new dynamic array."<<endl;
    int fixed_array1_size=sizeof(fixed_array1)/sizeof(fixed_array1[0]);
    int fixed_array2_size=sizeof(fixed_array2)/sizeof(fixed_array2[0]);
    int fixed_array3_size=sizeof(fixed_array3)/sizeof(fixed_array3[0]);
    int dynamic_arrary_size=fixed_array1_size+ fixed_array2_size;
    int new_dynamic_array[dynamic_arrary_size];
 
    cout<<"Fill dynamic array with first two fixed array."<<endl;
    for(int i=0; i<fixed_array1_size;i++){
      new_dynamic_array[i]=fixed_array1[i];
    }
 
    for(int j=0;j<fixed_array2_size;j++){
      new_dynamic_array[fixed_array1_size+j]=fixed_array2[j];
    }
              
    /*sort the dynamic array*/   
    std::sort(new_dynamic_array,new_dynamic_array+dynamic_arrary_size);
     
    cout<<"Copy the sorted dynamic array into a new fixed array."<<endl;
    for(int i=0; i<fixed_array3_size;i++){
      fixed_array3[i]=new_dynamic_array[i];
    }
         
    cout<<"Print result"<<endl;
    bool is_sorted = true;
    for(int i=0;i<fixed_array3_size;i++){
     cout<< fixed_array3[i]<<endl;
     if(i<fixed_array3_size&&fixed_array3[i]>fixed_array3[i+1]){
       is_sorted=false;
     }
    }
     
    if(is_sorted){
    cout<<"New array is sorted."<<endl;
    }    
     
    return 0;
}


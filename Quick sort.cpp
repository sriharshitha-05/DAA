#include<iostream>
using namespace std;

int partition(int arr[],int low,int high)
{
	int pivot = arr[high];
	int i=low-1;
	for(int j=low;j<high;j++)
	{
		if(arr[j]<pivot)
		{
			i++;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[i+1],arr[high]);
	return (i+1);
}

void quickSort(int arr[],int low,int high)
{
	if(low<high)
	{
		int pivotIndex=partition(arr,low,high);
	    quickSort(arr,low,pivotIndex-1);
	    quickSort(arr,pivotIndex+1,high);
	}
}

void printArray(int arr[],int size)
{
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
	
int main()
{
	int a[10];
	int n,i;
	cout<<"Enter array size";
	cin>>n;
	cout<<"Enter array elements"<<endl;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<"Original Array:";
	printArray(a,n);
	
	quickSort(a,0,n-1);
	
	cout<<"Sorted Array:";
	printArray(a,n);
	return 0;
}

#include<iostream>
using namespace std;

void merge(int a[],int low,int mid,int high)
{
	int i=low,j=mid+1,k=0;
	
	int temp[100];
	
	while(i<=mid&&j<=high)
	{
		if(a[i]<a[j])
		{
			temp[k++]=a[i++];
		}
		else
		{
			temp[k++]=a[j++];
		}
	}
	
	while(i<=mid)
	{
		temp[k++]=a[i++];
	}
	
	while(j<=high)
	{
		temp[k++]=a[j++];
	}
	
	for(int x=low;x<=high;x++)
	{
		a[x]=temp[x-low];
	}
}

void mergeSort(int a[],int low,int high)
{
	if(low<high)
	{
		int mid=(low+high)/2;
		mergeSort(a,low,mid);
		mergeSort(a,mid+1,high);
		merge(a,low,mid,high);
	}
}

int main()
{
	int n,a[20];
	
	cout<<"Enter array size:";
	cin>>n;
	
	cout<<"Enter array elements:\n";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<"Original array:";
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	
	mergeSort(a,0,n-1);
	
	cout<<"\nSorted array:";
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	
	return 0;
}

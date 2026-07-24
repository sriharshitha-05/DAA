#include<iostream>
using namespace std;

int merge(int a[],int low,int mid,int high)
{
	int i=low,j=mid+1,k=0;
	int count=0;
	
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
			count+=(mid-i+1);
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
	
	return count;
}

int mergeSort(int a[],int low,int high)
{
	int count=0;
	if(low<high)
	{
		int mid=(low+high)/2;
		count+=mergeSort(a,low,mid);
		count+=mergeSort(a,mid+1,high);
		count+=merge(a,low,mid,high);
	}
	return count;
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
	
	int result=mergeSort(a,0,n-1);
	
	cout<<"\nNumber of inversions:"<<result;
	
	
	return 0;
}

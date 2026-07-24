#include<iostream>
using namespace std;

int binarySearch(int a[],int x,int low,int high)
{
	if(low>high)
	{
		return -1;
	}
	else {
	    int mid=(low+high)/2;
	    
	    if(x==a[mid])
	    {
	    	return mid;
		}
		else if(x>a[mid])
		{
			return binarySearch(a,x,low,mid);
		}
		else
		{
			return binarySearch(a,x,mid+1,high);
		}
	}
}

int main()
{
	int a[10],n,x;
	
	cout<<"Enter array size:";
	cin>>n;
	
	cout<<"Enter array elements:";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
    cout<<"Enter a element to search:";
    cin>>x;
    
    int index=binarySearch(a,x,0,n-1);
    
    if(index!=-1)
    {
    	cout<<"Element not found."<<endl;
	}
	else
	{
		cout<<"Element found at position:"<<index+1<<endl;
	}
	
    return 0;
}

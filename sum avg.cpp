#include<iostream>
using namespace std;

int main()
{
	int n,sum=0,x;
	float avg=0;
	
	cout<<"Enter number of elements:";
	cin>>n;
	
	cout<<"Enter the elements:"<<endl;
	
	for(int i=0;i<n;i++)
	{ 
	    cin>>x;
		sum+=x;
	}
	
	cout<<"Sum="<<sum<<endl;
	
	avg=sum/n;
	
	cout<<"Average:"<<avg<<endl;
	
	return 0;
}

#include<iostream>
using namespace std;

int main()
{
	int n;
	
	cout<<"Enter a number:";
	cin>>n;
	
	if(n>0&&(n&(n-1))==0)
	{
		cout<<n<<" is in powers of 2";
	}
	else{
		cout<<n<<" not in powers of 2";
	}
}

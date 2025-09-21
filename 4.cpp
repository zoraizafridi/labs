#include<iostream>
using namespace std;
int main()
{
	int size;
	cout<<"Enter the size of array:";
	cin>>size;
	int *arr=new int[size];
	int key;
	cout<<"Enter the elements of array:";
	for(int i=0; i<size; i++)
	{
		cin>>arr[i];
	}
	cout<<endl;
	cout<<"Array is"<<endl;
	for(int i=0; i<size; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	cout<<"Enter the key for searching:";
	cin>>key;
	bool found=false;
	int l=0;
	int u=size-1;
	while(l<=u)
	{
		int mid=(l+u)/2;
		if(arr[mid]==key)
		{
			cout<<"Key found at index:"<<mid;
			found=true;
			break;
		}
		else if(arr[mid]<key){
			l=mid+1;
		}
		else{
		    u=mid-1;
		}
	}
	if(!found)
	{
		cout<<"Key not found";
	}
	return 0;
}
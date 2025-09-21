#include<iostream>
using namespace std;
int main()
{
	int rows,cols;
	cout<<"Enter the size of rows:";
	cin>>rows;
	cout<<"Enter the size of cols:";
	cin>>cols;
	int **arr=new int*[rows];
	for(int i=0; i<rows; i++)
	{
		arr[i]=new int[cols];
	}
	cout<<"Enter the elements of matrix in ascending order";
	cout<<endl;
	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<cols; j++)
		{
			cin>>arr[i][j];
		}
	}
	cout<<"Matrix is"<<endl;
	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<cols; j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	int key;
	cout<<"Enter the key for searching:";
	cin>>key;
	bool found=false;
	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<cols; j++)
		{
			if(arr[i][j]==key)
			{
				found=true;
				break;
			}
			
		}
	}
	if(found)
	{
		cout<<"True";
	}
	else{
		cout<<"False";
	}
	return 0;
}
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
	cout<<"Enter the elements of array"<<endl;
	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<cols; j++)
		{
		cin>>arr[i][j];
		}
	}
	cout<<endl;
	cout<<"The elements of 2D array are"<<endl;
	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<cols; j++)
		{
			cout<<" "<<arr[i][j];
		}
		cout<<endl;
	}
	int index=0;
	int *arrcpy=new int[rows*cols];
	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<cols; j++)
	{
	arrcpy[index++]=arr[j][i];
	}
	}
	cout<<"1D array"<<endl;
	for(int i=0; i<index; i++)
	{
		cout<<arrcpy[i]<<" ";
	}
	return 0;
}
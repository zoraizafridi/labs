#include<iostream>
using namespace std;
class Median{
	private:
	int* arr;
	int size;
	int capacity;
	int findposition(int num)
	{
	int l=0; int u=size-1;
	while(l<=u)
	{
		int mid=(l+u)/2;
		if(arr[mid]==num)
		{
			return mid;
		}
		else if(arr[mid]<num){
			l=mid+1;
		}
		else{
			u=mid-1;
		}
	}
	return l;
    }
	public:
		Median(int cap=1000){
		capacity=cap;
		arr=new int[capacity];
		size=0;
		}
		void addnum(int num)
		{
			if(size==capacity)
			{
				cout<<"Capacity full"<<endl;
				return;
			}
			int pos=findposition(num);
			for(int i=size; i>pos; i--)
			{
				arr[i]=arr[i-1];
			}
			arr[pos]=num;
			size++;
		}
		double getmedian()
		{
			if(size==0)
			{
				return 0.00;
			}
			else if(size%2==1){
				return arr[size/2];
			}
			else{
				return (arr[(size-1)/2]+arr[size/2])/2.0;
			}
		}
		~Median()
		{
			delete[] arr;
		}
};
int main()
{
	Median m;
	m.addnum(3);
	m.addnum(4);
	m.addnum(7);
	m.addnum(9);
	cout<<"Median= "<<m.getmedian()<<endl;
	m.addnum(30);
	cout<<"Median= "<<m.getmedian();
	return 0;
}
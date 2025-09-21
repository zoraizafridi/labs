#include<iostream>
using namespace std;
int main()
{
	struct Student{
		float* gpas;
		float finalgpa;
	};
	string subjects[]={"Data Structure","Programming for AI","Digital Logic Design","Probability & Statistics","Finance & Accounting"};
	int s=5; //no of subjects
	string name[]={"Ali","Hiba","Asma","Zain","Faisal"};
	int n=5; //no of students
	Student students[n];
	for(int i=0; i<n; i++)
	{
		students[i].gpas=new float[s];
	}
	for(int i=0; i<n; i++)
	{
		float sum=0;
		cout<<"Enter gpas for "<<name[i]<<endl;
		for(int j=0; j<s; j++)
		{
			cout<<subjects[j]<<": ";
			cin>>students[i].gpas[j];
			sum+=students[i].gpas[j];
		}
		students[i].finalgpa=sum/s;
		cout<<endl;
	}
	cout<<"Final gpa"<<endl;
	for(int i=0; i<n; i++)
	{
		cout<<"Name "<<name[i]<<"-> "<<students[i].finalgpa<<endl;
	}
	for(int i=0; i<n; i++)
	{
		delete[] students[i].gpas;
	}
	return 0;
}
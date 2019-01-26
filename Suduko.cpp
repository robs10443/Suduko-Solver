#include<iostream>
#define Suduko_Size 9
using namespace std;
class Suduko
{
	int mat[Suduko_Size][Suduko_Size];
	public:
	Suduko()
	{
		for (int i=0;i<Suduko_Size;i++)
			for (int j=0;j<Suduko_Size;j++)
				cin>>mat[i][j];
	}
	Suduko(int n)
	{
		for (int i=0;i<Suduko_Size;i++)
			for (int j=0;j<Suduko_Size;j++)
				mat[i][j]=n;
	}
	bool isFull()
	{
		for (int i=0;i<Suduko_Size;i++)
			for (int j=0;j<Suduko_Size;j++)
				if(mat[i][j]==0)
					return false;
		return true;
	}
	bool valid()
	{
		int hash[Suduko_Size]={0};
		for (int i=0;i<Suduko_Size;i++)
			for (int j=0;j<Suduko_Size;j++)
				if(mat[i][j]>=0 && mat[i][j]<=Suduko_Size)
					hash[mat[i][j]-1]++;
		
		for (int i=0;i<Suduko_Size;i++)
			if(hash[i]!=Suduko_Size)
				return false;
		
		return true;
	}
	bool safe(int r,int c,int num)
	{
		
		for (int i=0;i<Suduko_Size;i++)
			if(mat[r][i]==num)
				return false;
		
		for (int i=0;i<Suduko_Size;i++)
			if(mat[i][c]==num)
				return false;
		
		for (int i=0;i<3;i++)
			for (int j=0;j<3;j++)
				if(mat[i+r-r%3][j+c-c%3]==num)
					return false;
		
		return true;			
	
	}
	pair<int,int> vacant()
	{
		pair<int,int> p;
		for (int i=0;i<Suduko_Size;i++)
		for (int j=0;j<Suduko_Size;j++)
			if(mat[i][j]==0)
			{
				p.first=i;
				p.second=j;
			}
		return p;
	}
	bool solve()
	{
		if(isFull())
			return true;
		pair<int,int> p = vacant();
		for (int i=1;i<=Suduko_Size;i++)
		{
			if(safe(p.first,p.second,i))
			{
				mat[p.first][p.second]=i;
				if(solve())
					return true;
				mat[p.first][p.second]=0;
			}
		}
		return false;
	}
	void display()
	{
		cout<<"\n\n\n\tSuduko Solved\n\n";
		for (int i=0;i<Suduko_Size;i++)
		{
			if( i && i%3==0 )
				cout<<"------ ------- ------\n";
			for (int j=0;j<Suduko_Size;j++)
			{
				if(j && j%3==0)
					cout<<"| "<<mat[i][j]<<" ";
				else
					cout<<mat[i][j]<<" ";
			}
			cout<<endl;
		}
	}
};
int main()
{
	Suduko sd;
	if(sd.solve())
	{
		if(sd.valid())
		{	
			sd.display();
			return 0;
		}
	}
	cout<<"\n\n\t\tNot a valid Suduko\n\n\n";
}

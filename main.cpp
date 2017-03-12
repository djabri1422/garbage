#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

class tmatrix
{
private:
	int **p;
	int n,m;
public:
	tmatrix();
	tmatrix(int , int);
	~tmatrix();
	void fill(string);
	void print();
	tmatrix operator+(tmatrix)const;
	tmatrix operator*(tmatrix)const;
	tmatrix operator=(tmatrix)const;
	tmatrix(tmatrix &tmatcmp);
};

tmatrix::tmatrix()
{
	n=0;
	m=0;
}

tmatrix::tmatrix(int xSize, int ySize)
{
	p = new int *[ySize];
	for (int count = 0; count < ySize; count++)
		p[count] = new int[xSize];
	n = xSize;
	m = ySize;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
		p[i][j] = 0;
		}
	}
}

void tmatrix::fill(string name_1 )
{
	ifstream file(name_1);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			file>>p[i][j];
		}
	}
}

void tmatrix::print()
{
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<p[i][j]<<"  ";
		}
		cout<<"\n";
	}
	cout<<"\n"<<flush;
}

tmatrix::tmatrix(tmatrix&tmatrixcmp)
{
	n = tmatrixcmp.n;
	m = tmatrixcmp.m;
	p = new int*[n];
	for (int i = 0; i < n; i++) {
		p[i] = new int[m];
		for (int j = 0; j < m; j++) {
			p[i][j] = tmatrixcmp.p[i][j];
		}
	}
}

tmatrix tmatrix::operator+(tmatrix tmatrixcmp) const
{
	tmatrix re(n, m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
		re.p[i][j] = p[i][j] + tmatrixcmp.p[i][j];
		}
	}
	return re;
}

tmatrix tmatrix::operator*(tmatrix tmatrixcmp)const
{
		tmatrix re(n, m);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			re.p[i][j] = 0;
			for (int k = 0; k < m; k++)
				re.p[i][j] += p[i][k] * tmatrixcmp.p[k][j];
		}	
	}
	return re;
}

tmatrix::~tmatrix()
{
		for (int i = 0; i < n; i++){
		delete[] p[i];
	}
	delete[] p;
}

int main()
{
	setlocale(LC_ALL,"rus");
	string name_1;
	int ySize ,xSize;
	cout<<"¬ведите навание файла: ";
	getline(cin,name_1);
	cout << "Number of lines: ";
	cin >> ySize;
	cout << "Number of columns: ";
	cin >> xSize;
	tmatrix tmatrix_1(xSize,ySize);
	tmatrix_1.fill(name_1);
	tmatrix_1.print();
	tmatrix tmatrix_2(xSize,ySize);
	tmatrix_2.fill(name_1);
	tmatrix_2.print();
	tmatrix Sum = tmatrix_1 + tmatrix_2;
	Sum.print();
	tmatrix Comp = tmatrix_1*tmatrix_2;
	Comp.print();
	system("pause");
}

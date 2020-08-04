#include "Matrix.h"

matrix::matrix()
{
	M = { {} };
}

matrix::matrix(int m, int n)
{
	//TO_DO: Use std::cin to initialize a matrix of size m * n
	M.resize(m);

	for(int i=0;i<m;i++)
		M[i].resize(n);

	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			cin>>M[i][j];
}

matrix::matrix(vector<vector<int>>& m)
{
	M = m;
}

bool matrix::IsSameShape(matrix m1)
{
	return (!(M.size()==m1.M.size()&&M[0].size()==m1.M[0].size()));
}

void matrix::Add(matrix m1)
{
	if(IsSameShape(m1))
	{
		cout << "Not the same shape" << endl;
	}
	else
	{
		for(unsigned int i=0;i<M.size();i++)
			for(unsigned int j=0;j<M[0].size();j++)
				M[i][j]+=m1.M[i][j];
		cout << "m1+m2 :" << endl;
		this->Print();
	}
	return;
}

void matrix::Sub(matrix m1)
{
	if(IsSameShape(m1))
	{
		cout << "Not the same shape" << endl;
	}
	else
	{
		for(unsigned int i=0;i<M.size();i++)
			for(unsigned int j=0;j<M[0].size();j++)
				M[i][j]-=m1.M[i][j];
		cout << "m1-m2 :" << endl;
		this->Print();
	}
}

matrix matrix::Mul(matrix m1)
{
	if (M[0].size() != m1.M.size()) 
	{
		cout << "Cannot do multiplication!" << endl;
		return matrix();
	}
	else 
	{
		//TO_DO: Multiply two matrices and print the result.
		matrix tmp;
		tmp.M.resize(M.size());
		for(unsigned int i=0;i<M.size();i++)
			tmp.M[i].resize(m1.M[0].size());
		for(unsigned int i=0;i<M.size();i++)
		{
			for(unsigned int j=0;j<m1.M[0].size();j++)
			{
				int sum=0;
				for(unsigned int k=0;k<M[0].size();k++)
				{
					sum+=M[i][k]*m1.M[k][j];
				}
				tmp.M[i][j]=sum;
			}
		}
		cout << "m1*m2 :" << endl;
		return tmp;
	}

}

void matrix::Inverse()
{
	vector<vector<int>> adj;
	adj.resize(M.size());
	for(unsigned int i=0;i<adj.size();i++)
		adj[i].resize(M.size());

	if(M.size()!=2)
	{
		vector<vector<int>> tmp;
		tmp.resize(M.size()-1);
		for(unsigned int i=0;i<tmp.size();i++)
			tmp[i].resize(M.size()-1);
		
		//force
		bool sgn=1;
		for(unsigned int i=0;i<M.size();i++)
			for(unsigned int j=0;j<M.size();j++)
			{
				for(unsigned int ii=0,indexi=0;ii<M.size();ii++)
				{
					if(ii==i)continue;
					for(unsigned int jj=0,indexj=0;jj<M.size();jj++)
					{
						if(jj==j)continue;
						tmp[indexi][indexj]=M[ii][jj];
						indexj++;
					}
					indexi++;
				}
				adj[i][j]=(sgn?1:-1)*Det(tmp);
				//sum+=(sgn?1:-1)*m[0][j]*Det(tmp);
				sgn^=1;
			}
		for(int i=0;i<M.size();i++)
			for(int j=i;j<M.size();j++)
				swap(adj[i][j],adj[j][i]);
	}
	else
	{
		adj[0][0]=M[1][1];
		adj[1][1]=M[0][0];
		adj[0][1]=-M[0][1];
		adj[1][0]=-M[1][0];
	}
	int det=Det(M);
	
	if (!SquareMatrix()||det==0)
		cout << "Not a Square Matrix" << endl;
	else
	{
		cout<<"Inverse Matrix:\n(1/"<<det<<") *\n";
		matrix(adj).Print();
	}
	return;
}

bool matrix::SquareMatrix()
{
	//TO_DO: Return true if matrix is a square matrix, otherwise return fasle.
		return M.size()!=0&&M.size()==M[0].size();
}

void matrix::GetDet()
{
	if (!SquareMatrix())
		cout << "Not a Square Matrix" << endl;
	else
		cout << "Determinant of matrix : " << Det(M) << endl;
	
}

int matrix::Det(vector<vector<int>>& m)
{
	if(m.size()==2)
	{
		return m[0][0]*m[1][1]-m[1][0]*m[0][1];
	}

	//TO_DO: Compute the determinant of matrix m.
	int sum=0;
	vector<vector<int>> tmp;
	tmp.resize(m.size()-1);
	for(unsigned int i=0;i<tmp.size();i++)
		tmp[i].resize(m.size()-1);
	
	//force
	bool sgn=1;
	for(unsigned int j=0;j<m.size();j++)
	{
		for(unsigned int ii=1,indexi=0;ii<m.size();ii++)
		{
			for(unsigned int jj=0,indexj=0;jj<m.size();jj++)
			{
				if(jj==j)continue;
				tmp[indexi][indexj]=m[ii][jj];
				indexj++;
			}
			indexi++;
		}
		sum+=(sgn?1:-1)*m[0][j]*Det(tmp);
		sgn^=1;
	}
	return sum;
}

void matrix::Print()
{
	for (unsigned int i = 0; i < M.size(); i++) {
		for (unsigned int j = 0; j < M[0].size(); j++) {
			cout << M[i][j] << " ";
		}
		cout << endl;
	}
}

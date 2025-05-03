#include<bits/stdc++.h>
using namespace std;

//打印 
void print(vector<vector<int>>& matrix)
{
	cout << "------------------------------" << endl;
	for(int i=0;i<matrix.size();++i) {
		for(int j=0;j<matrix[0].size();++j) {
			cout << setw(4) << matrix[i][j];
		}
		cout << endl;
	}
	cout << "------------------------------" << endl;
}
//朴素转置 
void transpose(vector<vector<int>>& transposeMatrix,vector<vector<int>>& matrix)
{
	for(int i=0;i<transposeMatrix.size();++i) {
		for(int j=0;j<transposeMatrix[0].size();++j) {
			transposeMatrix[i][j] = matrix[j][i];
		}
	}
}
//快速转置
void quicktranspose(vector<tuple<int,int,int>> &dataMatrix,pair<int,int> &pairMatrix,
					vector<tuple<int,int,int>> &dataTransposeMatrix,pair<int,int> &pairTransposeMatrix)
{
		pairTransposeMatrix.first = pairMatrix.second;
		pairTransposeMatrix.second = pairMatrix.first;
		
		//方法*****
		vector<int> num(pairMatrix.second,0);
		vector<int> copt(pairMatrix.second,0);
		for(int i=0;i<dataMatrix.size();++i) {
			int col = get<1>(dataMatrix[i]);
			++num[col];
		}
		copt[0] = 0;
		for(int i=1;i<pairMatrix.second;++i) {
			copt[i] = copt[i-1]+num[i-1]; 
		}
		for(int i=0;i<dataMatrix.size();++i) {
			int col = get<1>(dataMatrix[i]);
			int q = copt[col];
			int first = get<1>(dataMatrix[i]);
			int second = get<0>(dataMatrix[i]);
			int third = get<2>(dataMatrix[i]);
			dataTransposeMatrix[q] = make_tuple(first,second,third);
			++copt[col];
		}
		//问题 
		/*
		for(int i=0;i<dataMatrix.size();++i) {
			int first = get<1>(dataMatrix[i]);
			int second = get<0>(dataMatrix[i]);
			int third = get<2>(dataMatrix[i]);
			dataTransposeMatrix[i] = make_tuple(first,second,third);
		}*/
 } 
//压缩
void press(vector<vector<int>> matrix,pair<int,int> &pairMatrix,vector<tuple<int,int,int>> &dataMatrix)
{
	pairMatrix.first = matrix.size();
	pairMatrix.second = matrix[0].size(); 
	for(int i=0;i<matrix.size();++i) {
		for(int j=0;j<matrix[0].size();++j) {
			if(matrix[i][j]!=0) dataMatrix.emplace_back(make_tuple(i,j,matrix[i][j]));
		}
	}
} 
//解压缩 
vector<vector<int>> depress(vector<tuple<int,int,int>> &data,pair<int,int> &p)
{
	vector<vector<int>> tem(p.first,vector<int>(p.second,0));
	for(auto &triple:data) {
		int i = get<0>(triple);
		int j = get<1>(triple);
		int v = get<2>(triple);
		tem[i][j] = v;
	}
	return tem;
}

int main()
{	vector<vector<int>> matrix = {{0,12,9,0,0,0,0},
				 {0,0,0,0,0,0,0},
				 {-3,0,0,0,0,14,0},
				 {0,0,24,0,0,0,0},
				 {0,18,0,0,0,0,0},
				 {15,0,0,-7,0,0,0}};
	vector<vector<int>> transposeMatrix(7,vector<int>(6));
	
	print(matrix);
	transpose(transposeMatrix,matrix);
	print(transposeMatrix);
	
	vector<tuple<int,int,int>> dataMatrix;
	pair<int,int> pairMatrix;
	press(matrix,pairMatrix,dataMatrix);
	for(auto &triple: dataMatrix) {
		int i = get<0>(triple);
		int j = get<1>(triple);
		int v = get<2>(triple);
		cout << i << " " << j << " " << v << endl;
	}
	cout << "-------------------------------------------"<<endl;
	vector<tuple<int,int,int>> dataTransposeMatrix(dataMatrix.size());
	pair<int,int> pairTransposeMatrix;
	quicktranspose(dataMatrix,pairMatrix,dataTransposeMatrix,pairTransposeMatrix);
	for(auto &triple: dataTransposeMatrix) {
		int i = get<0>(triple);
		int j = get<1>(triple);
		int v = get<2>(triple);
		cout << i << " " << j << " " << v << endl;
	}
	cout << "-------------------------------------------"<<endl;
	sort(dataTransposeMatrix.begin(),dataTransposeMatrix.end());
	for(auto &triple: dataTransposeMatrix) {
		int i = get<0>(triple);
		int j = get<1>(triple);
		int v = get<2>(triple);
		cout << i << " " << j << " " << v << endl;
	}
	vector<vector<int>> newMatrix = depress(dataTransposeMatrix,pairTransposeMatrix);
	print(newMatrix);
	return 0;
}

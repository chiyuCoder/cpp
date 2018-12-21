const int defaultSize = 100;
template <class T>
class SparseMatrix
{
		friend ostream &operator<<(ostream &os, SparseMatrix<T> M);
		friend istream &operator<<(istream &is, SparseMatrix<T> M);

	public:
		SparseMatrix(int maxSize = defaultSize): maxTerms(maxSize) 
		{
			if (maxSize < 1) {
				cerr << "" << endl;
				exit(1);
			}
			smArray = new Trituple<T>[maxSize];
			if(smArray == NULL) {
				cerr << "存储分配错误" << endl;
				exit(1);
			}
			Rows = 0;
			Cols = 0;
			Terms = 0;
		};
		SparseMatrix(SparseMatrix<T> &x) 
		{
			maxTerms = x.maxTerms;
			smArray = new Trituple<T>[maxTerms];
			if (smArray == NULL) {
				exit(1);
			}
			
			Rows = x.Rows;
			Cols = x.Cols;
			Terms = x.Terms;
			for (int i = 0; i < Terms; i ++)
			{
				smArray[i] = x.smArray[i];
			}
		};
		~SparseMatrix()
		{
			delete[] smArray;
		};
		SparseMatrix<T> &operator=(SparseMatrix<T> &x);
		//对当前稀疏矩阵对象( *this 指示） 执行转置运算。
		SparseMatrix<T> Transpose(){
			SparseMatrix<T> b(maxTerms);
			b.Rows = Cols;
			b.Cols = Rows;
			b.Terms = Terms;
			if (Terms > 0) {
				int k, i, currentB = 0;
				for (k = 0; k < Cols; k ++)
				{
					for (i = 0; i < Terms; i ++)
					{
						if (smArray[i].col == k) {
							b.smArray[currentB].row = k;
							b.smArray[currentB].col = smArray[i].row;
							b.smArray[currentB].value = smArray[i].value;
							currentB++;
						}
					}
				}
			}
			return b;
		};
		SparseMatrix<T> FastTranspose() 
		{
			SparseMatrix<T> b(maxTerms);
			b.Rows = Cols;
			b.Cols = Rows;
			b.Terms = Terms;
			if (Terms > 0) {
				int i, j;
				int *rowSize = new int[Cols];
				int *rowStart = new int[Cols];
				for (int i = 0; i < Cols; i++)
				{
					rowSize[i] = 0;
				}
				for (i = 0; i < Terms; i++)
				{
					rowSize[smArray[i].col]++;
				}
				rowStart[0] = 0;
				for (i = 1; i < Cols; i++)
				{
					rowSize[i] = rowStart[i - 1] + rowSize[i - 1];
				}
				for (i = 0; i < Terms; i++)
				{
					j = rowStart[smArray[i].col];
					b.smArray[j].row = smArray[i].col;
					b.smArray[j].col = smArray[i].row;
					b.smArray[j].value = smArray[i].value;
					rowStart[smArray[i].col]++;
				}
				delete[] rowSize;
				delete[] rowStart;
				return b;
			}
		}
		SparseMatrix<T> Add(SparseMatrix<T> &b); //当前稀疏矩阵对象( *this 指示）与矩阵b相加

	private:
		Trituple<T> *smArray;
		int Rows, Cols, Terms;
		int maxTerms;
};
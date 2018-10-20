int maxIncreaseKeepingSkyline（Array[], int row, int col）
{
	for(int i = 0; i < row; i ++)
	{
		for(int j = 0; j < col; j ++)
		{	
			row[i] = max(row[i], Array[i][j]);
			col[j] = min(col[j], Array[i][j]);
		}
	}
	for(int i = 0; i < row; i ++)
	{
		for(int j = 0; j < col; j ++)
		{
			res += min(row[i] - Array[i][j], col[j] - Array[i][j]);
		}
	}
	return res;
}
bool find_empty(vector<vector<char> > &A,int &row,int &col)
{
    for(row=0;row<9;row++)
    {
        for(col=0;col<9;col++)
        {
            if(A[row][col]=='.') return 1;
        }
    }
    return 0;
}
bool inrow(vector<vector<char> > &A,int row,int col,char val)
{
    for(int c=0;c<9;c++)
    {
        if(A[row][c]==val) return true;
    }
    return false;
}
bool incol(vector<vector<char> > &A,int row,int col,char val)
{
    for(int r=0;r<9;r++)
    {
        if(A[r][col]==val) return true;
    }
    return false;
}
bool insub(vector<vector<char> > &A,int row,int col,char val)
{
    for (int r = 0; r < 3; r++)  
        for (int c = 0; c < 3; c++)  
            if (A[r + row] 
                    [c + col] == val)  
                return true;  
    return false;
}
bool isSafe(vector<vector<char> > &A,int row,int col,char val)
{
    return !inrow(A,row,col,val) && !incol(A,row,col,val) && !insub(A,row-row%3,col-col%3,val);
}
bool solveit(vector<vector<char> > &A)
{
    int row=0,col=0;
    if(!find_empty(A,row,col))  return true;
    for(int t=1;t<=9;t++)
    {
        if(isSafe(A,row,col,'0'+t))
        {
            A[row][col]='0'+t;
            if(solveit(A)) return true;
            A[row][col]='.';
        }
    }
    return false;
}
void Solution::solveSudoku(vector<vector<char> > &A) 
{
    bool an = solveit(A);    
}
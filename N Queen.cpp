bool safe(vector<pair<int,int> > sell,int r,int c)
{
    for(int i=0;i<sell.size();i++)
    {
        if(sell[i].first==r) return false;
        if(sell[i].second==c) return false;
        if(sell[i].first-sell[i].second == r-c) return false;
        if(sell[i].first+sell[i].second == r+c) return false;
    }
    return true;
}
//void print
bool solveit(vector<vector<string> > &an, vector<string> &sqr, int col, int A, vector<pair<int,int> > &sell)
{
    if(col==A)
    {
        an.push_back(sqr);
        return true;
    }
    for(int i=0;i<A;i++)
    {
        if(safe(sell,i,col) || col==0)
        {
            sqr[i][col]='Q';
            sell.push_back({i,col});
            solveit(an,sqr,col+1,A,sell);
            sell.pop_back();
            sqr[i][col]='.';
        }
    }
    return false;
}
vector<vector<string> > Solution::solveNQueens(int A) 
{
    vector<vector<string> >an;
    vector<string> sqr;
    for(int i=0;i<A;i++)
    {   
        string s="";
        for(int j=0;j<A;j++)
        {
            s+='.';
        }
        sqr.push_back(s);
    }    
    vector<pair<int,int> > sell;
    solveit(an,sqr,0,A,sell);      
    return an;
}
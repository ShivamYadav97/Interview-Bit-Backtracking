bool solveit(vector<vector<int> > &an, vector<int> &temp, int sz, int ind, vector<int> A, int B)
{
    if(sz==B)
    {
        an.push_back(temp);
        return 1;
    }
    for(int i=ind;i<A.size();i++)
    {
        temp.push_back(A[i]);
        sz++;
        solveit(an,temp,sz,i+1,A,B);
        sz--;
        temp.pop_back();
    }
    return false;
}
vector<vector<int> > Solution::combine(int a, int B) 
{
    vector<vector<int> > an;
    vector<int> temp;
    vector<int> A;
    for(int i=1;i<=a;i++) A.push_back(i);
    int sz=0;
    int ind=0;
    solveit(an,temp,sz,ind,A,B);
    return an;
}
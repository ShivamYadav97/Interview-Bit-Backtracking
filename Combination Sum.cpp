bool solveit(vector<vector<int> > &an,int &sum,vector<int> &temp,vector<int> A,int B,int ind)
{
    if(sum==B)
    {
        an.push_back(temp);
        return true;
    }
    if(sum>B)
    {
        return false;
    }
        
    for(int i=ind;i<A.size();i++)
    {
        sum+=A[i];
        temp.push_back(A[i]);
        solveit(an,sum,temp,A,B,i);
        //ind++;
        sum-=A[i];
        temp.pop_back();
    }
    return false;
    
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B)
{
    set<int>As;
    for(int i=0;i<A.size();i++) As.insert(A[i]);
    A.clear();
    set<int> :: iterator it;
    for(it=As.begin();it!=As.end();it++)
    {
        A.push_back(*it);
    }
    vector<vector<int> > an;
    int ind=0;
    int sum=0;
    vector<int>temp;
    solveit(an,sum,temp,A,B,0);
    return an;
}
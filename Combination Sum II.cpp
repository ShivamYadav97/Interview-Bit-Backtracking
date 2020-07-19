bool solveit(vector<vector<int> > &an,int &sum,vector<int> &temp,vector<int> A,int B,int ind)
{
    map<int,bool> done;
    for (int i = ind; i < A.size(); i++)
    {
        if(done.find(A[i])==done.end()) 
            done[A[i]]=false;
    }

    if(sum==B)
    {
        an.push_back(temp);
        return true;
    }
    if(sum>B)
    {
        return false;
    }
    if(ind==A.size())
        return false;
        
    for(int i=ind;i<A.size();i++)
    {
        // linear search
        /*sum+=A[i];
        temp.push_back(A[i]);
        solveit(an,sum,temp,A,B,i+1);
        
        sum-=A[i];
        temp.pop_back();    i++;
        for(int i1=i;i1<A.size();i1++)
        {
            
            if(A[i1]!=A[i1-1]) break;
            i++;
        }*/

        //optimization using map (log n search) 
        if(!done[A[i]])
        {
            sum+=A[i];
            temp.push_back(A[i]);
            done[A[i]]=true;
            solveit(an,sum,temp,A,B,i+1);
            sum-=A[i];
            temp.pop_back();
        }
    }
    return false;
    
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B)
{
    sort(A.begin(),A.end());
    vector<vector<int> > an;
    int ind=0;
    int sum=0;
    vector<int>temp;
    solveit(an,sum,temp,A,B,0);
    return an;
}
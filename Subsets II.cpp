void solveit(vector<int>& A, vector<vector<int> >& an, vector<int>& temp, int ind) 
{ 
    an.push_back(temp); 
    map<int,bool> done;
    for (int i = ind; i < A.size(); i++)
    {
        if(done.find(A[i])==done.end()) 
            done[A[i]]=false;
    }
    
    for (int i = ind; i < A.size(); i++) 
    { 
        
        if(!done[A[i]])
        {
            temp.push_back(A[i]); 
            done[A[i]]=true;
            solveit(A, an, temp, i+1); 
            temp.pop_back(); 
        }    
    } 
  
    return; 
}
vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) 
{
    vector<int> temp; 
    vector<vector<int> > an; 
    sort(A.begin(),A.end());
    if(A.size()==0) {an.push_back(temp);return an;}
    int ind = 0; 
    solveit(A, an, temp, ind); 
  
    return an; 
}
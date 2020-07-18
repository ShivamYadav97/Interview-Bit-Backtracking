void prem(vector<int> &a, int l, int r,vector<vector<int> > & an)  
{  
    if (l == r)  
        an.push_back(a);  
    else
    {    
        for (int i = l; i <= r; i++)  
        {  
            swap(a[l], a[i]);  
            prem(a, l+1, r,an);  
            swap(a[l], a[i]);  
        }  
    }  
}  
vector<vector<int> > Solution::permute(vector<int> &A) 
{
    vector<vector<int> > an;
    prem(A,0,A.size()-1,an);
    return an;
}
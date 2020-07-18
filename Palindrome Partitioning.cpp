bool isPal(string str, int low, int high) 
{ 
    while (low < high) 
    { 
        if (str[low] != str[high]) 
            return false; 
        low++; 
        high--; 
    } 
    return true; 
} 
bool solveit(vector<vector<string> > &an, vector<string> &temp, string A,int ind)
{
    if(ind==A.length())
    {
        an.push_back(temp);
        return true;
    }
    for(int i=ind;i<A.length();i++)
    {
        if(isPal(A,ind,i))
        {
            temp.push_back(A.substr(ind, i-ind+1));
            solveit(an,temp,A,i+1);
            temp.pop_back();
        }
    }
    return false;
}
vector<vector<string> > Solution::partition(string A) 
{
    vector<vector<string> > an;
    vector<string> temp;
    int ind=0;
    solveit(an,temp,A,ind);
    return an;
}
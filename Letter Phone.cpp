void solveit(vector<string> &an, string *wrk, string A, vector<char>arr[], int ind)
{
    if(ind==A.length()) {an.push_back(*wrk);return;}
    int i1=A[ind]-'0';
    for(int i=0;i<arr[i1].size();i++)
    {
        (*wrk).push_back(arr[i1][i]);
        solveit(an,wrk,A,arr,ind+1);
        (*wrk).pop_back();
    }
    return;
}
 
vector<string> Solution::letterCombinations(string A) 
{
    vector<string> an;int ind=0;string wrk="";
    vector<char>arr[10];
    arr[0].push_back('0');
    arr[1].push_back('1');
    char cc='a';
    for(int i=2;i<=9;i++)
    {
        int t=3;
        if(i==7||i==9) t=4;
        while(t--)
        {
            arr[i].push_back(cc);
            cc++;
        }
    }
    
    solveit(an,&wrk,A,arr,ind);
    return an;
}
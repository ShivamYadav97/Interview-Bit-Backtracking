bool solveit(vector<string> &an, string *temp, int A, int &op, int &clo)
{
    if( (*temp).length() == (2*A) )
    {
        an.push_back((*temp));
        return true;
    }
    else
    {
        if(op<A)
        {
            (*temp).push_back('(');
            op++;
            solveit(an,temp,A,op,clo);
            op--;
            (*temp).pop_back();
        }
        if(clo<A && op-clo>0)
        {
            (*temp).push_back(')');
            clo++;
            solveit(an,temp,A,op,clo);
            (*temp).pop_back();
            clo--;
        }
    }
    return false;
}
vector<string> Solution::generateParenthesis(int A) 
{
    vector<string>an;
    string temp="";
    int op=0;
    int clo=0;
    solveit(an,&temp,A,op,clo);
    return an;
}
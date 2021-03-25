vector<int> findSubstringIndices(string s, const vector<string>& words)
{
    map<string,int>m;
    vector<int>v;
    int n=words.size(),i,ws=words[0].size(),j,ok;
    for(i=0; i<n; i++)
        m[words[i]]++;
    int ss=s.size();
    for(i=0; i<=ss-n*ws; i++)
    {
        j=i;
        ok=1;
        map<string,int>newMap(m);
        while(j<i+n*ws)
        {
            string newStr=s.substr(j,ws);
            if(!newMap[newStr])
            {
                ok=0;
                break;
            }
            else
                newMap[newStr]--;
            j+=ws;
        }
        if(ok)
            v.push_back(i);
    }
    return v;
}

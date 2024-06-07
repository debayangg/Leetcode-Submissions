class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        string wd="",ans="",ret="";
        sort(dictionary.begin(),dictionary.end(),
        [](const string &a,const string &b) -> bool {
            if(a.compare(b)<0)
            return true;
            else
            return false;
        });
        for(int i=0;i<sentence.size();i++)
        {
            if(sentence[i]!=' ')
            {
                wd+=sentence[i];
                if(binary_search(dictionary.begin(),dictionary.end(),wd) && !ans.size())
                ans=wd;
            }
            else
            {
                if(ans.size()>0)
                ret+=ans+" ";
                else
                ret+=wd+" ";
                wd="";
                ans="";
            }
        }
        if(ans.size()>0)
        ret+=ans;
        else
        ret+=wd;

        return ret;
    }
};
class Solution {
public:
    string decodeString(string s) {
        stack<int>A;
        stack<char>B;
        for(int S=0;S<s.size();S++)
        {
            if(isdigit(s[S]))
            {
               if((S-1)>=0 && isdigit(s[S-1]))
               {
                   int Q=A.top()*10 + (s[S]-48);
                   A.pop();
                   A.push(Q);
               }
                else
                {int Q=(s[S]-48);
                 A.push(Q);
                }
            }
            
         else
            {
                if(s[S]=='[')
                {
                    B.push(s[S]);
                }
                else if(s[S]>='a' && s[S]<='z')
                {
                    B.push(s[S]);
                }
                else
                {
                    string p,q="";
                    while(B.top()!='[')
                    {
                        p=p+B.top();
                        B.pop();
                    }
                    B.pop();
                reverse(p.begin(),p.end());
                    
                    while(A.top())
                    {
                        q.append(p);
                        A.top()--;
                    }
                    A.pop();
                    for(auto n:q)
                    {
                        B.push(n);
                    }
                    q.clear();
                    p.clear();
                 }
                }
        }
        string res="";
        while(!B.empty())
        {
            res=res+B.top();
            B.pop();
        }
      
        reverse(res.begin(),res.end());
        return res;
          
    }
};

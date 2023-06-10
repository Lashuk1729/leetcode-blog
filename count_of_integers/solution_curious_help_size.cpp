class Solution {
public:
    int n,mins,maxs;
    string s1,s2;
    int dp[30][2][2][604];
    int mod=(int)1e9+7;
    
    int fun(int i,int c1,int c2,int ds)
    {
         if(i==n)
         {
              if((ds>=mins) and (ds<=maxs))
                  return 1;
             
             return 0;
         }
        if(ds>maxs)
            return 0;
        
        if(dp[i][c1][c2][ds]!=-1)
            return dp[i][c1][c2][ds];
        
        
         int ans=0;
        if(c1 & c2)
        {
            int a1=(s1[i]-'0'),a2=(s2[i]-'0');
            if(a1==a2)
            {
                 ans+=fun(i+1,c1,c2,(ds+a1));
            }
            else
            {
                ans+=fun(i+1,c1,0,(ds+a1));
                
                for(int j=a1+1;j<a2;j++)
                {
                     ans+=fun(i+1,0,0,(ds+j));
                     ans%=mod;
                }
                
                ans+=fun(i+1,0,c2,(ds+a2));
                ans%=mod;
            }
        }
        else if(c1)
        {
            int a1=(s1[i]-'0');
            
                ans+=fun(i+1,c1,0,(ds+a1));
                
                for(int j=a1+1;j<10;j++)
                {
                     ans+=fun(i+1,0,0,(ds+j));
                    ans%=mod;
                }
                
               // ans+=fun(i+1,0,c2,(ds+a2));
           
        }
        else if(c2)
        {
            int a2=(s2[i]-'0');
           
               // ans+=fun(i+1,c1,0,(ds+a1));
                
                for(int j=0;j<a2;j++)
                {
                     ans+=fun(i+1,0,0,(ds+j));
                    ans%=mod;
                }
                
                ans+=fun(i+1,0,c2,(ds+a2));
                ans%=mod;
        }
        else
        {
            //  int a1=(s1[i]-'0'),a2=(s2[i]-'0');
            // if(a1==a2)
            // {
            //      ans+=fun(i+1,c1,c2,(ds+a1));
            // }
            // else
            // {
                //ans+=fun(i+1,c1,0,(ds+a1));
                
                for(int j=0;j<10;j++)
                {
                     ans+=fun(i+1,0,0,(ds+j));
                    ans%=mod;
                }
                
               // ans+=fun(i+1,0,c2,(ds+a2));
           // }
        }
        
        return dp[i][c1][c2][ds]=ans;
    }
    int count(string num1, string num2, int min_sum, int max_sum) {
        n=num2.size();
        
        if(num1.size()<num2.size())
        {
             reverse(num1.begin(),num1.end());
            while(num1.size()!=num2.size())
                num1+='0';
             reverse(num1.begin(),num1.end());
            
        }
        
        for(int i=0;i<=25;i++)
        {
             for(int j=0;j<2;j++)
             {
                  for(int k=0;k<2;k++)
                  {
                       for(int r=0;r<=(402);r++)
                            dp[i][j][k][r]=-1;
                  }
             }
        }
        s1=num1,s2=num2;
        mins=min_sum,maxs=max_sum;
        
        return fun(0,1,1,0);
    }
};
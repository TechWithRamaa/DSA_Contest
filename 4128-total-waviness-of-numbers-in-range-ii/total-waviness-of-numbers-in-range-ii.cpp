class Solution {
public:
    long long sumdp[20][2][2][20][11][11],cntdp[20][2][2][20][11][11];
    string s;
    int len;

    pair<long long,long long> dp(int pos,int tight,int st,int al,int p2,int p1){
        if(pos==len) return {0,1};
        long long &rs=sumdp[pos][tight][st][al][p2][p1];
        long long &rc=cntdp[pos][tight][st][al][p2][p1];
        if(rs!=-1) return {rs,rc};
        rs=rc=0;
        int up=tight?(s[pos]-'0'):9;
        for(int d=0;d<=up;d++){
            int nt=tight && (d==up),nst=st || (d!=0);
            int nal=al,np2=p2,np1=p1;
            long long yes=0;
            if(nst){
                if(!st) nal=1,np1=d;
                else {
                    nal=al+1,np2=p1,np1=d;
                    if(al>=2){
                        if((p1>p2 && p1>d)||(p1<p2 && p1<d)) yes=1;
                    }
                }
            }
            auto nx=dp(pos+1,nt,nst,nal,np2,np1);
            rs+=yes*nx.second+nx.first,rc+=nx.second;
        }
        return {rs,rc};
    }

    long long fn(long long x){
        s=to_string(x);
        len=s.size();
        memset(sumdp,-1,sizeof(sumdp)),memset(cntdp,-1,sizeof(cntdp));
        return dp(0,1,0,0,10,10).first;
    }

    long long totalWaviness(long long l,long long r) {
        return fn(r)-fn(l-1);
    }
};

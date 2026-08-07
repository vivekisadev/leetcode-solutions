class Solution {
    map<int,int> F(int d) {
        map<int,int> m;
        if (d==2) m[2]=1; else if (d==3) m[3]=1; else if (d==4) m[2]=2;
        else if (d==5) m[5]=1; else if (d==6) {m[2]=1;m[3]=1;} else if (d==7) m[7]=1;
        else if (d==8) m[2]=3; else if (d==9) m[3]=2;
        return m;
    }
    map<int,int> sub(map<int,int> a, map<int,int>& b) {
        for (auto& [k,v] : b) a[k] = max(0, a[k]-v);
        return a;
    }
    int sum(map<int,int>& m) { int s=0; for (auto& [k,v]:m) s+=v; return s; }
    map<int,int> need(map<int,int> c) {
        map<int,int> r;
        int c8=c[2]/3, r2=c[2]%3, c9=c[3]/2, c3=c[3]%2, c4=r2/2, c2=r2%2, c6=0;
        if (c2==1&&c3==1){c2=0;c3=0;c6=1;}
        if (c3==1&&c4==1){c2=1;c6=1;c3=0;c4=0;}
        r[2]=c2; r[3]=c3; r[4]=c4; r[5]=c[5]; r[6]=c6; r[7]=c[7]; r[8]=c8; r[9]=c9;
        return r;
    }
    string mk(map<int,int>& r) {
        string s;
        for (int d=2; d<10; d++) s += string(r[d], '0'+d);
        return s;
    }
public:
    string smallestNumber(string num, long long t) {
        map<int,int> tot = {{2,0},{3,0},{5,0},{7,0}};
        for (int p : {2,3,5,7}) while (t%p==0) { t/=p; tot[p]++; }
        if (t != 1) return "-1";

        auto need0 = need(tot);
        if (sum(need0) > (int)num.size()) return mk(need0);

        map<int,int> pre = {{2,0},{3,0},{5,0},{7,0}};
        for (char c : num) for (auto& [p,v] : F(c-'0')) pre[p]+=v;

        int z = num.find('0');
        bool ok = true;
        if (z == (int)string::npos) {
            z = num.size();
            for (auto& [k,v] : tot) if (pre[k] < v) { ok=false; break; }
            if (ok) return num;
        }

        for (int i = num.size()-1; i >= 0; i--) {
            auto fi = F(num[i]-'0');
            pre = sub(pre, fi);
            if (i > z) continue;
            for (int d = num[i]-'0'+1; d < 10; d++) {
                auto fd = F(d);
                auto rem = need(sub(sub(tot, pre), fd));
                int c = sum(rem);
                int space = num.size()-1-i;
                if (c <= space)
                    return num.substr(0,i) + char('0'+d) + string(space-c,'1') + mk(rem);
            }
        }

        auto ext = need(tot);
        int c = sum(ext);
        return string(num.size()+1-c, '1') + mk(ext);
    }
};
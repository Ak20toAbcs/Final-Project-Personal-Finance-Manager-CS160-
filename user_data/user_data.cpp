#include "user_data.h"

    string FormatMoney (int money){
        if (money == 0) return "0 VND";
        int m = abs(money);
        string s;
        int cnt = 0; int ss = 0;
        while(m>0){
            int t = m%10;
            m /= 10;
            s.push_back(t+'0');
            ++cnt; ++ss;
            if (m>0 && cnt%3==0) {s.push_back(','); ++ss;}
        }
        if (money<0) {s.push_back('-'); ++ss;}
        string res;
        for (int i=0; i<ss; ++i) res.push_back(s[ss-1-i]);
        res.push_back(' ');
        res.push_back('V');
        res.push_back('N');
        res.push_back('D');
        return res;
    }


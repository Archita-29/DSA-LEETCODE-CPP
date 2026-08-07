class Solution {
    struct Factors{
        int f2=0,f3=0,f5=0,f7=0;
    };

    Factors getPrimeCount(long long val){
        Factors f;
        while(val%2==0){ f.f2++; val/=2;}
        while(val%3==0){ f.f3++; val/=3;}
        while(val%5==0){ f.f5++; val/=5;}
        while(val%7==0){ f.f7++; val/=7;}
        if(val>1) return {-1,-1,-1,-1};
        return f;
    }
    int requiredDigits(Factors f){
        int c8=f.f2/3; f.f2%=3;
        int c9=f.f3/2; f.f3%=2;
        int c6=0;
        if(f.f2>=1 && f.f3==1){ c6=1;f.f2-=1; f.f3=0;}
        int c4=f.f2/2; f.f2%=2;
        return c8+c9+c6+c4+f.f2+f.f3+f.f5+f.f7;
    }
    string buildTail(Factors f,int length){
        int c9=f.f3/2;f.f3%=2;
        int c8=f.f2/3;f.f2%=3;
        int c6=0;
        if(f.f2>=1 && f.f3==1){ c6=1;f.f2-=1;f.f3=0;}
        int c4=f.f2/2; f.f2%=2;

        string tail="";
        tail.append(f.f2,'2');
        tail.append(f.f3,'3');
        tail.append(c4,'4');
        tail.append(f.f5,'5');
        tail.append(c6,'6');
        tail.append(f.f7,'7');
        tail.append(c8,'8');
        tail.append(c9,'9');

        while((int)tail.size()<length){
            tail.push_back('1');
        }
        sort(tail.begin(),tail.end());
        return tail;
    }

    Factors subtractDigit(Factors f,int digit){
        if(digit==2) f.f2=max(0,f.f2-1);
        else if(digit==3) f.f3=max(0,f.f3-1);
        else if(digit==4) f.f2=max(0,f.f2-2);
        else if(digit==5) f.f5=max(0,f.f5-1);
        else if(digit==6){ f.f2=max(0,f.f2-1); f.f3=max(0,f.f3-1);}
        else if(digit==7) f.f7=max(0,f.f7-1);
        else if(digit==8) f.f2=max(0,f.f2-3);
        else if(digit==9) f.f3=max(0,f.f3-2);
        return f;
    }
public:
    string smallestNumber(string num, long long t) {
        Factors req=getPrimeCount(t);
        if(req.f2==-1) return "-1";
        int n=num.size();
        vector<Factors> prefFactors(n+1);
        prefFactors[0]=req;
        int zeroPos=-1;
        for(int i=0;i<n;i++){
            if(num[i]=='0'){
                zeroPos=i;
                break;
            }
            prefFactors[i+1]=subtractDigit(prefFactors[i],num[i]-'0');
        }
        if(zeroPos==-1 && requiredDigits(prefFactors[n])==0){
            return num;
        }
        int maxPrefix=(zeroPos==-1)?n-1:zeroPos;
        for(int i=maxPrefix;i>=0;i--){
            int currentDigit=num[i]-'0';
            for(int d=currentDigit+1;d<=9;d++){
                Factors remFactors=subtractDigit(prefFactors[i],d);
                int needed=requiredDigits(remFactors);
                int avail=n-1-i;
                if(needed<=avail){
                    string ans=num.substr(0,i);
                    ans+=to_string(d);
                    ans+=buildTail(remFactors,avail);
                    return ans;
                }
            }
        }
        int minLen=max(n+1,requiredDigits(req));
        return buildTail(req,minLen);
    }
};
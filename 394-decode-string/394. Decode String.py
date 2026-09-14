class Solution:
    def decodeString(self, s: str) -> str:
        def solve(count,s):
            ans = ''
            n = len(s)
            i=0
            while i<n:
                x=0
                while(s[i].isdigit()):
                    x*=10
                    x+=int(s[i])
                    i+=1
                if x:
                    i+=1
                    j=i
                    k=1
                    while(k!=0):
                        if(s[i]=='['):
                            k+=1
                        elif (s[i]==']'):
                            k-=1
                        i+=1
                    ans+=solve(x,s[j:i-1])
                else:
                    ans+=s[i]
                    i+=1
            return count*ans
        return solve(1,s)
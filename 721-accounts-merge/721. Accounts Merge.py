
class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        a2i = {}
        i2n = {}
        self.p = [_ for _ in range(len(accounts))]
        # size = [1 for _ in range(len(accounts))]
        def find(mail,i):
            nonlocal a2i
            return self.p[a2i.get(mail,i)]
        def u_find(i):
            if self.p[i]!=i:
                self.p[i]=u_find(self.p[i])
            return self.p[i]
        def union(a,b):
            if self.p[i]!=i:
                self.p[i2]=self.p[i]
            else:
                self.p[i]=self.p[i2]
        for i,account in enumerate(accounts):
            name = account[0]
            i2n[i] = name 
            for mail in account[1:]:
                i2 = find(mail,i)
                i2 = u_find(i2)
                if i2!=i:
                    union(i,i2)
                a2i[mail] = self.p[i]
        i2a = defaultdict(list)
        print(self.p)
        for a,i in a2i.items():
            i2a[u_find(i)].append(a)
        print(self.p)
        ans = []
        for i,a in i2a.items():
            ans.append([i2n[i],*sorted(a)])
        return ans
                
            
            
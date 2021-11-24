import io,os,sys,heapq
input=io.BytesIO(os.read(0,\
                        os.fstat(0).st_size)).readline
def cout(s,End='\n'):
    sys.stdout.write(str(s)+str(End))
def main():
    for TCase in range(int(input())):
        d,n,k=map(int,input().split())
        atr,ans=[],0
        for i in range(1,n+1):
            atr.append(list(map(int,input().split())))
        atr=sorted(atr,key=lambda x:x[0],reverse=True)
        for i in range(1,d+1):
            t,j,x=k,0,0
            while(j<n and t>0):
                if atr[j][1]<=i<=atr[j][2]:
                    x+=atr[j][0]
                    t-=1
                j+=1
            ans=max(ans,x)
        cout("Case #"+str(TCase+1)+":",' ')
        cout(ans)
    pass
main()
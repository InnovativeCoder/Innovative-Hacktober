T = int(input())
while T>0:
    T=T-1
    N,X,S=map(int,input().split())
    coin=X
    while S>0:
        S=S-1
        swapbox=list(map(int,input().split()))
        if coin in swapbox:
            coin=swapbox[0]+swapbox[1]-coin
    print(coin)

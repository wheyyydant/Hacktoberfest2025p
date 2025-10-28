a,b = map(int,input().split())
c = max(a,b)
carry,i = 0 , 0
s = 0
while c:
    dig = 0
    lda,ldb = a%10 , b%10
    if lda+ldb+carry >9:
        dig = (lda+ldb+carry)%10
        carry = 1
    else:
        dig = (lda+ldb+carry)
        carry = 0
    s += dig*(10**i)
    c //= 10
    a //= 10
    b //= 10
    i += 1
if carry == 1:
    s += 1*(10**i)
print(s)

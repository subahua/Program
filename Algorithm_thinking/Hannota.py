#汉诺塔的移动
def Mv(n,A,B,C):
    if n == 1:
        print(A,'->',C)
    else:
        Mv(n - 1,A,C,B)
        print('A -> C')
        Mv(n - 1,B,A,C)
Mv(3,'A','B','C')

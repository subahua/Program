import math
def quadratic(a = 2,b = 3,c = 1):
    if not isinstance(a,(int)) | isinstance(b,(int)) | isinstance(c,(int)):
        print("参数错误")
    qua = math.sqrt(b * b - 4 * a * c)
    if qua > 0:
        print("改方程有两个根:")
        x1 = (-b + qua) / (2 * a)
        x2 = (-b - qua) / (2 * a)
        print("x1 = %f,x2 = %f"%(x1,x2))
        return x1,x2
    elif qua == 0:
        print("改方程有一个根:")
        x = (-b + qua) / (2 * a)
        print("x = %f"%(x))
    else:
        print("改方程没有实数解")

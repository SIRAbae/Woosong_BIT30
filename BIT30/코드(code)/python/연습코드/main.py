"""
import datetime
y={0:'월요일',1:'화요일',2:'수요일',3:'목요일',4:'금요일',5:'토요일',6:'일요일'}
d=datetime.date(2019,11,25)
print(y[d.weekday()])
"""
"""
def my_fun(start,end):
    sum=0
    for i in range(start,end+1):
        sum=sum+i
    print('합계',sum)


start=int(input('시작 값 : '))
end=int(input('끝 값 : '))
my_fun(start,end)
"""
"""
def my_fun(start):
    print('*'*start)

start=int(input('별의 수 : '))
my_fun(start)
"""
"""
def my_fun(start):
    return ('*' * start)

start=int(input('별의 수 : '))
st=my_fun(start)
print(st)
"""
def my_fun(a,b,c):
    if a>b and a>c:
        return a
    elif b>a and b>c:
        return b
    else:
        return c

a= int(input('a 값 :'))
b= int(input('b 값 :'))
c= int(input('c 값 :'))

print (my_fun(a,b,c))

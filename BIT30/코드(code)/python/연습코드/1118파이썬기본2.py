"""
len("_____")길이를 구한다.
변수.replace('바꿀이름','바꿀말')
변수.upper() ----소문자를 대문자로 치환
변수.lower() ----대문자를 소문자로 치환
"""

"""
a=10
b  ='10'
print(type(a))
print(type(b))
print(a+int(b))
print(str(a)+b)
"""

"""
dic={'경상도':{'부산','대구','울산','공통'},
     '전라도':{'광주','전주','공통'}}

for name,contents in dic.items():
    if '광주' in contents:
        print(name)

#광주가 있는 key값을 출력
        
for name,contents in dic.items():
    if '대구' in contents:
        print(name)
for name,contents in dic.items():
    if '공통' in contents:
        print(name)
"""
dic={'경상도':{'부산','대구','울산','공통'},
     '전라도':{'광주','전주','공통'}}

for name,contents in dic.items():
    if '공통' in contents and not('대구' in contents):
        print(name)
#'공통'이들어가고 '대구'가 안들어가는 key 값


age=int(input('나이?'))
if age<8:
    print('유아')
elif age>=8 and age<20:
    print('학생')
else:
    print('성인')

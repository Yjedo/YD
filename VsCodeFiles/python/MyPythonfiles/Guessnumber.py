 # coding=gbk
import random
num=random.randint(1,10)
while(1):
    answer=int (input("guess a number: "))
    if answer > num:
        print("�´���")
    elif answer < num:
        print("��С��")
    else:
        print("�¶���")
        break
print("the number: ", num)
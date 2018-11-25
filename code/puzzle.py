tmp = input()
str = list(input())
anscnt = 0
while (1):
    cnt = list()
    lastc = ''
    lastn = 0
    remc = 0
    fc = 0
    endf = True
    for k in str:
        if (lastc == k):
            cnt.append(lastn+1)
            lastn = lastn + 1
        else:
            cnt.append(1)
            lastn = 1
        lastc = k
    for i in range(len(cnt)-1, -1, -1):
        if (cnt[i] >= 3):
            if (remc == 0):
                remc = cnt[i]
                endf = False
        if (remc > 0):
            str[i] = '.'
            fc = fc + 1
            remc = remc - 1
    if (endf):
        break
    anscnt = anscnt + 1
    for i in range(fc):
        str.remove('.')
print (anscnt)
if(len(str) == 0):
    print("PERFECT!!!")
else:
    print (''.join(str))
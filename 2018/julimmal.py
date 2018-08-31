file = open('input.txt', 'r')
tc = int(file.readline())
ans = []
for k in range(tc):
    tc_ans = ''
    str = file.readline().split(' ')
    for i in range(len(str)):
        tc_ans += str[i][:1]
    ans.append(tc_ans)
file = open('ans.txt', 'w')
for k in ans:
    file.write(k + '\n')
file.close()

n, m = map(int, input().split())
word = input()
b = input()
text = [0]*m
for i in range(m-n, m):
    text[i] = ord(word[i+n-m])-ord('a')
# print(text)
for i in reversed(range(m)):
    if(i-n)<0: break
    text[i-n] = (ord(b[i])-ord('a')-text[i]+26)%26
ans = [chr(text[i]+ord('a')) for i in range(m)]
print(''.join(ans))
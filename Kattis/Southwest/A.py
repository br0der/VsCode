s = input()
totA = 0
totL = 0
for ch in s:
    totA += ord(ch)
    totL += 1
print(chr(int(totA/totL)))
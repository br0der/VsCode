import random, json

words = json.load(open("vocab.json"))
words2 = {}
for i in words.keys():
    words2[words[i]] = i
l = list(words2.keys())
random.shuffle(l)
for i in l:
    inp = input(f'What is {i}?')
    while(inp.title() not in words.keys()):
        print("wrong spelling")
        inp = input(f'What is {i}?')
    if(inp.lower() != words2[i].lower()):
        print(f'Wrong answer, correct was {words2[i]}')
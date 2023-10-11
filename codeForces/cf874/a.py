for tc in range(int(input())):
    n = int(input())
    notes = set()
    melody = input()
    for i in range(len(melody)-1):
        notes.add(melody[i:i+2])
    print(len(notes))
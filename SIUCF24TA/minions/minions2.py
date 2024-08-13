cases=int(input())
for i in range(cases):
    TAS=[]
    campers=[]
    players=int(input())
    for i in range(players):
        name,score=input().strip().split()
        if name[0]=="T" and name[1]=="A":
            TAS.append([name,score])
        else:
            campers.append([name,score])
    campers.sort(key=lambda x:x[0])
  
    campers.sort(key=lambda x:x[1],reverse=True)
  
    TAS.sort(key=lambda x:x[0])
    
    TAS.sort(key =lambda x:x[1],reverse=True)
    
    
 
    for i in range(len(campers)):
        print(campers[i][0])
    for i in range(len(TAS)):
        print(TAS[i][0])


   


    

        
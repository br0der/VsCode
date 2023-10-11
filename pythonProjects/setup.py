import os

number = int(input('What number CF contest is this?'))

problems = int(input('How many problems?'))
# Directory
directory = f'cf{number}'
  
# Parent Directory path
parent_dir = "C:/Users/aberb/Documents/vsCode/vscode/misc/"
  
# Path
path = os.path.join(parent_dir, directory)

os.makedirs(path)

parent_dir = f"C:/Users/aberb/Documents/vsCode/vscode/misc/cf{number}/"

for i in range(problems):
    char = chr(ord('a')+i)
    f = open(f"cf{number}/{char}.py","w+")
    f = open(f"cf{number}/{char}.in","w+")
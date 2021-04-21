'''
 Title   : Directory Handling
 Name    : Kevlyn Kadamala
 Roll no.: 8340
 '''

import shutil, os
src = '/Users/kad99kev/Desktop/SEM 4/Python/Test.txt'
des = '/Users/kad99kev/Desktop/SEM 4/Python/Copy.txt'
shutil.copyfile(src, des)
print(f"Copied file is in {os.path.split(os.path.abspath(des))} directory")
print("After shfiting")
src = '/Users/kad99kev/Desktop/SEM 4/Python/Copy.txt'
des = '/Users/kad99kev/Desktop/SEM 4/Copy.txt'
shutil.move(src,des)
print(f"Copied file is shifted {os.path.split(os.path.abspath(des))} directory")

'''
Copied file is in ('/Users/kad99kev/Desktop/SEM 4/Python', 'Copy.txt') directory
After shfiting
Copied file is shifted ('/Users/kad99kev/Desktop/SEM 4', 'Copy.txt') directory
'''

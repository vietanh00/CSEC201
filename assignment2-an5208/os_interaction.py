import os

"""
    pwd
    ls 
    mkdir Lab2
    ls 
    cd Lab2
    create a temp.txt and write some msg
    read the file 
    cd ../
    pwd
"""


def main():
    print(os.getcwd())  # pwd
    print(os.listdir())  # ls
    # Trying to get around flags if the directory exists
    try:
        os.mkdir('Lab2')
    except:
        print('mkdir: Lab2: File exists')
    print(os.listdir())
    os.chdir('Lab2')

    file = open('temp.txt', 'a')
    file.write("Hi \n")
    file.write("Bye \n")
    file.close()

    file2 = open('temp.txt', 'a')
    file2.write("Test \n")
    file2.close()

    file0 = open('temp.txt')
    for line in file0:
        print(line)

    os.chdir('../')
    print(os.getcwd())


main()

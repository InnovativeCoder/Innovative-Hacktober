import readchar
from termcolor import colored
import sys
def main():
    corrcol = "green"
    ip = open("Input.txt")
    countf = 0
    for i in ip:
    	countf+=len(i)+1
    	print(i)
    print("Type to start: No of chars = ",countf)
    ip.close()
    ip = open("Input.txt")
    countc=0
    strerr = "red"
    strcorr = "yellow"
    # print(countc,countf)
    countword = 0
    ch = 0
    linecount = 0
    while(countc!=countf):
        for line in ip:
            countc+=1
            countword = 0
            print(line)
            ch =0
            while(ch<(len(line))):
                countword+=1
                # print(len(line),"==",ch,countword)
                if (line[ch] == " "):
                    # print(countword)
                    countword=0    
                curr = readchar.readchar()
                if(curr == "\x03"): #Ctrl+c
                    print()
                    exit()
                if(curr == "\x7f"): #Backspace
                    # sys.stdout.write("\033[K")
                    print()
                    ch = ch-countword
                    if(countword-1<0):
                        countword = 0
                    else:
                        countword-=1
                    # print(ch)
                    if(ch<0):
                        print("Start from ",line[0])
                        ch = 0
                        continue
                    print("Start from ",line[ch+1])
                    ch+=1
                    countword = 0
                    continue
                if(curr == "\x0d"): #Next Line
                    if(ch!=len(line)-1):
                        # print(ch,len(line))
                        print()
                        print(colored("\n",strerr),sep = " ",end = "",flush = True)
                        continue
                    print() #No enter recorder simply puts to next line
                    break
                if(curr!=line[ch]):
                    print(colored(curr,strerr),sep = " ",end = "",flush = True)
                else:
                    print(colored(curr,strcorr),sep = " ",end = "",flush = True)
                ch+=1
            linecount+=len(line)
if __name__ == '__main__':
    main()
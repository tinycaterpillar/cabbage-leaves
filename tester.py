import os
from tqdm import tqdm

def main():
    os.system("python testcase_maker.py")
    os.system("00test.exe < input.txt > output1.txt")
    os.system("01test.exe < input.txt > output2.txt")
    
    # with open("output1.txt") as f:
    #     c = f.readline().rstrip()
    #     if c == "YES":
    #         with open("input.txt", 'r') as ff:
    #             print(ff.read())
    #             print()
            
    os.system("FC output1.txt output2.txt > result.txt")
    with open("result.txt", 'r') as rf:
        rf.readline()
        line = rf.readline()
        if "다른 점이 없습니다" not in line: 
            with open("input.txt", 'r') as f:
                print(f.read())
                print()

if __name__ == "__main__":
    for _ in tqdm(range(1000)): main()



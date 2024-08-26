import os

def main():
    os.system("python testcase_maker.py")
    os.system("00test.exe < input.txt > output1.txt")
    os.system("01test.exe < input.txt > output2.txt")
    
    os.system("02test.exe < output1.txt > output3.txt")
    os.system("02test.exe < output2.txt > output4.txt")
    
    os.system("FC output3.txt output4.txt")
    with open("input.txt", 'r') as f:
        print(f.read())
        print()

if __name__ == "__main__":
    for _ in range(1): main()



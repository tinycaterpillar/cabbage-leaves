import os

def main():
    os.system("python testcase_maker.py")
    os.system("00test.exe < input.txt > ouput1.txt")
    os.system("01test.exe < input.txt > ouput2.txt")
    
    os.system("FC ouput1.txt ouput2.txt")
    with open("input.txt", 'r') as f:
        print(f.read())
        print()

if __name__ == "__main__":
    for _ in range(10): main()



import os

def main():
    os.system("python 00test.py")
    os.system("00test.exe < input.txt")
    os.system("01test.exe < input.txt")

    with open("input.txt", 'r') as f:
        print(f.read())

if __name__ == "__main__":
    for _ in range(100): main()



import sys
import os.path

if os.path.isfile('input.txt'):
    sys.stdin = open('input.txt')
    sys.stdout = open('output.txt', 'w')
input = sys.stdin.readline


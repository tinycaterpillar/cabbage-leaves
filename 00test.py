N = pow(2, 12)
tar = [4820, 42095, 215201, 650000, 200001]
for i in tar:
    q, r = divmod(i, N)
    print(i, q, r)
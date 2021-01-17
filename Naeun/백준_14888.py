
n = (int)(input())
numbers = list(map(int, input().split()))
plus, minus, mul, div = list(map(int, input().split()))

resli = []
def ops(res, idx, plus, minus, mul, div):
    if idx >= n:
        resli.append(res)
        return

    if plus > 0:
        ops(res + numbers[idx], idx+1, plus-1, minus, mul, div)
    if minus > 0:
        ops(res - numbers[idx], idx+1,  plus, minus-1, mul, div)
    if mul > 0:
        ops(res * numbers[idx], idx+1, plus, minus, mul-1, div)
    if div > 0:
        ops((int)(res / numbers[idx]), idx+1, plus, minus, mul, div-1)


ops(numbers[0], 1, plus, minus, mul, div)
print(max(resli))
print(min(resli))

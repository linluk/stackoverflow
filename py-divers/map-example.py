foo = [
    [1, 2],
    [3, 4],
    [5, 6]
]

def add(num1, num2):
        return num1 + num2

print(map(lambda x: add(x[0], x[1]), foo))



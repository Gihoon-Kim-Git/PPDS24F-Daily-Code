def adding(sum, number):
    if number == 1:
        return sum + 1
    if number == 2:
        return sum + 2
    if number == 3:
        return sum + 4
    sum = adding(sum, number - 1)
    sum = adding(sum, number - 2)
    sum = adding(sum, number - 3)
    return sum

if __name__ == "__main__":
    count = int(input())
    for i in range(count):
        number = int(input())
        print(adding(0, number))
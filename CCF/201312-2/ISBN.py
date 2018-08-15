def main():
    isbn = input().strip('')
    numbers_str = isbn.split('-')
    numbers = list(int(x) for x in list(''.join(numbers_str)))
    sum = 1 * numbers[0] + 2 * numbers[1] + 3 * numbers[2] + 4 * numbers[3] + 5 *numbers[4] + 6 * numbers[5] + 7 * numbers[6] + 8 * numbers[7] + 9 *numbers[8]
    if sum % 11 == numbers[9]:
        print('Right')
    else:
        res = isbn[:len(isbn) - 1] + chr(sum % 11 + ord('0'))
        print(res)


if __name__ == '__main__':
    main()
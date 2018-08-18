def main():
    pattern = input()
    cap_sense = int(input())
    line_num = int(input())
    ori_lines = []
    pre_lines = []
    res = []
    for i in range(line_num):
        line = input()
        if cap_sense == 1 and line.find(pattern) != -1:
            res.append(line)
        elif cap_sense == 0 and line.lower().find(pattern.lower()) != -1:
            res.append(line)
    for item in res:
        print(item)



if __name__ == '__main__':
    main()
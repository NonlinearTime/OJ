def main():
    opts_str = input()
    opts = {}
    param_opts = {}
    for i in range(len(opts_str) - 1):
        if opts_str[i] == ':':
            continue
        if opts_str[i+1] == ':':
            param_opts[opts_str[i]] = ''
        else:
            opts[opts_str[i]] = ''
        if opts_str[len(opts_str) - 1] != ':':
            opts[opts_str[len(opts_str) - 1]] = ''
    line_num = int(input())
    sorted_opts = sorted(list(opts.keys()) + (list(param_opts.keys())))
    for idx in range(1, line_num + 1):
        line = input()
        out_line = 'Case ' + str(idx) + ': '
        params = line.split(' ')
        for i in range(1, len(params) - 1):
            if params[i][0] == '-' and params[i+1][0] != '-':
                if params[i][1] in param_opts:
                    param_opts[params[i][1]] = params[i+1]
                else: break
            if params[i][0] == '-' and params[i+1][0] == '-':
                if params[i][1] in opts:
                    opts[params[i][1]] = '1'
                else: break
        if params[len(params) - 1][0] == '-' and params[len(params) - 1][1] in opts:
            opts[params[i][1]] = '1'
        for item in sorted_opts:
            if item in opts and opts[item] != '':
                out_line += '{} '.format('-' + item)
                opts[item] = ''
            elif item in param_opts and param_opts[item] != '':
                out_line += '{} {} '.format('-' + item, param_opts[item])
                param_opts[item] = ''
        print(out_line.strip())


if __name__ == '__main__':
    main()
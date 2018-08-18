import sys


def main():
    rec = []
    is_valid = []
    dct = {
        'buy':  {},
        'sell': {}
    }
    buy_sum_left = 0
    buy_sum_right = 0
    sell_sum_left = 0
    sell_sum_right = 0
    for line in sys.stdin:
        tmp = line.strip()
        if tmp == '':
            break
        # print(tmp)
        is_valid.append(True)
        items = tmp.split(' ')
        rec.append(items)
        if items[0] == 'cancel':
            is_valid[int(items[1]) - 1] = False
            is_valid[-1] = False
    # print(is_valid)
    for i, item in enumerate(is_valid):
        if item:
            price = float(rec[i][1])
            local_sum = int(rec[i][2])
            if dct[rec[i][0]].get(price) is None:
                dct[rec[i][0]][price] = local_sum
            else:
                dct[rec[i][0]][price] += local_sum
    # print(dct)
    prices = set(dct['sell'].keys()).union(set(dct['buy'].keys()))
    prices = list(sorted(prices))
    # print(prices)

    max_num = 0
    max_price = 0.00

    for i, price in enumerate(prices):
        if dct['buy'].get(price) is None:
            dct['buy'][price] = 0
        if dct['sell'].get(price) is None:
            dct['sell'][price] = 0
        if i == 0:
            buy_sum_left = 0
            buy_sum_right = sum(dct['buy'].values())
            sell_sum_left = dct['sell'][price]
            sell_sum_right = sum(dct['sell'].values()) - dct['sell'][price]
        else:
            buy_sum_left += dct['buy'][prices[i - 1]]
            buy_sum_right -= dct['buy'][prices[i - 1]]
            sell_sum_left += dct['sell'][price]
            sell_sum_right -= dct['sell'][price]
        suc_num = min(buy_sum_right, sell_sum_left)
        if suc_num >= max_num:
            max_num = suc_num
            max_price = price
    print('%.2lf %ld' % (max_price, max_num))


if __name__ == '__main__':
    main()


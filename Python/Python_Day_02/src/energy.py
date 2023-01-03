def fix_wiring(cables, sockets, plugs):
    cables = check_iter(cables)
    sockets = check_iter(sockets)
    plugs = check_iter(plugs)
    res_list = list()
    for cable_value, socket_value, plug_value in zip(cables, sockets, plugs):
        res_list.append(
            f'plug {cable_value} into {socket_value} using {plug_value}')
    for cable_value, socket_value in zip(cables, sockets):
        check_value = 0
        for tmp_value in res_list:
            if cable_value not in tmp_value and socket_value not in tmp_value:
                check_value += 1
        if check_value == len(res_list):
            res_list.append(
                f'weld {cable_value} to {socket_value} without plug')
    return res_list


def check_iter(iter_list):
    res_list = list()
    check_list = ('plug', 'socket', 'cable')
    for tmp_value in iter_list:
        if isinstance(tmp_value, str):
            for check_value in check_list:
                if check_value == tmp_value[:-1]:
                    res_list.append(tmp_value)
    return res_list


def main():
    print('-------- test_case_1 -------------')
    plugs = ['plug1', 'plug2', 'plug3']
    sockets = ['socket1', 'socket2', 'socket3', 'socket4']
    cables = ['cable1', 'cable2', 'cable3', 'cable4']
    for c in fix_wiring(cables, sockets, plugs):
        print(c)
    print('-------- test_case_2 -------------')
    plugs = ['plugZ', None, 'plugY', 'plugX']
    sockets = [1, 'socket1', 'socket2', 'socket3', 'socket4']
    cables = ['cable2', 'cable1', False]
    for c in fix_wiring(cables, sockets, plugs):
        print(c)
    print('-------- test_case_3 -------------')
    plugs = ['plugZ', None, 'plugY', 'plugX']
    sockets = [1, 'socket1', 'socket2', 'socket3', 'socket4']
    cables = ['cable2', 'cable1', False, 'cable3']
    for c in fix_wiring(cables, sockets, plugs):
        print(c)
    print('-------- test_case_4 -------------')
    plugs = ['plugZ', None, 'plugY']
    sockets = [1, 'socket1', 'socket2', 'socket3', 'socket4']
    cables = ['cable2', 'cable1', False, 'cable3']
    for c in fix_wiring(cables, sockets, plugs):
        print(c)


if __name__ == '__main__':
    main()

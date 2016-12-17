def demo_map(int_list, str_list):
    print 'demo map:'
    res_int_list = map(lambda ele: ele * ele, int_list)
    print res_int_list

    res_len_list = map(lambda ele: len(ele), str_list)
    print res_len_list


def demo_filter(int_list, str_list):
    print 'demo filter:'
    res_int_list = filter(lambda ele: ele % 2 == 0, int_list)
    print res_int_list

    res_str_list = filter(lambda ele: ele[0].isupper(), str_list)
    print res_str_list


def demo_reduce(int_list, str_list):
    print 'demo reduce/fold:'
    res_int = reduce(lambda left, right: left * right, int_list, 1)
    print res_int

    res_str = reduce(lambda left, right: left + ':' + right, str_list, 'Haha')
    print res_str

    print 'If use pythonic style:', ':'.join(['Haha'] + str_list)


if __name__ == '__main__':
    my_int_list = [i for i in range(1, 6)]
    my_str_list = ['Programming', 'in', 'a', 'functional', 'style.']

    demo_map(my_int_list, my_str_list)
    demo_filter(my_int_list, my_str_list)
    demo_reduce(my_int_list, my_str_list)

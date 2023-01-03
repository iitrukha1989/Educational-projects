from main import check_human


def test_check_number():
    """
    Тестирование функции проверки основных показателей
    :return:
    """
    assert check_human((140, 800, 30, 60)) == True
    assert check_human((200, 900, 100, 100)) == True
    assert check_human((1_000_000, 0, 0, 0)) == False
    assert check_human((1_000, 1_000, 1_000, 0)) == False
    assert check_human((140, 800, 54)) == False
    assert check_human(()) == False
    assert check_human((140, )) == False
    assert check_human((140, 800,)) == False
    assert check_human(('')) == False
    assert check_human(('140', '800', '54', '421')) == True
    assert check_human((-140, -800, -54, -421)) == False
    assert check_human((0, 0, 0, 0)) == False
    assert check_human(('dawdw', 'dwada', 'dawda', 'dwda')) == False
    assert check_human(('-241', '-2145', '-125', '421')) == False
    assert check_human((140, -800, -54, 421)) == False
    assert check_human((140, '800', -54, '-421')) == False

from main import check_digit


def test_check_number():
    """
    Тестирование функции проверки на число
    :return:
    """
    assert check_digit('5') == True
    assert check_digit('-5') == True
    assert check_digit('0') == True
    assert check_digit('12') == True
    assert check_digit('57732') == True
    assert check_digit('asd') == False
    assert check_digit('dwasd') == False
    assert check_digit('-521asd') == False
    assert check_digit('1255asd') == False
    assert check_digit('adw2324sd') == False
    assert check_digit('adwsd2125') == False
    assert check_digit('214ad dwawsd2125') == False
    assert check_digit('214ad2121dwsd215') == False
    assert check_digit(' 214ad2121dwsd215') == False
    assert check_digit('214ad212 1dwsd215') == False
    assert check_digit('214ad212 1dwsd21 ') == False

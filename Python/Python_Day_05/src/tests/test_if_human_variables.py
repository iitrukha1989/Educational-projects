from main import if_human_variables


def test_human_variables_1(monkeypatch):
    """
    Тестирование функции ввода показателей
    :param monkeypatch: 
    :return: 
    """
    inputs = iter(['12', '60', '0', '2'])
    monkeypatch.setattr('builtins.input', lambda _: next(inputs))
    one_value, two_value, three_value, four_value = if_human_variables()
    assert int(one_value) == 12
    assert int(two_value) == 60
    assert int(three_value) == 0
    assert int(four_value) == 2


def test_human_variables_2(monkeypatch):
    inputs = iter(['16', '100', '6', '8'])
    monkeypatch.setattr('builtins.input', lambda _: next(inputs))
    one_value, two_value, three_value, four_value = if_human_variables()
    assert int(one_value) == 16
    assert int(two_value) == 100
    assert int(three_value) == 6
    assert int(four_value) == 8


def test_human_variables_3(monkeypatch):
    inputs = iter(['15', '65', '4', '7'])
    monkeypatch.setattr('builtins.input', lambda _: next(inputs))
    one_value, two_value, three_value, four_value = if_human_variables()
    assert int(one_value) == 15
    assert int(two_value) == 65
    assert int(three_value) == 4
    assert int(four_value) == 7

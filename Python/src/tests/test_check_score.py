import json
from main import check_score, DATABASE


dict_value = None
with open(DATABASE) as json_file:
    dict_value = json.load(json_file)
    dict_value = dict_value['item']


def test_check_number():
    """
    Тестирование функции проверки правильности ответов
    :return:
    """
    assert check_score(1, dict_value, 0) == 1
    assert check_score(2, dict_value, 0) == 0
    assert check_score(3, dict_value, 0) == 0
    assert check_score(4, dict_value, 0) == 0
    assert check_score(1, dict_value, 1) == 0
    assert check_score(2, dict_value, 1) == 1
    assert check_score(3, dict_value, 1) == 0
    assert check_score(4, dict_value, 1) == 0
    assert check_score(1, dict_value, 2) == 1
    assert check_score(2, dict_value, 2) == 0
    assert check_score(3, dict_value, 2) == 0
    assert check_score(4, dict_value, 2) == 0
    assert check_score(1, dict_value, 3) == 0
    assert check_score(2, dict_value, 3) == 0
    assert check_score(3, dict_value, 3) == 1
    assert check_score(4, dict_value, 3) == 0
    assert check_score(1, dict_value, 4) == 1
    assert check_score(2, dict_value, 4) == 0
    assert check_score(3, dict_value, 4) == 0
    assert check_score(4, dict_value, 4) == 0
    assert check_score(1, dict_value, 5) == 0
    assert check_score(2, dict_value, 5) == 1
    assert check_score(3, dict_value, 5) == 0
    assert check_score(4, dict_value, 5) == 0
    assert check_score(1, dict_value, 6) == 0
    assert check_score(2, dict_value, 6) == 1
    assert check_score(3, dict_value, 6) == 0
    assert check_score(4, dict_value, 6) == 0
    assert check_score(1, dict_value, 7) == 1
    assert check_score(2, dict_value, 7) == 0
    assert check_score(3, dict_value, 7) == 0
    assert check_score(4, dict_value, 7) == 0
    assert check_score(1, dict_value, 8) == 0
    assert check_score(2, dict_value, 8) == 0
    assert check_score(3, dict_value, 8) == 1
    assert check_score(4, dict_value, 8) == 0
    assert check_score(1, dict_value, 9) == 0
    assert check_score(2, dict_value, 9) == 0
    assert check_score(3, dict_value, 9) == 0
    assert check_score(4, dict_value, 9) == 1

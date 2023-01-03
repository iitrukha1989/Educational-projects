from main import choose_plural


def test_check_number():
    """
    Тестирование функции склонения слова балл
    :return: 
    """
    assert choose_plural(1) == 'балл'
    assert choose_plural(3) == 'балла'
    assert choose_plural(13) == 'баллов'
    assert choose_plural(29) == 'баллов'
    assert choose_plural(80) == 'баллов'
    assert choose_plural(108) == 'баллов'
    assert choose_plural(241) == 'балл'
    assert choose_plural(359) == 'баллов'
    assert choose_plural(742) == 'балла'
    assert choose_plural(901) == 'балл'
    assert choose_plural(1_015) == 'баллов'
    assert choose_plural(1_261) == 'балл'
    assert choose_plural(5_203) == 'балла'
    assert choose_plural(10_001) == 'балл'
    assert choose_plural(234_215) == 'баллов'
    assert choose_plural(1_652_873) == 'балла'

from os import system, name
import random
import json

DATABASE = 'database.json'


def clear():
    """
    Функция очитски терминала
    :return:
    """
    if name == 'nt':
        _ = system('cls')
    else:
        _ = system('clear')


def check_digit(answer_value: str):
    """
    Функция проверки аргумента на тип данных Integer
    :param answer_value:
    :return: boolean
    """
    try:
        str(answer_value).isdigit()
        (isinstance(int(answer_value), int))
        return True
    except:
        return False


def output_question_otion(dict_value: dict, q_index: int):
    """
    Функция (опционная) на вывод содержание вопроса и вариантов ответа
    :param dict_value:
    :param q_index:
    :return:
    """
    print(dict_value[q_index]['question'])
    for tmp_value in dict_value[q_index]['answers']:
        print(f"{tmp_value['id']} : {tmp_value['text']}")


def output_question(dict_value: dict, q_index: int):
    """
    Функция по выводу вопроса, ввода и обработки ответа
    :param dict_value:
    :param q_index:
    :return: str
    """
    output_question_otion(dict_value, q_index)
    answer_value = input()
    while True:
        if check_digit(answer_value):
            break
        else:
            clear()
            output_question_otion(dict_value, q_index)
            answer_value = input()
    return answer_value


def check_score(answer_value: str, dict_value: dict, q_index: int):
    """
    Функция по проверки правильности введенного ответа
    :param answer_value:
    :param dict_value:
    :param q_index:
    :return: int
    """
    res_value = 0
    for tmp_value in dict_value[q_index]['answers']:
        if tmp_value['id'] == int(answer_value):
            res_value = tmp_value['score']
            break
    return res_value


def output_result(count_question: int, count_correct: int, human_variables_list: list):
    """
    Функция по обработке и выводу результатов тестирования
    :param count_question:
    :param count_correct:
    :param human_variables_list:
    :return:
    """
    if count_correct >= (count_question - count_correct) and check_human(human_variables_list):
        print('Тест завершен!')
        print(f'Вы набрали {count_correct} {choose_plural(count_correct)}')
        print('Поздравляю, Вы человек!')
    else:
        print('Тест завершен!')
        print(f'Вы набрали {count_correct} {choose_plural(count_correct)}')
        print('Поздравляю, Вы робот!')


def choose_plural(count_correct: int, declensions=('балл', 'балла', 'баллов')):
    """
    Функция по проверки формы склонения слова балл
    :param count_correct:
    :param declensions:
    :return: str
    """
    if 10 <= count_correct % 100 <= 20:
        return declensions[2]
    if count_correct % 10 == 1:
        return declensions[0]
    if 2 <= count_correct % 10 <= 4:
        return declensions[1]
    if count_correct % 10 == 0 or count_correct % 10 >= 5:
        return declensions[2]


def check_human(human_variables_list: list):
    """
    Функция по проверке разницы среднего значения показателей
    :param human_variables_list:
    :return:
    """
    check_value = 0
    if human_variables_list and len(human_variables_list) == 4:
        for human_value, avg_value in zip(human_variables_list, (140, 800, 30, 60)):
            if check_digit(human_value) and int(human_value) >= avg_value:
                check_value += 1
        return (check_value == 4)
    else:
        return False


def if_human_variables():
    """
    Функция по сбору информации в части показателей
    :return: tuple
    """
    print('После каждого ответа внесите свои показатели:')
    respiration_value = input('Дыхание (обычно около 12-16 вдохов в минуту): ')
    while True:
        if check_digit(respiration_value) and 12 <= int(respiration_value) <= 16:
            break
        else:
            clear()
            respiration_value = input(
                'Дыхание (обычно около 12-16 вдохов в минуту): ')
    clear()
    heart_value = input('Частота сердечных сокращений (обычно около 60-100): ')
    while True:
        if check_digit(heart_value) and 60 <= int(heart_value) <= 100:
            break
        else:
            clear()
            heart_value = input(
                'Частота сердечных сокращений (обычно около 60-100): ')
    clear()
    blushing_value = input(
        'Уровень покраснения (окатегориальный, 6 возможных уровней): ')
    while True:
        if check_digit(blushing_value) and 0 <= int(blushing_value) <= 6:
            break
        else:
            clear()
            blushing_value = input(
                'Уровень покраснения (окатегориальный, 6 возможных уровней): ')
    clear()
    pupillary_value = input(
        'Расширение зрачка (текущий размер зрачка от 2 до 8 мм): ')
    while True:
        if check_digit(pupillary_value) and 2 <= int(pupillary_value) <= 8:
            break
        else:
            clear()
            pupillary_value = input(
                'Расширение зрачка (текущий размер зрачка от 2 до 8 мм): ')
    clear()
    return (respiration_value, heart_value, blushing_value, pupillary_value)


def is_test():
    """
    Функция тестирования на эмпатию
    :return:
    """
    count_question = 0
    count_correct = 0
    human_variables_list = [0, 0, 0, 0]
    with open(DATABASE) as json_file:
        clear()
        dict_value = json.load(json_file)
        dict_value = dict_value['item']
        list_value = [tmp_value for tmp_value in range(10)]
        random.shuffle(list_value)
        for q_index in list_value:
            answer_value = output_question(dict_value, q_index)
            while True:
                if len(dict_value[q_index]['answers']) >= int(answer_value) >= 1:
                    break
                clear()
                answer_value = output_question(dict_value, q_index)
            clear()
            count_question += 1
            count_correct += check_score(answer_value, dict_value, q_index)
            for tmp_index, tmp_value in enumerate(if_human_variables()):
                human_variables_list[tmp_index] += int(tmp_value)
    output_result(count_question, count_correct, human_variables_list)


def main():
    """
    Основная функция запуска программы/скрипта
    :return:
    """
    try:
        is_test()
    except KeyboardInterrupt:
        clear()
        print('Тест прерван!')


if __name__ == '__main__':
    main()

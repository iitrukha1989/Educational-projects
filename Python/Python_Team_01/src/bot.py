# @SuperDuperGame_3534543_bot

import config
import json
import telebot
from telebot import types


bot = telebot.TeleBot(config.token)

PERSON = ''
PLANET = ''


def load_file(db):
    with open(db, 'r', encoding='utf8') as file:
        return json.load(file)


def get_planet_name(input):
    data = load_file('location_database.json')
    planet = data['locations']
    if input == 'person_1':
        return planet['1']['name']
    elif input == 'person_2':
        return planet['2']['name']
    elif input == 'person_3':
        return planet['3']['name']
    elif input == 'person_4':
        return planet['4']['name']


def get_person_name(input):
    data = load_file('player_database.json')
    person = data['player']
    if input == 'person_1':
        return person['1']['name']
    elif input == 'person_2':
        return person['2']['name']
    elif input == 'person_3':
        return person['3']['name']
    elif input == 'person_4':
        return person['4']['name']


def get_planet_num():
    data_planet = load_file('location_database.json')
    planet = data_planet['locations']
    planet_num = []
    for i in range(1, len(planet) + 1):
        planet_num.append(planet[str(i)]['name'])
    return planet_num.index(PLANET) + 1


def get_npc():
    data_npc = load_file('npc_database.json')
    npc = data_npc['npc']
    data_planet = load_file('location_database.json')
    planet = data_planet['locations']
    planet_num = get_planet_num()
    valid_npc = planet[str(planet_num)]['npc']
    res = []
    for i in range(1, len(npc) + 1):
        if str(i) in valid_npc:
            res.append(npc[str(i)]['name'])
    return res


def get_npc_question():
    data = load_file('dialog_database.json')
    npc_question = data['item']
    res = []
    for i in range(len(npc_question)):
        res.append(npc_question[i]['question'])
    return res


def get_talk():
    data = load_file('dialog_database.json')
    person = data['item']
    if input == 'person_1':
        return person['1']['name']
    elif input == 'person_2':
        return person['2']['name']
    elif input == 'person_3':
        return person['3']['name']
    elif input == 'person_4':
        return person['4']['name']


def get_enemy():
    data_planet = load_file('location_database.json')
    planet = data_planet['locations']
    planet_num = get_planet_num()
    select_enemy = planet[str(planet_num)]['enemy']
    data_enemy = load_file('enemy_database.json')
    enemy = data_enemy['enemy']
    return enemy[select_enemy[0]]['name']


def get_planet():
    planet_data = load_file('location_database.json')
    planet = planet_data['locations']
    planet_list = []
    for i in range(1, len(planet) + 1):
        planet_list.append(planet[str(i)]['name'])
    return planet_list


@bot.message_handler(commands=['start'])
def welcome(message):
    bot.send_message(
        message.chat.id, text='Привет, юный падаван! Сейчас мы сыграем в игру "Звездные войны".')
    start(message)


@bot.message_handler(commands=[])
def start(message):
    markup = types.InlineKeyboardMarkup(row_width=2)
    button_1 = types.InlineKeyboardButton(
        text='Luke', callback_data='person_1')
    button_2 = types.InlineKeyboardButton(
        text='Han Solo', callback_data='person_2')
    button_3 = types.InlineKeyboardButton(
        text='Mandolorian', callback_data='person_3')
    button_4 = types.InlineKeyboardButton(
        text='Obi-Van Kenobi', callback_data='person_4')
    markup.add(button_1, button_2, button_3, button_4)
    bot.send_message(
        message.chat.id, text='Выберите персонажа', reply_markup=markup)


@bot.callback_query_handler(func=lambda call: True)
def select_person(call):
    if call.message:
        if str(call.data).startswith('person_'):  # Главное меню
            global PERSON
            PERSON = call.data
            global PLANET
            PLANET = get_planet_name(call.data)
            markup = types.InlineKeyboardMarkup(row_width=3)
            button_1 = types.InlineKeyboardButton(
                text='Поговорить', callback_data='action_talk')
            button_2 = types.InlineKeyboardButton(
                text='Подраться', callback_data='action_punch')
            button_3 = types.InlineKeyboardButton(
                text='Сменить планету', callback_data='action_change_planet')
            markup.add(button_1, button_2, button_3)
            bot.send_message(call.message.chat.id, text='Вы ' + get_person_name(
                call.data) + '. Вы находитесь на планете ' + PLANET + '.', reply_markup=markup)

        if call.data == 'action_talk':  # Получить список NPC на планете
            npc = get_npc()
            markup = types.InlineKeyboardMarkup(row_width=3)
            keyboard = []
            for i in range(len(npc)):
                button = types.InlineKeyboardButton(
                    text=npc[i], callback_data='talk_npc_' + str(i))
                keyboard.append(button)
            markup.add(*keyboard)
            button_back = types.InlineKeyboardButton(
                text='НАЗАД', callback_data='back')
            markup.row(button_back)
            bot.send_message(call.message.chat.id,
                             text='Выберите NPC', reply_markup=markup)

        if str(call.data).startswith('talk_npc_'):  # Получить список вопросов NPC
            npc_question = get_npc_question()
            markup = types.InlineKeyboardMarkup(row_width=1)
            keyboard = []
            for i in range(len(npc_question)):
                button = types.InlineKeyboardButton(
                    text=npc_question[i], callback_data='npc_question' + str(i))
                keyboard.append(button)
            markup.add(*keyboard)
            button_back = types.InlineKeyboardButton(
                text='НАЗАД', callback_data='back')
            markup.row(button_back)
            bot.send_message(call.message.chat.id,
                             text='Выберите вопрос', reply_markup=markup)

        if call.data == 'action_punch':  # Меню драки
            markup = types.InlineKeyboardMarkup(row_width=2)
            button_1 = types.InlineKeyboardButton(
                text='Ударить', callback_data='action_punch_punch')
            button_2 = types.InlineKeyboardButton(
                text='Сбежать', callback_data='action_punch_run')
            markup.add(button_1, button_2)
            button_back = types.InlineKeyboardButton(
                text='НАЗАД', callback_data='back')
            markup.row(button_back)
            bot.send_message(call.message.chat.id, text='Перед вами ' +
                             get_enemy() + '. Выберите действие.', reply_markup=markup)

        if call.data == 'action_punch_punch':  # Если ударил
            bot.send_message(call.message.chat.id, text='Вы нанесли удар.')

        if call.data == 'action_punch_run':  # Если сбежал
            bot.send_message(call.message.chat.id, text='Вы сбежали.')

        if call.data == 'action_change_planet':  # Меню выбора планеты
            planet = get_planet()
            markup = types.InlineKeyboardMarkup(row_width=3)
            keyboard = []
            for i in range(len(planet)):
                button = types.InlineKeyboardButton(
                    text=planet[i], callback_data='to_planet_' + str(planet[i]))
                keyboard.append(button)
            markup.add(*keyboard)
            button_back = types.InlineKeyboardButton(
                text='НАЗАД', callback_data='back')
            markup.row(button_back)
            bot.send_message(call.message.chat.id,
                             text='Выберите планету', reply_markup=markup)

        if str(call.data).startswith('to_planet_'):  # Смена планеты
            PLANET = call.data.split('_')[2]
            bot.send_message(call.message.chat.id,
                             text='Вы находитесь на планете ' + PLANET + ' .')

        if call.data == 'back':
            bot.delete_message(call.message.chat.id, call.message.message_id)


if __name__ == "__main__":
    bot.polling(none_stop=True)

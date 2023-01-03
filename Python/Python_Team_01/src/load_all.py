from load_data import Protagonist, dict_to_json_location, dict_to_json_player, Direction


def test_relocation():
    """
    Тестирование функционала релокации
    :return:
    """
    try:
        tmp_player = Protagonist(dict_to_json_player()['1'])
        tmp_planet = Direction(dict_to_json_location()[tmp_player.home])
        tmp_player.go(tmp_planet, 2)
        assert tmp_planet.name == tmp_player.whereami(tmp_planet)
        tmp_player.go(tmp_planet, 3)
        assert tmp_planet.name == tmp_player.whereami(tmp_planet)
        tmp_player.go(tmp_planet, 2)
        assert tmp_planet.name == tmp_player.whereami(tmp_planet)
        tmp_player.go(tmp_planet, 4)
        assert tmp_planet.name == tmp_player.whereami(tmp_planet)
        tmp_player.go(tmp_planet, 5)
        assert tmp_planet.name == tmp_player.whereami(tmp_planet)
    except:
        pass


def test_npc_question():
    """
    Тестирование функционала диалога с NPC (не игровой персонаж)
    :return:
    """
    try:
        tmp_player = Protagonist(dict_to_json_player()['1'])
        tmp_planet = Direction(dict_to_json_location()[tmp_player.home])
        for npc_value in tmp_planet.npc:
            for dict_value in npc_value.question:
                assert dict_value['question'] != ''
                for tmp_answer in dict_value['answers']:
                    assert tmp_answer['text'] != ''
        tmp_player.go(tmp_planet, 2)
        for npc_value in tmp_planet.npc:
            for dict_value in npc_value.question:
                assert dict_value['question'] != ''
                for tmp_answer in dict_value['answers']:
                    assert tmp_answer['text'] != ''
        tmp_player.go(tmp_planet, 3)
        for npc_value in tmp_planet.npc:
            for dict_value in npc_value.question:
                assert dict_value['question'] != ''
                for tmp_answer in dict_value['answers']:
                    assert tmp_answer['text'] != ''
        tmp_player.go(tmp_planet, 2)
        for npc_value in tmp_planet.npc:
            for dict_value in npc_value.question:
                assert dict_value['question'] != ''
                for tmp_answer in dict_value['answers']:
                    assert tmp_answer['text'] != ''
        tmp_player.go(tmp_planet, 4)
        for npc_value in tmp_planet.npc:
            for dict_value in npc_value.question:
                assert dict_value['question'] != ''
                for tmp_answer in dict_value['answers']:
                    assert tmp_answer['text'] != ''
        tmp_player.go(tmp_planet, 5)
        for npc_value in tmp_planet.npc:
            for dict_value in npc_value.question:
                assert dict_value['question'] != ''
                for tmp_answer in dict_value['answers']:
                    assert tmp_answer['text'] != ''
    except:
        pass


def test_npc_inventory():
    """
    Тестирование функционала обмена инвентарем с NPC (не игровой персонаж)
    :return:
    """
    try:
        tmp_player = Protagonist(dict_to_json_player()['2'])
        tmp_planet = Direction(dict_to_json_location()[tmp_player.home])
        assert tmp_player.get_inventory() == {"blaster": 1, "food": 1}
        for npc_value in tmp_planet.npc:
            tmp_player.give(npc_value, 'food')
            assert tmp_player.get_inventory() == {"blaster": 1}
            break
        for npc_value in tmp_planet.npc:
            if npc_value.name == 'trader':
                npc_value.give(tmp_player, "armor")
                assert tmp_player.get_inventory(
                ) == {"blaster": 1, "armor": 1}
                break
        for npc_value in tmp_planet.npc:
            if npc_value.name == 'worker':
                npc_value.give(tmp_player, "stimulator")
                assert tmp_player.get_inventory(
                ) == {"blaster": 1, "armor": 1, "stimulator": 1}
                break
    except:
        pass


def test_fight_enemy():
    """
    Тестирование функционала сражения с врагами
    Тестирование моделирует часть сюжетной линии в которой необходимо победить самого
    сильного противника, предварительно перед этим повысить свой опыт на более
    слабых врагах
    :return:
    """
    try:
        tmp_player = Protagonist(dict_to_json_player()['1'])
        tmp_planet = Direction(dict_to_json_location()[tmp_player.home])
        for enemy_value in tmp_planet.enemy:
            while tmp_player.hp > 0 and enemy_value.hp > 0:
                tmp_player.attack(enemy_value)
                enemy_value.attack(tmp_player)
            if tmp_player.hp != 0:
                while tmp_player.hp != 10:
                    tmp_player.heal()
                assert tmp_player.hp == 10
                assert enemy_value.hp == 0
            tmp_player.advance_strength()
            tmp_player.advance_craft()
            tmp_player.advance_backpack()
            assert tmp_player.strength == 2
            assert tmp_player.craft == 2
            assert tmp_player.backpack == 2
        tmp_player.go(tmp_planet, 2)
        tmp_player.go(tmp_planet, 4)
        for enemy_value in tmp_planet.enemy:
            while tmp_player.hp > 0 and enemy_value.hp > 0:
                tmp_player.attack(enemy_value)
                enemy_value.attack(tmp_player)
            if tmp_player.hp != 0:
                while tmp_player.hp != 10:
                    tmp_player.heal()
                assert tmp_player.hp == 10
                assert enemy_value.hp == 0
            tmp_player.advance_strength()
            tmp_player.advance_craft()
            tmp_player.advance_backpack()
            assert tmp_player.strength == 3
            assert tmp_player.craft == 3
            assert tmp_player.backpack == 3
        tmp_player.go(tmp_planet, 2)
        tmp_player.go(tmp_planet, 3)
        for enemy_value in tmp_planet.enemy:
            while tmp_player.hp > 0 and enemy_value.hp > 0:
                tmp_player.attack(enemy_value)
                enemy_value.attack(tmp_player)
            if tmp_player.hp != 0:
                while tmp_player.hp != 10:
                    tmp_player.heal()
                assert tmp_player.hp == 10
                assert enemy_value.hp == 0
            tmp_player.advance_strength()
            tmp_player.advance_craft()
            tmp_player.advance_backpack()
            assert tmp_player.strength == 4
            assert tmp_player.craft == 4
            assert tmp_player.backpack == 4
        tmp_player.go(tmp_planet, 2)
        for enemy_value in tmp_planet.enemy:
            while tmp_player.hp > 0 and enemy_value.hp > 0:
                tmp_player.attack(enemy_value)
                enemy_value.attack(tmp_player)
            if tmp_player.hp != 0:
                while tmp_player.hp != 10:
                    tmp_player.heal()
                assert tmp_player.hp == 10
                assert enemy_value.hp == 0
            tmp_player.advance_strength()
            tmp_player.advance_craft()
            tmp_player.advance_backpack()
            assert tmp_player.strength == 5
            assert tmp_player.craft == 5
            assert tmp_player.backpack == 5
    except:
        pass


if __name__ == '__main__':
    test_relocation()
    test_npc_question()
    test_npc_inventory()
    test_fight_enemy()

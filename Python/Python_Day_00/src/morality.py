from collections import Counter
from random import randint


class Game():
    """Класс игра, выполнять симуляцию заданного количества матчей между
    игроками с заданной моделью поведения поведением."""

    def __init__(self, matches=10):
        self.matches = matches
        self.registry = Counter()

    def full_play(self, *args):
        for player_index_1 in range(len(args)):
            for player_index_2 in range(player_index_1 + 1, len(args)):
                self.play(args[player_index_1], args[player_index_2])

    def play(self, player1, player2):
        for _ in range(self.matches):
            self.update_candy(player1, player2)
            tmp_behave_1 = player1.get_behave()
            tmp_behave_2 = player2.get_behave()
            player1.set_behave(tmp_behave_2)
            player2.set_behave(tmp_behave_1)
        self.update_registry(player1, player2)
        player1.reset_player()
        player2.reset_player()

    def update_candy(self, player1, player2):
        if player1.get_behave() == 0 and player2.get_behave() == 0:
            player1.set_candy(2)
            player2.set_candy(2)
        elif player1.get_behave() == 0 and player2.get_behave() == 1:
            player1.set_candy(-1)
            player2.set_candy(3)
        elif player1.get_behave() == 1 and player2.get_behave() == 0:
            player1.set_candy(3)
            player2.set_candy(-1)

    def update_registry(self, player1, player2):
        self.registry[str(player1)] += player1.get_candy()
        self.registry[str(player2)] += player2.get_candy()

    def top3(self):
        return self.registry.most_common(3)


class Player:
    """Базовый класс игрок, описывает основные свойства и методы игроков,
    внезависимости от их модели поведения"""

    def __init__(self):
        self.candy = 0
        self.behave = 0

    # установить новое значение конфет
    def set_candy(self, candy):
        self.candy += candy

    # вернуть текущее значение конфет
    def get_candy(self):
        return self.candy

    # вернуть текущее значение поведения игрока
    def get_behave(self):
        return self.behave


class PlayerCheater(Player):
    """Подкласс Обманщик, наследуется от базового класса игрока,
    описывает свойства и методы игрока с соответсвующей поведения"""

    def __init__(self):
        super().__init__()
        self.behave = 1  # 0 - Cooperator, 1 - Cheater

    def __str__(self):
        return 'Cheater'

    def reset_player(self):
        self.candy = 0
        self.behave = 1

    def set_behave(self, behave_enemy):
        self.behave = 1


class PlayerCooperator(Player):
    """Подкласс Наивный, наследуется от базового класса игрока,
    описывает свойства и методы игрока с соответсвующей моделью поведения"""

    def __init__(self):
        super().__init__()
        self.behave = 0  # 0 - Cooperator, 1 - Cheater

    def __str__(self):
        return 'Cooperator'

    def reset_player(self):
        self.candy = 0
        self.behave = 0

    def set_behave(self, behave_enemy):
        self.behave = 0


class PlayerCopycat(Player):
    """Подкласс Имитатор, наследуется от базового класса игрока,
    описывает свойства и методы игрока с соответсвующей моделью поведения"""

    def __init__(self):
        super().__init__()
        self.behave = 0  # 0 - Cooperator, 1 - Cheater

    def __str__(self):
        return 'Copycat'

    def reset_player(self):
        self.candy = 0
        self.behave = 0

    def set_behave(self, behave_enemy):
        self.behave = behave_enemy


class PlayerGrudger(Player):
    """Подкласс Злопамятный, наследуется от базового класса игрока,
    описывает свойства и методы игрока с соответсвующей моделью поведения"""

    def __init__(self):
        super().__init__()
        self.behave = 0  # 0 - Cooperator, 1 - Cheater

    def __str__(self):
        return 'Grudger'

    def reset_player(self):
        self.candy = 0
        self.behave = 0

    def set_behave(self, behave_enemy):
        if behave_enemy == 1:
            self.behave = 1


class PlayerDetective(Player):
    """Подкласс Детектив, наследуется от базового класса игрока,
    описывает свойства и методы игрока с соответсвующей моделью поведения"""

    def __init__(self):
        super().__init__()
        self.behave = 0  # 0 - Cooperator, 1 - Cheater
        self.count = 0  # счетчик по значению итерации
        self.check = 0

    def __str__(self):
        return 'Detective'

    def reset_player(self):
        self.candy = 0
        self.behave = 0
        self.count = 0
        self.check = 0

    def set_behave(self, behave_enemy):
        if behave_enemy == 1 and self.count <= 2:
            self.check = 1
        if self.count == 0:
            self.behave = 1
        if self.count in [1, 2]:
            self.behave = 0
        if self.count > 2 and self.check == 0:
            self.behave = 1
        if self.count > 2 and self.check == 1:
            self.behave = behave_enemy
        self.count += 1


class PlayerRandom(Player):
    """Бонусный подкласс Случайный, наследуется от базового класса игрока,
    описывает свойства и методы игрока с соответсвующей моделью
    поведения"""

    def __init__(self):
        super().__init__()
        self.behave = 0  # 0 - Cooperator, 1 - Cheater

    def __str__(self):
        return 'Random'

    def reset_player(self):
        self.candy = 0
        self.behave = 0

    def set_behave(self, behave_enemy):
        self.behave = randint(0, 1)


class PlayerSimpletons(Player):
    """Бонусный подкласс Простак, наследуется от базового класса игрока,
    описывает свойства и методы игрока с соответсвующей моделью
    поведения"""

    def __init__(self):
        super().__init__()
        self.behave = 0

    def __str__(self) -> str:
        return 'Simpletons'

    def reset_player(self):
        self.candy = 0
        self.behave = 0

    def set_behave(self, behave_enemy):
        if behave_enemy == 1:
            if self.behave == 1:
                self.behave = 0
            if self.behave == 0:
                self.behave = 1


class PlayerCopykitten(Player):
    """Бонусный подкласс Подражатель, наследуется от базового класса игрока,
    описывает свойства и методы игрока с соответсвующей моделью поведения"""

    def __init__(self):
        super().__init__()
        self.behave = 0
        self.behave_enemy = 0
        self.count = 0

    def __str__(self) -> str:
        return 'Copykitten'

    def reset_player(self):
        self.candy = 0
        self.behave = 0
        self.behave_enemy = 0
        self.count = 0

    def set_behave(self, behave_enemy):
        if behave_enemy == 1:
            if self.behave_enemy == 0 and self.count == 0:
                self.behave_enemy = 1
                self.count += 1
            else:
                self.behave = 1
        if behave_enemy == 0:
            self.behave = 0
            self.behave_enemy = 0
            self.count = 0


def main():
    print('------------- main_test -----------')
    game_value_1 = Game()
    game_value_1.full_play(PlayerCopycat(), PlayerCheater(),
                           PlayerCooperator(), PlayerGrudger(),
                           PlayerDetective())
    print(*game_value_1.top3(), sep='\n')
    print('------ bonus_test_simpletons ------')
    game_value_2 = Game()
    game_value_2.full_play(PlayerSimpletons(), PlayerCopycat(),
                           PlayerCheater(), PlayerCooperator(),
                           PlayerGrudger(), PlayerDetective())
    print(*game_value_2.top3(), sep='\n')
    print('------ bonus_test_copykitten ------')
    game_value_3 = Game()
    game_value_3.full_play(PlayerCopykitten(), PlayerCopycat(),
                           PlayerCheater(), PlayerCooperator(),
                           PlayerGrudger(), PlayerDetective())
    print(*game_value_3.top3(), sep='\n')
    print('------- bonus_test_random --------')
    game_value_4 = Game()
    game_value_4.full_play(PlayerRandom(), PlayerCopycat(),
                           PlayerCheater(), PlayerCooperator(),
                           PlayerGrudger(), PlayerDetective())
    print(*game_value_4.top3(), sep='\n')
    print('-------_ bonus_test_all ----------')
    game_value_5 = Game()
    game_value_5.full_play(PlayerSimpletons(), PlayerCopykitten(),
                           PlayerRandom(), PlayerCopycat(),
                           PlayerCheater(), PlayerCooperator(),
                           PlayerGrudger(), PlayerDetective())
    print(*game_value_5.top3(), sep='\n')


if __name__ == '__main__':
    main()

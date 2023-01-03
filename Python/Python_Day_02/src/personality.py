from random import randint
import time


def shoot(self):
    print('shoot')


def search(self):
    print('search')


def talk(self):
    print('talk')


def get_action():
    return {'shoot': shoot, 'search': search, 'talk': talk}


def get_traits():
    traits_list = ('neuroticism', 'openness', 'conscientiousness',
                   'extraversion', 'agreeableness')
    while True:
        list_value = list([randint(0, 100) for _ in range(5)])
        if sum(list_value) == 100:
            break
    return dict(zip(traits_list, list_value))


def turrets_generator():
    while True:
        time.sleep(0.2)
        yield type('Turret', (object, ), dict(get_traits() | get_action()))


def main():
    MyTurrets = turrets_generator()
    for turret_value in MyTurrets:
        print(type(turret_value))
        print(turret_value.neuroticism, turret_value.openness,
              turret_value.conscientiousness, turret_value.extraversion,
              turret_value.agreeableness)
        turret_value.shoot(MyTurrets), turret_value.search(MyTurrets),
        turret_value.talk(MyTurrets)


if __name__ == '__main__':
    main()

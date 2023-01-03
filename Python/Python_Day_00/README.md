# Индивидуальный, учебный проект 00 - Python Bootcamp

## Contents

1. [Chapter I](#chapter-i) \
    1.1. [EX00](#ex00)
2. [Chapter II](#chapter-ii) \
    2.1. [EX01](#ex01)

## Chapter I
### EX00

Вам нужно описать класс `Python 'Key'` так, чтобы экземпляр этого класса прошел перечисленные выше проверки. 
Имейте в виду, что ваш код в этом упражнении не должен создавать никаких 
контейнеров ни размером 404, ни меньше. Даже без него вы сможете пройти эти проверки.

```
AssertionError: len(key) == 1337
AssertionError: key[404] == 3
AssertionError: key > 9000
AssertionError: key.passphrase == "zax2rulez"
AssertionError: str(key) == "GeneralTsoKeycard"

```

## Chapter II
### EX01

Реализовать игру Мораль (Теория игр/Обмони меня)

По умолчанию код при запуске должен имитировать 10 совпадений 
(один вызов `play()`) между каждой парой двух игроков с разными типами поведения 
(всего 10 раундов по 10 совпадений в каждом, отсутствие совпадений между двумя 
копиями одного и того же поведения) и вывести трех лучших победителей. после всей игры.

#### Общие правила игры:

Итак, если все сотрудничают и кладут конфеты в автомат, как и было согласовано, 
каждый получает вознаграждение. Но у обоих участников также есть соблазн схитрить и 
только сделать вид, что они положили конфету в автомат, потому что в этом случае их 
группа получит обратно 3 конфеты, просто забрав одну конфету у второй группы. 
Проблема в том, что если оба оператора решат играть грязно, то никто ничего не получит.

|  | Both cooperate | 1 cheats, 2 cooperates | 1 cooperates, 2 cheats | Both cheat |
|------------|----------|----------|----------|---------|
| Operator 1 | +2 candy | +3 candy | -1 candy | 0 candy |
| Operator 2 | +2 candy | -1 candy | +3 candy | 0 candy |

#### Участники игры:

| Behavior type | Player Actions                                                                                                                                                                                         |
|---------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Cheater       | Always cheats                                                                                                                                                                                          |
| Cooperator    | Always cooperates                                                                                                                                                                                      |
| Copycat       | Starts with cooperating, but then just repeats whatever the other guy is doing                                                                                                                         |
| Grudger       | Starts by always cooperating, but switches to Cheater forever if another guy cheats even once                                                                                                          |
| Detective     | First four times goes with [Cooperate, Cheat, Cooperate, Cooperate],  and if during these four turns another guy cheats even once -  switches into a Copycat. Otherwise, switches into Cheater himself |

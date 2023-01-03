# Индивидуальный, учебный проект 06 - Python Bootcamp

## Contents

1. [Chapter I](#chapter-i) \
    1.1. [EX00](#ex00)
2. [Chapter II](#chapter-ii) \
    2.1. [EX01](#ex01)
3. [Chapter III](#chapter-iii) \
    3.1. [EX02](#ex02)

## Chapter I
### EX00


```
import asyncio

from enum import Enum, auto
from random import choice


class Action(Enum):
    HIGHKICK = auto()
    LOWKICK = auto()
    HIGHBLOCK = auto()
    LOWBLOCK = auto()


class Agent:

    def __aiter__(self, health=5):
        self.health = health
        self.actions = list(Action)
        return self

    async def __anext__(self):
        return choice(self.actions)
```

Вы должны написать скрипт под названием `fight.py`, который будет включать в себя немодифицированный код выше, 
а также асинхронную функцию `fight ()`, которая будет реализовывать логику, описанную выше.

Вывод скрипта может выглядеть следующим образом (поскольку действия рандомизированы, фактический результат будет 
другим при каждом запуске):

```
Agent: Action.HIGHBLOCK, Neo: Action.LOWKICK, Agent Health: 4
Agent: Action.LOWBLOCK, Neo: Action.HIGHKICK, Agent Health: 3
Agent: Action.LOWKICK, Neo: Action.LOWBLOCK, Agent Health: 3
Agent: Action.HIGHKICK, Neo: Action.HIGHBLOCK, Agent Health: 3
Agent: Action.LOWBLOCK, Neo: Action.HIGHKICK, Agent Health: 2
Agent: Action.LOWKICK, Neo: Action.LOWBLOCK, Agent Health: 2
Agent: Action.HIGHKICK, Neo: Action.HIGHBLOCK, Agent Health: 2
Agent: Action.LOWKICK, Neo: Action.LOWBLOCK, Agent Health: 2
Agent: Action.HIGHBLOCK, Neo: Action.LOWKICK, Agent Health: 1
Agent: Action.HIGHBLOCK, Neo: Action.LOWKICK, Agent Health: 0
Neo wins!
```

## Chapter II
### EX01

Программа должна состоять из двух файлов - `crawl.py` и `server.py`. Рекомендуется использовать `aiohttp` или `httpx` 
для клиентской части и `FastAPI` для серверной. Весь код ввода-вывода должен быть асинхронным.

Рабочий процесс выглядит следующим образом:

1. сервер запущен и прослушивает порт 8888
2. `client(crawl.py)` получает один или несколько запрашиваемых URL в качестве аргумента
3. клиент отправляет все URL-адреса через запрос HTTP POST в виде списка JSON на конечную точку сервера `/api/v1/tasks/`
4. сервер отвечает созданным HTTP 201 и объектом задачи
5. объект задачи включает статус «выполняется» и идентификатор UUID4.
6. затем сервер запускается асинхронно (не используйте потоки или многопроцессорность) отправляет запросы HTTP GET на отправленные URL-адреса и собирает коды ответов HTTP, будь то 200, 404 или какой-либо другой
7. клиент продолжает периодически запрашивать конечную точку `/api/v1/tasks/{received_task_id}`, пока сервер не завершит обработку всех URL-адресов. Затем статус задачи должен измениться на «готово», а в поле «результат» задачи должен быть список кодов ответов HTTP для отправленных URL-адресов.
8. клиент распечатывает разделенный табуляцией код ответа HTTP и соответствующий URL-адрес для каждой записи

## Chapter III
### EX02

Вы должны использовать `Redis` как для кэша, так и для счетчиков домена. Весь код по-прежнему должен быть асинхронным и 
использовать парадигму `async/await`. Вы можете рассмотреть возможность использования библиотеки aioredis для этой задачи. 
Поскольку код клиента не затрагивается, вы должны отправить только один файл с измененным кодом сервера EX01 под 
названием `server_cached.py`.

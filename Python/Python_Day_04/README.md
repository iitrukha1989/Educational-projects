# Индивидуальный, учебный проект 04 - Python Bootcamp

## Contents

1. [Chapter I](#chapter-i) \
    1.1. [EX00](#ex00)
2. [Chapter II](#chapter-ii) \
    2.1. [EX01](#ex01)
3. [Chapter III](#chapter-iii) \
    3.1. [EX02](#ex02)

## Chapter I
### EX00

Сюжетная предыстория:

Основной протокол, используемый для межпространственной связи, назывался `Protobuf 2.0`. Записи отправлялись через 
транспорт под названием `gRPC`. Итак, это был первый слой, который Эндер должен был реализовать.
Поскольку `gRPC` — это инфраструктура связи клиент-сервер, необходимо было реализовать два компонента — 
`reporting_server.py` и `reporting_client.py`. 

Сервер должен предоставить конечную точку потоковой передачи ответов, где он получает набор координат, 
и отвечает потоком записей космического корабля.
Поскольку в настоящее время это тестовая среда, хотя каждый космический корабль должен иметь все упомянутые параметры, 
они могут быть случайными. Кроме того, они должны быть строго типизированы, например:

- Свой/чужой (система распознания) - перечисление
- Имя корабля - строка
- Длина корабля - цифра с плавающей точкой
- Класс корабля - перечисление
- Размер корабля — целое число
- Вооруженный статус - логическим
- Количество офицеров - перечисление

У каждого офицера на борту должно быть имя, фамилия и звание в виде строк.
Количество офицеров на борту — случайное число от 0 (только для вражеских кораблей) до 10.

Рабочий процесс должен быть таким:

Сервер запущен
Клиент запускается с заданным набором координат в выбранной форме, например:

`./reporting_client.py 17 45 40.0409 −29 00 28.118`


 ```
  {
    "alignment": "Ally",
    "name": "Normandy",
    "class": "Corvette",
    "length": 216.3,
    "crew_size": 8,
    "armed": true,
    "officers": [{"first_name": "Alan", "last_name": "Shepard", "rank": "Commander"}]
  }
  {
    "alignment": "Enemy",
    "name": "Executor",
    "class": "Dreadnought",
    "length": 19000.0,
    "crew_size": 450,
    "armed": true,
    "officers": []
  }
  ```

## Chapter II
### EX01

Необходимо сделать еще одну/другую версию клиента (`reporting_client_v2.py`), 
которая будет работать с этим же сервером. Но на этот раз он должен проверить поток космических кораблей с помощью 
`Pydantic` и отфильтровать те, у которых некоторые параметры выходят за пределы, в соответствии с таблицей ниже. 
Остальное должно быть напечатано точно так же, как в `EX00`.

| Class       | Length     | Crew    | Can be armed? | Can be hostile? |
|-------------|------------|---------|---------------|-----------------|
| Corvette    | 80-250     | 4-10    | Yes           | Yes             |
| Frigate     | 300-600    | 10-15   | Yes           | No              |
| Cruiser     | 500-1000   | 15-30   | Yes           | Yes             |
| Destroyer   | 800-2000   | 50-80   | Yes           | No              |
| Carrier     | 1000-4000  | 120-250 | No            | Yes             |
| Dreadnought | 5000-20000 | 300-500 | Yes           | Yes             |

## Chapter III
### EX02

Третья версия клиента теперь должна не только распечатывать отфильтрованный список космических кораблей, но и 
сохранять их в базе данных `PostgreSQL`. Это нормально, если база данных и пользователь для `PostgreSQL` создаются вручную, 
если в присланном проекте есть описание в комментариях/текстовом файле.
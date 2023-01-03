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


async def fight():
    agent_value = Agent()
    async for action_list in agent_value:
        if action_list == Action.HIGHKICK:
            neo_value = Action.HIGHBLOCK
        if action_list == Action.HIGHBLOCK:
            neo_value = Action.LOWKICK
        if action_list == Action.LOWKICK:
            neo_value = Action.LOWBLOCK
        if action_list == Action.LOWBLOCK:
            neo_value = Action.HIGHKICK
        if action_list == Action.HIGHBLOCK or action_list == Action.LOWBLOCK:
            agent_value.health -= 1
        print(
            f'Agent: {action_list}, Neo: {neo_value}, Agent Health: {agent_value.health}')
        if agent_value.health == 0:
            break
    print('Neo wins!')


async def fight_2(agent_value, num, sem):
    async with sem:
        async for action_list in agent_value:
            if action_list == Action.HIGHKICK:
                neo_value = Action.HIGHBLOCK
            if action_list == Action.HIGHBLOCK:
                neo_value = Action.LOWKICK
            if action_list == Action.LOWKICK:
                neo_value = Action.LOWBLOCK
            if action_list == Action.LOWBLOCK:
                neo_value = Action.HIGHKICK
            if action_list == Action.HIGHBLOCK or action_list == Action.LOWBLOCK:
                agent_value.health -= 1
            print(
                f'Agent: {action_list}, Neo: {neo_value}, Agent Health: {agent_value.health}')
            if agent_value.health == 0:
                break
    print('Neo wins!')


async def fightmany(n):
    agent_list = [Agent() for _ in range(n)]
    sem_value = asyncio.Semaphore(n)
    task_list = list()
    for tmp_index, agent_value in enumerate(agent_list, 1):
        task_value = fight_2(agent_value, tmp_index, sem_value)
        task_list.append(task_value)
    await asyncio.gather(*task_list)


def main():
    asyncio.run(fight())
    asyncio.run(fightmany(int(input())))


if __name__ == '__main__':
    main()

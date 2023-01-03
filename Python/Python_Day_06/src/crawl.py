import warnings
import asyncio
import httpx


async def get_data_api(data_value):
    warnings.simplefilter(action='ignore', category=DeprecationWarning)
    url_value = f'http://127.0.0.1:8888/api/v1/tasks/{data_value}'
    for i in range(3):
        async with httpx.AsyncClient() as client_value:
            response_value = await client_value.get(url_value)
            response_value.raise_for_status()
    data_value = response_value.json()
    print(data_value)


task_list = list()
task_list.append(asyncio.ensure_future(get_data_api('Python')))
task_list.append(asyncio.ensure_future(get_data_api('Java')))
task_list.append(asyncio.ensure_future(get_data_api('Go')))

loop_value = asyncio.get_event_loop()
loop_value.run_until_complete(asyncio.gather(*task_list))
loop_value.close()

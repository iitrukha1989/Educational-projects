import httpx
import aioredis
import requests
import uvicorn
from fastapi import FastAPI
from bs4 import BeautifulSoup

api = FastAPI()

@api.get('/api/v1/tasks/{data_value}')
async def tasks(data_value: str):
    redis = aioredis.Redis.from_url(
        "redis://localhost", max_connections=10, decode_responses=True
    )
    url_value = f'https://ru.wikipedia.org/wiki/{data_value}'
    with httpx.Client() as client:
        soup_value = BeautifulSoup(client.get(url_value))
        response_value = requests.get(url_value)
    cache = await redis.get(data_value)
    if cache is not None:
        return {'web site': soup_value.title.string,
                'link': url_value,
                # 'UUID4': uuid.uuid4(),
                'status': response_value.status_code}
    await redis.set(soup_value.title.string,
                    url_value,
                    # uuid.uuid4(),
                    response_value.status_code)
    return {'web site': soup_value.title.string,
            'link': url_value,
            # 'UUID4': uuid.uuid4(),
            'status': response_value.status_code}


if __name__ == '__main__':
    uvicorn.run(api, host="127.0.0.1", port=8888)

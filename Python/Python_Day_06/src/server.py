import uuid
import httpx
import uvicorn
import requests
from fastapi import FastAPI
from bs4 import BeautifulSoup

api = FastAPI()


@api.get('/api/v1/tasks/{data_value}')
def tasks(data_value: str):
    url_value = f'https://ru.wikipedia.org/wiki/{data_value}'
    with httpx.Client() as client:
        soup_value = BeautifulSoup(client.get(url_value))
        response_value = requests.get(url_value)
    return {'web site': soup_value.title.string,
            'link': url_value,
            'UUID4': uuid.uuid4(),
            'status': response_value.status_code}


if __name__ == '__main__':
    uvicorn.run(api, host="127.0.0.1", port=8888)

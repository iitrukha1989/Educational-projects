from random import randint
import logging
import redis
import time
import json


def get_stream():
    logging.basicConfig(level=logging.DEBUG)
    logger = logging.getLogger('log data')
    red = redis.Redis(host='localhost', port=6379, db=0)
    while True:
        time.sleep(0.5)
        record_value = generator_json()
        logger.info(record_value)
        red.publish("user_producer", record_value)


def generator_json():
    from_value = ''.join([str(randint(0, 9)) for _ in range(10)])
    to_value = ''.join([str(randint(0, 9)) for _ in range(10)])
    dict_value = {'metadata': {'from': from_value,
                               'to': to_value},
                  'amount': randint(-10_000, 10_000)}
    return json.dumps(dict_value)


def main():
    get_stream()


if __name__ == "__main__":
    main()

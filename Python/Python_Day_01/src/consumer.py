import logging
import redis
import json
import sys


def set_stream(check_value_1, check_value_2):
    logging.basicConfig(level=logging.DEBUG)
    logger = logging.getLogger('output crime')
    red = redis.Redis(host='localhost', port=6379, db=0)
    while True:
        sub = red.pubsub(ignore_subscribe_messages=True)
        sub.subscribe('user_producer')
        for message in sub.listen():
            new_record = json.loads(message['data'])
            if new_record['metadata']['to'] in (
                    str(check_value_1), str(check_value_2)):
                if new_record['amount'] < 0:
                    logger.info(new_record)
                else:
                    logger.info(create_json(new_record))
            if new_record['metadata']['from'] in (
                    str(check_value_1), str(check_value_2)):
                logger.info(new_record)


def create_json(new_record):
    dict_value = {'metadata': {'from': new_record['metadata']['to'],
                               'to': new_record['metadata']['from']},
                  'amount': new_record['amount']}
    return json.dumps(dict_value)


def main(flag_check, check_value_1, check_value_2):
    if flag_check == '-e' and check_value_1[:-1].isdigit() \
            and check_value_2.isdigit() \
            and len(check_value_1[:-1]) == 10 \
            and len(check_value_2) == 10:
        set_stream(check_value_1, check_value_2)
    else:
        print('Incorrect input')


if __name__ == '__main__':
    try:
        main(sys.argv[1], sys.argv[2], sys.argv[3])
    except BaseException:
        print('Incorrect input')
        exit()

from wsgiref.simple_server import make_server
from urllib.parse import parse_qsl
import json


def application(environ, start_response):
    url_value = environ['QUERY_STRING']
    parsed_url = dict(parse_qsl(url_value))
    response_headers = [('Content-Type', 'application/json')]
    species_dict = {
        "Cyberman": "John Lumic",
        "Dalek": "Davros",
        "Judoon": "Shadow Proclamation Convention 15 Enforcer",
        "Human": "Leonardo da Vinci",
        "Ood": "Klineman Halpen",
        "Silence": "Tasha Lem",
        "Slitheen": "Coca-Cola salesman",
        "Sontaran": "General Staal",
        "Time Lord": "Rassilon",
        "Weeping Angel": "The Division Representative",
        "Zygon": "Broton"
    }
    if parsed_url['species'] in species_dict:
        status = '200 OK'
        res_dict = {'credentials': species_dict[parsed_url['species']]}
    else:
        status = '404 Not Found'
        res_dict = {'credentials': 'Unknown'}
    json_file = json.dumps(res_dict)
    res_json = json_file.encode('utf-8')
    start_response(status, response_headers)
    return [res_json]


def main():
    try:
        httpd = make_server('localhost', 8888, application)
        httpd.serve_forever()
        httpd.handle_request()
    except KeyboardInterrupt:
        print('Good buy!')


if __name__ == '__main__':
    main()

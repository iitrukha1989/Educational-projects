from bs4 import BeautifulSoup
import wikipedia
import argparse
import requests
import logging
import json

WIKI_FILE = 'wiki.json'


def find_wiki_page(name_search):
    return wikipedia.page(name_search).url


def create_soup(url_value):
    logging.basicConfig(level=logging.INFO)
    logger = logging.getLogger('log data')
    req_value = requests.get(url_value)
    soup_value = BeautifulSoup(req_value.content, 'html.parser')
    logger.info(soup_value.title.string)
    return soup_value


def parse_page(
        name_page,
        link_page,
        depth_research,
        set_value,
        data_dict,
        page_limit=[1000],
        id=[1]):
    depth_research -= 1
    if page_limit[0] >= 0 and depth_research >= 0:
        try:
            soup_value = create_soup(link_page)
            link_list = soup_value.find(
                id='bodyContent').find_all('a', href=True)
            prev_name = name_page
            prev_id = id[0]
            for link_value in link_list:
                name_page = link_value.get('title')
                link_page = link_value.get('href')
                if link_value['href'].find("/wiki/", 0, 6) == -1:
                    continue
                if name_page is None:
                    continue
                if name_page not in set_value:
                    set_value.add(name_page)
                    data_dict['nodes'].append(
                        {'page_name': name_page,
                         'link_page': 'https://en.wikipedia.org' + link_page,
                         'id': id[0]})
                    id[0] += 1
                    data_dict['edges'].append(
                        {'source': prev_name, 'target': name_page,
                         'source_id': prev_id, 'target_id': id[0]})
                    parse_page(
                        name_page,
                        'https://en.wikipedia.org' + link_page,
                        depth_research,
                        set_value,
                        data_dict,
                        page_limit,
                        id)
                    page_limit[0] -= 1
        except BaseException:
            pass


def create_json(data_dict):
    with open('wiki.json', 'w', encoding='utf-8') as json_file:
        json.dump(data_dict, json_file, ensure_ascii=False, indent=4)


def main():
    parser = argparse.ArgumentParser(description="Parser web page Wikipedia")
    parser.add_argument('-p', type=str, default='Erdős number',
                        help='defaul name in wikipedia')
    parser.add_argument('-d', type=int, default=3,
                        help='the value of the link depth')
    args = parser.parse_args()
    url_value = find_wiki_page(str(args.p))
    data_dict = {'nodes': list(), 'edges': list()}
    set_value = set()
    parse_page(args.p, url_value, args.d, set_value, data_dict)
    create_json(data_dict)


if __name__ == '__main__':
    main()

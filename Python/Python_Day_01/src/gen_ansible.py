import yaml


def read_yaml(name_file):
    with open(name_file) as yaml_value:
        data_value = yaml.load(yaml_value, Loader=yaml.FullLoader)
    return data_value


def create_yaml(data_value):
    yaml_dict = dict()
    yaml_dict['server'] = data_value['server']
    yaml_dict.setdefault('bad_guys', str(
        [int(tmp_value) for tmp_value in data_value['bad_guys']]))
    yaml_dict['hosts'] = 'all'
    yaml_dict['task'] = [
        {'name': 'Install python3',
         'apt': {'pkg': 'python3', 'state': 'latest'}},
        {'name': 'Install nginx',
         'apt': {'pkg': 'nginx', 'state': 'latest'}},
        {'name': 'Copy exploit.py',
         'copy': {
             'SourceFolder': 'fake_path/exploit.py',
             'TargetFolder': 'fake_path/exploit.py'}},
        {'name': 'Copy consumer.py',
         'copy': {
             'SourceFolder': 'fake_path/consumer.py',
             'TargetFolder': 'fake_path/consumer.py'}},
        {'name': 'Run exploit.py', 'command': 'python3 exploit.py'},
        {'name': 'Run consumer.py',
         'command':
         f'python3 consumer.py -e {", ".join(data_value["bad_guys"])}'}]
    return yaml_dict


def write_yaml(yaml_dict):
    with open('deploy.yml', 'w') as file_value:
        yaml.dump(yaml_dict, file_value, sort_keys=False, indent=4)


def main():
    write_yaml(create_yaml(read_yaml(name_file='todo.yml')))


if __name__ == '__main__':
    main()

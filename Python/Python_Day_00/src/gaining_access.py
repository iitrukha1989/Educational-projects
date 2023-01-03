class Key:

    def __init__(self):
        self.passphrase = 'zax2rulez'

    def __len__(self):
        return 1337

    def __getitem__(self, key):
        if isinstance(key, int) and key == 404:
            return 3
        elif not isinstance(key, int):
            raise TypeError
        else:
            raise KeyError

    def __str__(self):
        return 'GeneralTsoKeycard'

    def __gt__(self, tmp_value):
        return 9001 > tmp_value


if __name__ == '__main__':
    k_value = Key()
    assert len(k_value) == 1337
    assert k_value[404] == 3
    assert k_value > 9000
    assert k_value.passphrase == "zax2rulez"
    assert str(k_value) == "GeneralTsoKeycard"

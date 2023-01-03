from random import randint
import time


def emit_gel(step):
    if step in range(0, 100):
        tmp_value = randint(0, 100)
        while True:
            tmp_value += randint(min(0, step), max(0, step))
            from_send = yield tmp_value
            if from_send is not None:
                step *= -1
                print('sign change')
            time.sleep(0.2)
    else:
        print('incorrect input')


def valve(step=0):
    gen_value = emit_gel(step)
    for tmp_value in gen_value:
        if tmp_value < 20 or tmp_value > 80:
            gen_value.send(True)
        if tmp_value < 10 or tmp_value > 90:
            gen_value.close()
        print(tmp_value)


def main():
    print('------ test_case_1 -------')
    valve(10)
    print('------ test_case_2 -------')
    valve(25)
    print('------ test_case_3 -------')
    valve(45)
    print('------ test_case_4 -------')
    valve(80)


if __name__ == '__main__':
    main()

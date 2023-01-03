import threading
import warnings
import time
import sys


class Semaphore():
    def __init__(self, initial):
        self.lock = threading.Condition(threading.Lock())
        self.value = initial

    def up(self):
        with self.lock:
            self.value += 1
            self.lock.notify()

    def down(self):
        with self.lock:
            while self.value == 0:
                self.lock.wait()
            self.value -= 1


class Screwdriver():
    def __init__(self, number):
        self.number = number
        self.user = -1
        self.lock = threading.Condition(threading.Lock())
        self.taken = False

    def take(self, user):
        with self.lock:
            while self.taken:
                self.lock.wait()
            self.user = user
            self.taken = True
            self.lock.notifyAll()

    def drop(self):
        with self.lock:
            while self.taken == False:
                self.lock.wait()
            self.user = -1
            self.taken = False
            self.lock.notifyAll()


class Doctor (threading.Thread):
    def __init__(self, number, left, right, butler):
        threading.Thread.__init__(self)
        self.number = number
        self.left = left
        self.right = right
        self.butler = butler

    def run(self):
        for i in range(1):
            time.sleep(1)
            self.butler.down()
            time.sleep(1)
            self.left.take(self.number)
            time.sleep(1)
            self.right.take(self.number)
            time.sleep(1)
            sys.stdout.write("DOCTOR: %s BLAST!\n" % (self.number))
            self.right.drop()
            time.sleep(1)
            self.left.drop()
            time.sleep(1)
            self.butler.up()
            time.sleep(1)


def blast():
    warnings.simplefilter(action='ignore', category=DeprecationWarning)
    butler = Semaphore(4)
    scw_value = [Screwdriver(index_value) for index_value in range(5)]
    doc_value = [Doctor(index_value + 9,
                        scw_value[index_value],
                        scw_value[(index_value + 1) % 5],
                        butler) for index_value in range(5)]
    for index_value in range(5):
        doc_value[index_value].start()


def main():
    blast()


if __name__ == '__main__':
    main()

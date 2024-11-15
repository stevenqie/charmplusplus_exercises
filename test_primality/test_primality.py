from charm4py import charm, Chare, Group
import sys
import random

def isPrime(number):
    if number <= 1:
        return False
    for i in range(2, number):
        if number % i == 0:
            return False
    return True 


class CheckPrimality(Chare):
    def __init__(self, number, mainProxy):
        result = isPrime(number)
        mainProxy.receiveResult(number, result)

class Main(Chare):
    def __init__(self, args):
        if len(args) < 2:
            print("K was not specified")
            charm.exit()
        self.k = int(args[1])
        self.numbersrecevied = 0
        self.primeMap = {}
        for i in range(self.k):
            randnum = random.randint(1, 100000000)
            self.primeMap[randnum] = False
            primecheck = Chare(CheckPrimality, args=[randnum, self.thisProxy])
    def receiveResult(self, number, isPrime):
        self.primeMap[number] = isPrime
        self.numbersrecevied += 1
        if self.numbersrecevied == self.k:
            for key, value in self.primeMap.items():
                print("Number: ", key, " is prime: ", value)
            charm.exit()


def main(args):
    a_proxy = Chare(Main, args=[args])

charm.start(main)
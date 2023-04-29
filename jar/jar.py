class Jar:
    def __init__(self, capacity=12):
        if capacity < 0:
            raise ValueError
        self.capacity = capacity
        self.number = 0


    def __str__(self):
        return "🍪" * self.number

    def deposit(self, n):
        if self.number + n > self.capacity or n > self.capacity:
            raise ValueError
        self.number += n

    def withdraw(self, n):
        if self.number - n < 0:
            raise ValueError
        self.number -= n

    # @property
    # def capacity(self):
    #     ...

    # @property
    # def size(self):
    #     ...

def main():
    jar = Jar(100)
    # Jar.deposit(3)
    print(jar)


main()
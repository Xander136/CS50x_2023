class Jar:
    def __init__(self, capacity=12):
        if capacity < 0:
            raise ValueError
        self.capacity = capacity
        self.size = 0


    def __str__(self):
        return "🍪" * self.size

    def deposit(self, n):
        if self.size + n > self.capacity or n > self.capacity:
            raise ValueError
        self.size += n

    def withdraw(self, n):
        if self.size - n < 0:
            raise ValueError
        self.size -= n

    @property
    def capacity(self):
        return self.capacity

    @property
    def size(self):
        return self.size

def main():
    jar = Jar(5)
    jar.deposit(3)
    # jar.withdraw(4)
    print(jar.size)


main()
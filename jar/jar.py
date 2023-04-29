class Jar:
    def __init__(self, capacity=12):
        while True:
            try:
                capacity.isdigit
                self.capacity = capacity
            except ValueError:



    def __str__(self):
        ...

    def deposit(self, n):
        ...

    def withdraw(self, n):
        ...

    @property
    def capacity(self):
        ...

    @property
    def size(self):
        ...
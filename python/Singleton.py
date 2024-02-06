class FooMeta(type):
    
    _instances = {}
    
    def __call__(cls, *args, **kwargs):

        if cls not in cls._instances:
            instance = super().__call__(*args, **kwargs)
            cls._instances[cls] = instance
        return cls._instances[cls]


class Foo(metaclass=FooMeta):
    def some_func_here(self):
        return 42


if __name__ == "__main__":

    foo1 = Foo()
    foo2 = Foo()

    if id(foo1) == id(foo2):
        print("Both variables refer to the same object")
    else:
        print("Both variables refer to different objects")
from abc import ABC, abstractmethod

class Iperson:
    """
        Person Inteface, Abstract Class
    """
    @abstractmethod
    def speak(): pass
    
    def personType(self):
        print(type(self))


class Student(Iperson):
    """
        concrete class, inherits from Iperson
    """
    def __init__(self, name):
        self.name = name
    
    def speak(self):
        print("I'm a Student")
    
    
class Teacher(Iperson):
    
    """
        concrete class, inherits from Iperson

    """
    
    def __init__(self, title):
        self.title = title
    
    def speak(self):
        print("I'm a Teacher")


class PersonFactory:
    
    @classmethod
    def create(cls,arg):
        """ 
            Decides what type of object to create at runtime, based off the user input

        """
        if 'Mr.' in arg or 'Mrs.' in arg:
            return Teacher(arg)
        else:
            return Student(arg)

if __name__ == '__main__':
    usr_input = input("->")
    obj = PersonFactory.create(usr_input)
    
    obj.speak()
    obj.personType()
        

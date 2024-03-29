# Design Patterns

## Patterns Covered

    - Singleton
    - Factory

### Singleton

The Singleton design pattern is used when wanting to control access to some common resource.  

- Is a Creational Design Pattern[^1]
- Only one instance to a class is in existence at any given time.
- If a new instance is attempted to be created, while an instance of the class already exists, then the new instance will not be created, but the new variable will just point to the old instnace instead.

[^1]: Creational Design Patterns provide a variety of creation mechanisms to increase flexibility and reuse existing code.

### Factory Pattern

Imported modules: ABC, abstractmethod

1. Create an abstract class (interface)
2. create concrete classes. The class that inherit fromm the abstract class and defines the methods.
3. Create a factory. Where the decision is made on which concrete class to create based on arguments passed in

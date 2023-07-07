# Expression Tree

## Base Class

- Supports and simplifies iteration of nodes

```c++
    class Base {
        public:
            virtual ~Base() = default;

            /* Pure Virtual Functions */
            virtual double evaluate() = 0; 
            virtual std::string stringify() = 0;
            virtual int number_of_children() = 0; // returns the number of node's children 
            virtual Base* get_child(int i) = 0;
    };
```

## Iterator Class

- Used to traverse expression tree, visitng nodes multiple times.
- Limiting node visits determined on the quantity of children nodes.
  - Nodes with no children, visited once.
  - Nodes with one child, visited twice.
  - Nodes with two children, visited three times.

```c++
    class Iterator {
        public:

            void next(); // advances iterator to the next node

            bool is_done(); // If true, then iteration has finished and no other function calls allowed.

            Base* current_node(); // returns a pointer to the current node being visited.

            int current_index(); // number of times visited.
    }
```

### Base Iterator

```c++

    struct base_iterator
    {
        base_iterator(Base* ptr);
        Base* ptr;
        int index;
        int number_children;
    };

```

## Visitor Class

- Base class, Interface for visiting the expression tree.
- Used to print out the expression tree in two different ways.

```c++

    class Visitor{
        public:
            virtual ~Visitor() = default;

            virtual void visit_op(Op* node) = 0;
            virtual void visit_rand(Rand* node) = 0;
            
            // addition (+)
            virtual void visit_add_begin(Add* node) = 0;
            virtual void visit_add_middle(Add* node) = 0;
            virtual void visit_add_end(Add* node) = 0;

            // subtraction (-)
            virtual void visit_sub_begin(Sub* node) = 0;
            virtual void visit_sub_middle(Sub* node) = 0;
            virtual void visit_sub_end(Sub* node) = 0;

            // multiplication (*)
            virtual void visit_mult_begin(Mult* node) = 0;
            virtual void visit_mult_middle(Mult* node) = 0;
            virtual void visit_mult_end(Mult* node) = 0;

            // Division (/)
            virtual void visit_div_begin(Div* node) = 0;
            virtual void visit_div_middle(Div* node) = 0;
            virtual void visit_div_end(Div* node) = 0;
            // Exponent (^)
            virtual void visit_pow_begin(Pow* node) = 0;
            virtual void visit_pow_middle(Pow* node) = 0;
            virtual void visit_pow_end(Pow* node) = 0;
            
    };
```

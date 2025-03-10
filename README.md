
# Secured - Hash Table Project

## Description

The **Secured** project focuses on implementing a library in C to manage hash tables. The aim is to efficiently secure and store information using fundamental C programming concepts such as structures, function pointers, and dynamic memory management.

## Features

The **libhashtable.a** library offers the following functionalities:
- **Create Hash Tables**: Initialize and free customizable hash tables.
- **Insert**: Dynamically manage keys and values in the hash table.
- **Search in the Table**: Quickly access values associated with a given key.
- **Handle Collisions**: Use separate chaining to resolve collisions.
- **Display Table State**: Visualize the contents of the hash table.

## Installation

To compile and use the library, follow the steps below.

### Directory Structure

```
/include/
  ├── hashtable.h        # Declarations for structures and function prototypes
/src/
  ├── file.c        # Utility functions (memory management, display, etc.)
  ├── hash_func.c    # Implementation of the hash function
  └── hash_table.c            # Implementation of the hashtable
Makefile                 # Makefile for compilation
README.md                # This file
```

### Compilation

1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/secured.git
   ```

2. Compile the library:
   ```bash
   make
   ```

3. Clean intermediate files:
   ```bash
   make clean
   ```

## Usage

The library compiles into **libhashtable.a**. You can use it in your own projects by including `hashtable.h` and linking the library.

### Example Usage

Below is a simple example to create a hash table, insert elements, and perform searches:

```c
#include "hashtable.h"

int main(void) {
    hashtable_t *ht = new_hashtable(&hash, 5);  // Create a table of size 5

    ht_insert(ht, "Vision", "./Documents/Vision");
    ht_insert(ht, "Kratos", "./Trash/Kratos.ai");
    ht_dump(ht);  // Display the current table state

    char *value = ht_search(ht, "Kratos");
    if (value)
        printf("Found value: %s\n", value);

    ht_delete(ht, "Vision");
    ht_dump(ht);

    delete_hashtable(ht);  // Free allocated memory
    return 0;
}
```
You can find a premade main file in message.txt and the GCC command to compile it and use it with the library in command_gcc.txt.

### Expected Output

```plaintext
[0]:
[1]: > 1769199557 - ./Documents/Vision
[2]: > 1952572858 - ./Trash/Kratos.ai
[3]:
[4]:

Found value: ./Trash/Kratos.ai

[0]:
[1]:
[2]: > 1952572858 - ./Trash/Kratos.ai
[3]:
[4]:
```

## Contributors

This project was developed in duo as part of the **Elementary Programming in C** module at Epitech.

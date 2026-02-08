This project is a **simple stack-based memory allocator** written in C, inspired by  
*The C Programming Language* by **Brian Kernighan and Dennis Ritchie**, Chapter 5 (Pointers and Arrays).

The goal of this project is **not** to replace `malloc`, but to deeply understand:
- pointer arithmetic
- memory layout
- how dynamic memory allocation actually works internally
- how real C projects are structured and built

---

##  What This Project Is
This allocator provides two functions:

char *alloc(size_t n);
void afree(char *p);

alloc(n) --> Returns a pointer to n consecutive bytes from a private memory buffer.
afree(p) --> Frees memory only in reverse order of allocation (LIFO).

Internally, the allocator:
- owns a fixed-size static memory buffer
- tracks the next free byte using a pointer
- uses pointer arithmetic instead of array indices
This makes it a stack allocator, not a general-purpose heap allocator.


## Limitations (By Design)
This allocator is intentionally simple:
- Memory must be freed in last-in, first-out order
- No metadata is stored per allocation
- No protection against double-free or overflow
- Not thread-safe
These limitations exist so the core ideas are visible, not hidden behind complexity.



## What I Learned From This Project
## C & Memory Concepts
- Pointer arithmetic (p + n, pointer subtraction)
- Why char * is used for raw memory
- Why size_t is the correct type for sizes
- Difference between memory start, current position, and end
- Why allocators need strict boundaries (ALLOCSIZE)
  
## Modular C Design
- Writing header files as interfaces/contracts
- Keeping implementation details private using static
- Why headers should not contain definitions
- How .c and .h files work together
  
## Build System & Tooling
- Difference between compilation and linking
- What object files (.o) are
- Why linking fails when object paths don’t match
- How gcc behaves with and without -o
- How Make decides what needs rebuilding

## How the Allocator Works (High Level)
- allocbuf --> A static character array that represents all memory owned by the allocator
- allocp --> A pointer that always points to the next free byte
- Allocation: Check if enough space remains
              Return the current allocp
              Move allocp forward by n
- Freeing: Move allocp backward to a previously returned pointer

## Building & Running the Project
1. Requirements
- GCC or Clang
- Make
- Unix-like environment (Linux / macOS)
2. Build
From the project root: 'make'
Run: './allocator_test1'
Clean build artifacts : 'make clean'

## About the Makefile
The Makefile automates the C build process by:
- Compiling .c files into .o object files
- Tracking dependencies on header files
- Linking object files into a final executable
- Avoiding unnecessary recompilation
  
Key ideas used:
- Variables (CC, CFLAGS, OBJ)
- Separate compile and link steps
- Explicit output paths using -o
- Dependency tracking (.o : .c .h)
- A clean target to reset the build
This mirrors how real-world C projects are built.

## Why This Project Exists
This project exists to answer one question:
“What is malloc really doing under the hood?”

By implementing a minimal allocator using only:
- arrays
- pointers
- arithmetic
- discipline
  
the abstraction of dynamic memory becomes concrete and understandable.

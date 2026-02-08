CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -Iinclude

OBJ = src/allocator.o tests/allocator_test1.o

allocator_test1 : $(OBJ)
	@echo "Linking and producing the final executable"
	$(CC) $(CFLAGS) $(OBJ) -o allocator_test1


src/allocator.o : src/allocator.c include/allocator.h
	@echo "Compiling the src file"
	$(CC) $(CFLAGS) -c src/allocator.c -o src/allocator.o

tests/allocator_test1.o : tests/allocator_test1.c include/allocator.h
	@echo "Compiling the test file"
	$(CC) $(CFLAGS) -c tests/allocator_test1.c -o tests/allocator_test1.o


clean:
	rm -f $(OBJ) allocator_test1

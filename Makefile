# Compiler
CC = cc -g

# Compiler flags
CFLAGS = -I include -fPIC

# Directories
SRCDIR = srcs
UTILDIR = utils
INCDIR = include
LIBDIR = printf

# Source files
SRC = $(wildcard $(SRCDIR)/*.c) $(wildcard $(UTILDIR)/*.c) main.c

# Object files
OBJ = $(SRC:.c=.o)

# Library source files
LIBSRC = $(wildcard $(LIBDIR)/*.c)

# Library object files
LIBOBJ = $(LIBSRC:.c=.o)

# Library file
LIB = $(LIBDIR)/libprintf.a

# Output executable
TARGET = push_swap

# Linker flags
LDFLAGS = $(LIB)

# Rules
all: $(TARGET)

$(TARGET): $(OBJ) $(LIB)
	$(CC) $(OBJ) $(LDFLAGS) -o $@

$(LIB): $(LIBOBJ)
	ar rcs $@ $^

$(LIBDIR)/%.o: $(LIBDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET) $(LIBOBJ)

fclean: clean
	rm -f $(LIB)

re: fclean all

.PHONY: all clean fclean re


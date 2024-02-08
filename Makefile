CC = g++-13
CFLAGS = -Wall -Wextra -g
OUTPUT = test
OBJECTS = GetInput.o Plot.o main.o


all: $(OUTPUT)

$(OUTPUT): $(OBJECTS)
		$(CC) -o $@ $^

%.o: %.c
		$(CC) $(CFLAGS) -c -o $@ $^

clean:
		rm -rf *.o $(OUTPUT)

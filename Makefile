CC = g++-13
CFLAGS = -Wall -Wextra -g
OUTPUT = Model
OBJECTS = main.o GetInput.o Plot.o


all: $(OUTPUT)

$(OUTPUT): $(OBJECTS)
		$(CC) -o $@ $^

%.o: %.c
		$(CC) $(CFLAGS) -c -o $@ $^

clean:
		rm -rf *.o $(OUTPUT)

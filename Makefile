CFLAGS=-O0 -std=c11 -march=native -ggdb -pipe -Wall -Wextra -Wshadow

sort: sort.o
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

clean:
	rm -f *.o
	rm -f sort

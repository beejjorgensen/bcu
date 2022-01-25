demolib.o: demolib.c
	gcc -Wall -Wextra -c $<

.PHONY: test clean

test_demolib: demolib.c
	gcc -Wall -Wextra -o $@ $< -DBCU_TEST_ENABLED

test: test_demolib
	./test_demolib

clean:
	rm -f test_demolib demolib.o
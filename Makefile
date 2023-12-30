dev: dev_test.c linked_list.c
	gcc -Wall -Werror $^ -o dev_test

test: linked_list_test.c linked_list.c
	gcc -Wall -Werror $^ -o test
	./test
	rm -f test
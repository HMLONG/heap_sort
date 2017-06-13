heapsort : heap_sort.o
	gcc -o heap_sort heap_sort.o
heapsort.o : heap_sort.c
	gcc -c heap_sort.c
clean :
	rm heap_sort heap_sort.o

project: project.o linked_list.o
	gcc project.o linked_list.o -o project
linked_list.o: linked_list.c linked_list.h
	gcc -c linked_list.c
project.o: project.c
	gcc -c project.c
 Missing newline at the end of file.

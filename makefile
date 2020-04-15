.PHONY: all

all: task1 task2 task3 task2.1 task2.2 task2.3 task2.4 lib

task1: hello_Ariel.c hello_Ariel.h main1_1.c
	gcc -o hello1 hello_Ariel.c main1_1.c

task2: hello_Ariel.h main1_1.c lib
	gcc main1_1.c -L. -l Hello -o hello2

task3: hello_Ariel.h main1_3.c lib
	gcc main1_3.c -fPIC -ldl -o hello3

task2.1: main2_1.c
	gcc main2_1.c -o forkExample

task2.2: main2_2.c
	gcc main2_2.c -o cloneExample

task2.3: main2_3.c
	gcc main2_3.c -o deamonExample

task2.4: main2_1.c main2_2.c main2_3.c main2_4.c
	gcc main2_4.c -o main4

lib: hello_Ariel.h hello_Ariel.c
	gcc -shared hello_Ariel.c -fPIC -o libHello.so

.PHONY: clean
clean:
	-rm hello1 hello2 hello3 libHello.so 2>/dev/null

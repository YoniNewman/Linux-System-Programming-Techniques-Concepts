TARGET:exe
student.o: student.c
	gcc -c student.c -o student.o
diff.o: diff.c
	gcc -c diff.c -o diff.o
dll.o: dll.c
	gcc -c dll.c -o dll.o
dll_util.o: dll_util.c
	gcc -c dll_util.c -o dll_util.o
libdll.a: dll.o dll_util.o
	ar rs libdll.a dll.o dll_util.o
application.o: application.c
	gcc -c application.c -o application.o 
exe: application.o student.o diff.o libdll.a
	gcc application.o student.o diff.o -o exe -L . libdll.a -lm 
clean:
	rm dll.o
	rm dll_util.o
	rm application.o
	rm libdll.a
	rm student.o
	rm diff.o
	rm exe
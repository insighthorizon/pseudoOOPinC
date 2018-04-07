# pseudoOOP test with templateObj.c/.h makefile

test:
	make build;
	make run;
build:
#compiling into .o files
	gcc main.c -o main.o -c;
	gcc object.c -o object.o -c;
#linking into ELF binary
	gcc main.o object.o -o pseudoObjTest;

run:
	./pseudoObjTest;

clean:
	-rm pseudoObjTest;
	-rm main.o;
	-rm object.o;

# pseudoOOP test with templateObj.c/.h makefile

test:
	make build;
	make run;
build:
#compiling into .o files
	gcc main.c -o main.o -c;
	gcc templateObj.c -o templateObj.o -c;
#linking into ELF binary
	gcc main.o templateObj.o -o pseudoObjTest;

run:
	./pseudoObjTest;

clean:
	-rm pseudoObjTest;
	-rm main.o;
	-rm templateObj.o;

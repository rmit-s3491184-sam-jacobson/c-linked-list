SOURCES=addressbook.c addressbook_list.c commands.c helpers.c
HEADERS=addressbook.h addressbook_list.h commands.h helpers.h
OBJECTS=addressbook.o addressbook_list.o commands.o helpers.o
PROGRAM=addressbook
FLAGS=-ansi -pedantic -Wall

all: $(PROGRAM)

$(PROGRAM): $(OBJECTS)
	gcc $(FLAGS) -o $(PROGRAM) $(OBJECTS)
	
addressbook.o: addressbook.c *.h
	gcc $(FLAGS) -c addressbook.c
	
addressbook_list.o: addressbook_list.c *.h
	gcc $(FLAGS) -c addressbook_list.c
	
helpers.o: helpers.c *.h
	gcc $(FLAGS) -c helpers.c
	
commands.o: commands.c *.h
	gcc $(FLAGS) -c commands.c
	
clean:
	rm $(PROGRAM)
	
archive:
	zip $(USER)-a2 $(SOURCES) $(HEADERS) Makefile
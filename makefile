COURSE = cs240
SEMESTER = spring2023
CP_NUMBER = 1
LASTNAME = Park
GITUSERID = jpark430
EXE = bst
#  valgrind --leak-check=full --show-leak-kinds=all


REPODIR = ../$(COURSE)-$(SEMESTER)-cp$(CP_NUMBER)-$(GITUSERID)
TARFILE = CP$(CP_NUMBER)_$(LASTNAME)_$(USER)_$(GITUSERID).tar

FLAGS = -Wall -Wextra -g
# FLAGS = -Wall -O3
CC = g++
BIN = bin
OBJ = obj

# Specifiy the target
all:BST

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
BST: BST.o
	g++ $(FLAGS) BST.o

# Specify how the object files should be created from source files
BST.o: BST.cpp
	g++ $(FLAGoS) -c BST.cpp

tar:	clean
	tar cvvf $(TARFILE) $(REPODIR)
	gzip $(TARFILE)

clean:
	rm -f  *.o  scheduler *.tar.gz
	
run:
	./scheduler

COURSE = cs240
SEMESTER = spring2023
CP_NUMBER = 4
LASTNAME = Park
GITUSERID = sirunde
EXE = test

REPODIR = ../$(COURSE)-$(SEMESTER)-cp$(CP_NUMBER)-$(GITUSERID)
TARFILE = CP$(CP_NUMBER)_$(LASTNAME)_$(USER)_$(GITUSERID).tar

# FLAGS = -Wall -Wextra -g
FLAGS = -Wall -Wextra -g -O3
CC = g++
BIN = bin
OBJ = obj
TESTS = $(BIN)/test

all: $(BIN)/$(EXE) $(TESTS)

# ------------------------------------------------------------------------
# Builds the .o
$(OBJ)/BST.o: BST.cpp
	$(CC) $(FLAGS) -c BST.cpp -o $@

# ------------------------------------------------------------------------
# Builds the .o
$(OBJ)/main.o: main.cpp
	$(CC) $(FLAGS) -c main.cpp -o $@

# ------------------------------------------------------------------------
# excutable
$(BIN)/$(EXE): $(OBJ)/main.o $(OBJ)/BST.o
	$(CC) $(FLAGS) $(OBJ)/main.o $(OBJ)/BST.o \
		-o $@ 

tar:	clean
	tar cvvf $(TARFILE) $(REPODIR)
	gzip $(TARFILE)

clean:
	rm -f $(OBJ)/*.o $(BIN)/$(EXE) $(TESTS) *.tar.gz
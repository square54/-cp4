COURSE = cs240
SEMESTER = spring2023
CP_NUMBER = 1
LASTNAME = Thomas
GITUSERID = square54
EXE = scheduler

REPODIR = ../$(COURSE)-$(SEMESTER)-cp$(CP_NUMBER)-$(GITUSERID)
TARFILE = CP$(CP_NUMBER)_$(LASTNAME)_$(USER)_$(GITUSERID).tar

FLAGS = -Wall -Wextra -g
# FLAGS = -Wall -O3
CC = g++
BIN = bin
OBJ = obj

# Specifiy the target
all:scheduler

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
scheduler: scheduler.o Student.o StudentList.o Course.o CourseList.o CourseInfo.o
	g++ $(FLAGS) scheduler.o Student.o StudentList.o Course.o CourseList.o CourseInfo.o -o scheduler

# Specify how the object files should be created from source files
scheduler.o: scheduler.cpp Student.cpp StudentList.cpp Course.cpp CourseList.cpp CourseInfo.cpp
	g++ $(FLAGS) -c scheduler.cpp

student.o: scheduler.cpp Student.cpp StudentList.cpp Course.cpp CourseList.cpp CourseInfo.cpp
	g++ $(FLAGS) -c Student.cpp 

studentList.o: scheduler.cpp Student.cpp StudentList.cpp Course.cpp CourseList.cpp CourseInfo.cpp
	g++ $(FLAGS) -c StudentList.cpp 

course.o: scheduler.cpp Student.cpp StudentList.cpp Course.cpp CourseList.cpp CourseInfo.cpp
	g++ $(FLAGS) -c Course.cpp 

courseList.o: scheduler.cpp Student.cpp StudentList.cpp Course.cpp CourseList.cpp CourseInfo.cpp
	g++ $(FLAGS) -c CourseList.cpp 

courseInfo.o: scheduler.cpp Student.cpp StudentList.cpp Course.cpp CourseList.cpp CourseInfo.cpp
	g++ $(FLAGS) -c CourseInfo.cpp

tar:	clean
	tar cvvf $(TARFILE) $(REPODIR)
	gzip $(TARFILE)

clean:
	rm -f  *.o  scheduler *.tar.gz
	
run:
	./scheduler

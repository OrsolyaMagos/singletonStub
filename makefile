# before executing test, you have to specify
# CXXTEST_PATH environment variable
# example: export CXXTEST_PATH=/home/magos/work/unittest/cxxtest

CC=g++
SRC=Singleton.cpp
OBJ=$(SRC:.cpp=.o)
TST_FILE=gentests.cpp
CXXTEST_GEN=$(CXXTEST_PATH)/bin/cxxtestgen

CCFLAGS = -g -Wall
INCLUDES = -I. -I$(CXXTEST_PATH)
LIBS=-L. -lSingleton


obj: $(SRC)
	$(CC) -fpic -c $(SRC)

all: obj
	$(CC) -shared -o libSingleton.so $(OBJ)
#	g++ -o singleton Singleton.cpp tests.cpp -I../cxxtest


buildtest: all
	$(CXXTEST_GEN) --error-printer -o gentests.cpp singletonTest.hpp
	$(CC) $(TST_FILE) $(INCLUDES) $(CXXFLAGS) -o singletonTest $(LIBS)

test: buildtest
	export LD_LIBRARY_PATH=. && ./singletonTest

check: buildtest
	export LD_LIBRARY_PATH=. && valgrind --verbose ./singletonTest

clean:
	rm -rf *.o *.so singletonTest $(TST_FILE)




#example from http://stevemorin.blogspot.hu/2005/10/create-shared-library-with-g.html
#1) g++ -fpic -c CLib.cpp
#2) g++ -shared -o libCLib.so CLib.o
#3) g++ CLibTest.cpp -o CLibTest -L. -lCLib



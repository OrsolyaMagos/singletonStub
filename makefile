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


buildtest: all
	$(CXXTEST_GEN) --error-printer -o gentests.cpp singletonTest.hpp
	$(CC) $(TST_FILE) $(INCLUDES) $(CXXFLAGS) -o singletonTest $(LIBS)

test: buildtest
	export LD_LIBRARY_PATH=. && ./singletonTest

check: buildtest
	export LD_LIBRARY_PATH=. && valgrind --verbose ./singletonTest

clean:
	rm -rf *.o *.so singletonTest $(TST_FILE)



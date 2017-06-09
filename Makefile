# Builds the RSA_OBJECT project.

src=src
objects=MAIN_RSA_OBJECT.o
testobjects=test.o

cc=g++
cflags=-std=c++11 -Wall

testcflags=$(cflags) -I$(src)

MAIN_RSA_OBJECT: $(objects)
	$(cc) -o $@ $^ $(cflags)

%.o: $(src)/%.cpp
	$(cc) -c -o $@ $^ $(cflags)

.PHONY: clean
clean:
	rm -rf *.o core MAIN_RSA_TEST

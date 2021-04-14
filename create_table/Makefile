CC=g++
CFLAGS=-c -Wall -g

LIBS =  -L/usr/local/lib -laws-cpp-sdk-core
LIBS += -L/usr/local/lib -laws-cpp-sdk-dynamodb
LIBS += -L/usr/local/lib -laws-cpp-sdk-dynamodbstreams
LIBS += -L/usr/lib/x86_64-linux-gnu -lcurl

SOURCES = create_table.cpp

OBJECTS = $(SOURCES:.cpp=.o)

all: create_table

create_table: create_table.o
	$(CC) create_table.o -o create_table $(LIBS)
create_table.o: create_table.cpp
	$(CC) $(CFLAGS) create_table.cpp

clean:
	rm -f *.o create_table

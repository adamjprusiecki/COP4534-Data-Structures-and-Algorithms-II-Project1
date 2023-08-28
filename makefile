CC = g++
DEBUG = -g
CFLAGS = $(DEBUG) -c -Wall -std=c++11
LDLIBS =

TARGET = run

SOURCES = \
CreateFiles.cpp \
UserNode.cpp \
SinglyLinkedList.cpp \
HashTable.cpp \
Driver.cpp \
main.cpp 

OBJECTS = $(SOURCES:.cpp=.o)

$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS) $(LDLIBS)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@ 

.PHONY : all $(TARGET)

clean: 
	rm -f $(OBJECTS)
	rm -f raw.txt
	rm -f encrypted.txt
	rm -f run

clobber: clean
	rm -f $(TARGET) 

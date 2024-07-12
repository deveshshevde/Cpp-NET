CXX := g++
CXXFLAGS := -std=c++20 -Wall
INCDIR := /Users/deveshshevde/Desktop/Network-C++/Cpp-NET/asio-1.30.2/include
TARGET := Network
all: $(TARGET)
$(TARGET): main.o
	$(CXX) $(CXXFLAGS) -o $@ $^
main.o: main.cpp | $(INCDIR)
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c -o $@ $<
clean:
	rm -f $(TARGET) *.o

.PHONY: all clean

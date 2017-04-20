CXX       = g++
CXXFLAGS  = -Wall -I -std=c++0x -std=gnu++0x -fopenmp

PROGRAM   = firesim
SRCS      = firesim.cpp Random.cpp Forest.cpp
OBJS      = $(SRCS:.cpp=.o)

.SUFFIXES: .cpp .o

.cpp.o: 
	$(CXX) -c $(CXXFLAGS) $<

all: $(PROGRAM) 

$(PROGRAM): $(OBJS)
	$(CXX) -o $(PROGRAM) $(SRCS) $(CXXFLAGS) $(LDFLAGS)

clean:
	/bin/rm -f $(OBJS) $(PROGRAM)

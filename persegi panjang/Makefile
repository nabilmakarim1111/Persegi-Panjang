CXX?=g++ 
CXXFLAGS+= --std=c++17 -O3 -Wextra -I.
SOURCES=src/main.cpp src/persegipanjang.cpp

src/%.o: src/%.cpp 
	$(CXX) $(CXXFLAGS) -c -o $@ $<

app: $(SOURCES:.cpp=.o)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	del src\*.o
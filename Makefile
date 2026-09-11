CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
TARGET = storyteller
SOURCES = main.cpp person.cpp story.cpp Trait.cpp

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
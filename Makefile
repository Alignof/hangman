CC	 := gcc
CFLAGS := -g -O0

INCLUDE  := -I./include
TARGET   := ./hangman
SRCDIR   := ./src
OBJDIR   := ./src/obj
SOURCES  := $(wildcard ./src/*.cpp)
OBJECTS  := $(addprefix $(OBJDIR)/, $(notdir $(SOURCES:.cpp=.o)))

$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^ $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@[ -d $(OBJDIR) ]
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ -c $<

install: $(OBJECTS)
	$(CXX) -O2 -o $(TARGET) $^ $(LDFLAGS)

clean:
	rm -f $(OBJECTS) $(TARGET)

test: kinako-chan
	./hangman



.PHONY: test buildtest clean install

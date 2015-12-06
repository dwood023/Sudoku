COMPILER=g++ -std=c++11
LIBS:=
SRCFILES:=${wildcard src/*.cpp}
OBJFILES := $(addprefix obj/,$(notdir $(SRCFILES:.cpp=.o)))
EXECUTABLE:=Sudoku

all: bin/$(EXECUTABLE)

bin/$(EXECUTABLE): $(OBJFILES)
	@echo "** Build Happening **"
	$(COMPILER) $(LIBS) -g -o $@ $^ 

obj/%.o: src/%.cpp
	$(COMPILER) -g -c -o $@ $<

clean: 
	@echo "** Removing executable and objects **"
	rm -f bin/$(EXECUTABLE) $(OBJFILES)

killswp:
	@echo "Cleaning up swp trash"
	rm src/.*.swp

install:
	@echo "** Installing to /usr/bin **"
	cp bin/$(EXECUTABLE) /usr/bin
	
uninstall:
	@echo "** Uninstalling /usr/bin/Sudoku **"
	rm -f /usr/bin/$(EXECUTABLE)

run:
	./bin/$(EXECUTABLE)

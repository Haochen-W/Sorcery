CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD
EXEC = myprogram
OBJECTS = main.o concreteminion.o minion.o card.o player.o subject.o observer.o ascii_graphics.o textdisplay.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}

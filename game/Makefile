CXX = g++
CXXFLAGS = -std=c++14 -I/usr/X11/include -Wall -MMD
EXEC = sorcery
OBJECTS = main.o concreteminion.o concretespell.o concreteritual.o concreteenchantment.o minion.o ritual.o enchantment.o spell.o card.o player.o observer.o decorator.o ascii_graphics.o display.o textdisplay.o graphicdisplay.o window.o exception.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} $^ -o $@ -L/usr/X11/lib -lX11

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}

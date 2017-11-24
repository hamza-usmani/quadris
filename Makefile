CXX = g++
CXXFLAGS = -std=c++14 -g -MMD -Werror=vla
EXEC = quadris
OBJECTS = main.o board.o cell.o textdisplay.o Level.o Level_0.o block.o iblock.o jblock.o lblock.o oblock.o sblock.o zblock.o tblock.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean


CXX = g++
CXXFLAGS = -std=c++14 -g -MMD -Werror=vla
EXEC = quadris
OBJECTS = main.o board.o cell.o textdisplay.o Level.o Level_0.o Level_1.o Level_2.o Level_3.o Level_4.o block.o iblock.o jblock.o lblock.o oblock.o sblock.o zblock.o tblock.o blankblock.o window.o graphicsdisplay.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean


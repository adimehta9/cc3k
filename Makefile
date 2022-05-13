CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD
EXEC = cc3k
OBJECTS = main.o ba.o base.o bd.o board.o chamber.o character.o doorway.o dragon.o drow.o dwarf.o effects.o elf.o enemy.o gameobject.o goblin.o gold.o halfling.o human.o merchant.o orc.o passage.o ph.o potion.o race.o rh.o shade.o stairway.o troll.o vampire.o wa.o wall.o wd.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}

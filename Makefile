# Makefile for CPSC2430, Seattle University, Spring 2018
#

# Flags:
CPP_FLAGS = -std=c++11 -Wall -Werror -pedantic -ggdb
LNK_FLAGS = 
LIBS = -lgtest -lpthread

# Projects:
ifeq ($(shell pwd),/home/fac/lundeenk/cpsc2430/testmake)
	SUBMIT = ~lundeenk/submit/test
else
	SUBMIT = ~lundeenk/submit/18sq2430
endif

PROJECTS = tw1 tw2 tw3 lab1 lab2 lab3 p1 p2
WORK = RandomList.cpp lab1.cpp CrowWorld.cpp tw2.cpp lab2.cpp InchWorm.cpp Menagerie.cpp tw3.cpp PQueueLL.h adt/PriorityQueue.h BinaryNode.h lab3.cpp

GIVEN = CrowWorld.h InchWorm.h lab1_hints.cpp lab1_test.cpp lab2_test.cpp ListA.h ListLL.h PixelMatrix.h PixelMatrix.cpp QueueL.h RandomList.h RGB.cpp RGB.h Terminal.cpp Terminal.h Tower.cpp Tower.h tw1.cpp tw1_test.cpp tw2_hints.cpp p1.cpp Menagerie2.cpp Menagerie.h InchWorm2.cpp Pacer.cpp Pacer.h Cannon.cpp Cannon.h Cannonball.cpp Cannonball.h tw3_test.cpp RandomList_v2.h RandomList_v2.cpp p1_test.cpp lab3_test.cpp

ADTS = adt/List.h adt/Stack.h adt/Queue.h adt/Critter.h adt/Display.h adt/Printable.h
DATA_FILES = data/Cities.txt data/Cousins.txt data/Latitude.txt data/Longitude.txt
TEST_FILES = test/lab2_input.txt

# make with no argument means just update Makefile from source
default: Makefile
	@touch updated_makefile

# header dependencies for all .o files
Cannon.o : Cannon.h adt/Critter.h
Cannonball.o : Cannonball.h adt/Critter.h
CrowWorld.o : CrowWorld.h ListA.h adt/List.h
InchWorm.o : InchWorm.h adt/Critter.h PixelMatrix.o
InchWorm2.o : InchWorm.o
Menagerie.o : Menagerie.h Cannon.h InchWorm.h Cannonball.h Pacer.h ListA.h adt/List.h adt/Critter.h adt/Display.h QueueL.h adt/Queue.h
Menagerie2.o : Menagerie.o
Pacer.o : Pacer.h adt/Critter.h
PixelMatrix.o : RGB.o PixelMatrix.h
RGB.o : RGB.h ListA.h adt/List.h
RandomList.o : RandomList.h ListA.h adt/List.h
RandomList_v2.o : RandomList_v2.h ListA.h adt/List.h
Terminal.o : Terminal.h PixelMatrix.o adt/Display.h
Tower.o : Tower.h adt/Stack.h PixelMatrix.o
lab1.o : CrowWorld.o
lab1_test.o : lab1.o
lab2.o : InchWorm.o Terminal.o 
lab2_test.o : lab2.o
lab3.o : BinaryNode.h QueueL.h adt/Queue.h
lab3_test.o : lab3.o
p1.o : Menagerie.h ListA.h adt/List.h QueueL.h adt/Queue.h adt/Critter.h
p1_test.o : p1.o
tw1.o : RandomList.o
tw1_test.o : tw1.o
tw2.o : Tower.o Terminal.o QueueL.h adt/Queue.h
tw3.o : PQueueLL.h adt/PriorityQueue.h
tw3_test.o : PQueueLL.h adt/PriorityQueue.h

# TW1
tw1_prep : ListA.h adt/List.h RandomList.h tw1.cpp tw1_test.cpp
	@touch $@
tw1: tw1_prep tw1.o RandomList.o
	g++ $(LNK_FLAGS) $(filter %.o, $^) $(LIBS) -o $@
tw1_test: tw1 tw1_test.o RandomList.o 
	g++ $(LNK_FLAGS) $(filter %.o, $^) $(LIBS) -o $@_exe
	valgrind ./$@_exe

# L1
lab1_prep: CrowWorld.h lab1_hints.cpp lab1_test.cpp data/Cities.txt data/Cousins.txt data/Longitude.txt data/Latitude.txt
	@touch lab1_prep
lab1: lab1_prep lab1.o CrowWorld.o
	g++ $(LNK_FLAGS) $(filter %.o, $^) $(LIBS) -o $@
lab1_test: lab1 lab1_test.o CrowWorld.o
	g++ $(LNK_FLAGS) $(filter %.o, $^) $(LIBS) -o $@_exe
	valgrind ./$@_exe

# L2
lab2_prep: InchWorm.h PixelMatrix.h PixelMatrix.cpp Terminal.h Terminal.cpp RGB.h RGB.cpp lab2_test.cpp test/lab2_input.txt adt/Display.h adt/Critter.h adt/Printable.h
	@touch lab2_prep
L2_OBJ = InchWorm.o InchWorm2.o PixelMatrix.o Terminal.o RGB.o
lab2: lab2_prep lab2.o $(L2_OBJ)
	g++ $(LNK_FLAGS) $(filter %.o, $^) $(LIBS) -lncurses -o $@
lab2_test: lab2 lab2_test.o $(L2_OBJ)
	./lab2 < test/lab2_input.txt
	g++ $(LNK_FLAGS) $(filter %.o, $^) $(LIBS) -lncurses -o $@_exe
	valgrind ./$@_exe

# R3
reading_3: ListLL.h $(ADTS) 

# TW2
tw2_prep: Tower.h QueueL.h Tower.cpp tw2_hints.cpp
	@touch tw2_prep
tw2: tw2_prep tw2.o Tower.o Terminal.o PixelMatrix.o RGB.o
	g++ $(LNK_FLAGS) $(filter %.o, $^) $(LIBS) -lncurses -o $@
tw2_test: tw2
	@echo "There is no internal testing for tw2."

# P1
-include p1_make_extra
ifndef P1_EXTRA
    P1_EXTRA = 
endif
p1_prep: InchWorm.h PixelMatrix.h PixelMatrix.cpp Terminal.h Terminal.cpp RGB.h RGB.cpp InchWorm2.cpp Pacer.h Pacer.cpp adt/Display.h Cannon.h Cannon.cpp Cannonball.h Cannonball.cpp Menagerie.h Menagerie2.cpp p1.cpp adt/Printable.h
	@touch p1_prep
P1_CORE = Menagerie.o Menagerie2.o InchWorm.o InchWorm2.o Pacer.o Cannon.o Cannonball.o PixelMatrix.o RGB.o
p1: p1_prep p1.o $(P1_CORE) $(P1_EXTRA) Terminal.o
	g++ $(LNK_FLAGS) $(filter %.o, $^) $(LIBS) -lncurses -o $@
p1_test: $(P1_CORE) $(P1_EXTRA) Terminal.o p1_test.o
	g++ $(LNK_FLAGS) $(filter %.o, $^) $(LIBS) -lncurses -o $@_exe
	valgrind ./$@_exe

# TW3
tw3_prep: adt/Queue.h QueueL.h adt/List.h ListLL.h tw3_test.cpp RandomList_v2.cpp RandomList_v2.h ListA.h adt/List.h
	@touch tw3_prep
tw3: tw3_prep tw3.o 
	g++ $(LNK_FLAGS) $(filter %.o, $^) $(LIBS) -o $@
tw3_test: tw3 tw3_test.o RandomList_v2.o
	g++ $(LNK_FLAGS) $(filter %.o, $^) $(LIBS) -o $@_exe
	valgrind ./$@_exe

# L3
lab3_prep: QueueL.h adt/Queue.h
	@touch lab3_prep
lab3: lab3_prep lab3.o
	g++ $(LNK_FLAGS) $(filter %.o, $^) $(LIBS) -o $@
lab3_test: lab3 lab3_test.o
	g++ $(LNK_FLAGS) $(filter %.o, $^) $(LIBS) -o $@_exe
	valgrind ./$@_exe

# General Stuff
$(GIVEN) Makefile : % : $(SUBMIT)/files/%
	@if [ `pwd` != "/home/fac/lundeenk/cpsc2430" ];then 	\
		echo "Provide/update $@ (from $<)" ; \
		cp -f $< $@ ; \
    else \
		echo "Doh! You're in dev directory. $< newer than $@." ; \
	fi

SUBMIT_EXTRA ?= 
$(foreach proj, $(PROJECTS), $(proj)_submit) : %_submit: %
	$(SUBMIT)/script/$<_runme $(SUBMIT_EXTRA)

$(WORK) : % :
	@echo "Student-provided file, $@, not found"
	@false

$(ADTS): adt/%.h : $(SUBMIT)/files/adt/%.h
	@if [ `pwd` != "/home/fac/lundeenk/cpsc2430" ];then 	\
		echo "Provide/update $@ (from $<)" ; \
		if [ ! -d "./adt" ];then 	\
			mkdir ./adt; 		\
		fi ; \
		cp -f $< $@ ; \
    else \
		echo "Doh! You're in dev directory. $< newer than $@." ; \
	fi

$(DATA_FILES): data/% : $(SUBMIT)/files/data/%
	@if [ `pwd` != "/home/fac/lundeenk/cpsc2430" ];then 	\
		echo "Provide/update $@ (from $<)" ; \
		if [ ! -d "./data" ];then 	\
			mkdir ./data; 		\
		fi ; \
		cp -f $< $@ ; \
    else \
		echo "Doh! You're in dev directory. $< newer than $@." ; \
	fi

$(TEST_FILES): test/% : $(SUBMIT)/files/test/%
	@if [ `pwd` != "/home/fac/lundeenk/cpsc2430" ];then 	\
		echo "Provide/update $@ (from $<)" ; \
		if [ ! -d "./test" ];then 	\
			mkdir ./test; 		\
		fi ; \
		cp -f $< $@ ; \
    else \
		echo "Doh! You're in dev directory. $< newer than $@." ; \
	fi

%.o: %.cpp
	g++ $(CPP_FLAGS) -c $< -o $@

clean:
	rm -f $(GIVEN) $(ADTS) $(DATA_FILES) $(TEST_FILES)
	rm -f *.o
	rm -f $(PROJECTS)
	rm -f $(foreach proj, $(PROJECTS), $(proj)_prep)
	rm -f $(foreach proj, $(PROJECTS), $(proj)_test)
	rm -f $(foreach proj, $(PROJECTS), $(proj)_test_exe)

# release: cp -ruvi * $CS/files

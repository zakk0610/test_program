all: a.out

.SUFFIXES:
.PHONY: a.out

flag = -std=c++11 -g

clean:
	rm *.o -f
%.o:
	g++ $(patsubst %.o,%.cpp,$@) -o $@ -c $(flag)

a.out : main.o large_number.o
	g++ $^ -o $@ $(flag)

all: a.out

.SUFFIXES:
.PHONY: a.out

flag = -g

clean:
	rm *.o -f
%.o:
	g++ $(patsubst %.o,%.cpp,$@) -o $@ -c $(flag)

a.out : main.o GHR.o
	g++ $^ -o $@ $(flag)

CFLAGS = -lglfw3 -ldl -lm -lGL -lGLU -lX11
GFLAGS = -pthread

hello.o: hello.cpp 
	g++ ${GFLAGS} -o hello.o hello.cpp glad.c ${CFLAGS}

rect.o: rect.cpp 
	g++ ${GFLAGS} -o rect.o rect.cpp glad.c ${CFLAGS}
clean: 
	rm *.o

.PHONY : clean
OBJS = LinearList.o main.o
TARGET = LinearList
CFLAGS = -I ../utils -g -Wall

$(TARGET) : $(OBJS)
	gcc $(OBJS) -o $(TARGET)

clean:
	rm -rf ${OBJS} ${TARGET}

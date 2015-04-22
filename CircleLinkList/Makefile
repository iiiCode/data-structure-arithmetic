OBJS = CircleLinkList.o main.o
TARGET = CircleLinkList
CFLAGS = -I ../utils -g -Wall

$(TARGET) : $(OBJS)
	gcc $(OBJS) -o $(TARGET)

clean:
	rm -rf ${OBJS} ${TARGET} tags
tags:
	ctags -R .

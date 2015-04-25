OBJS = CircleDuLinkList.o main.o
TARGET = CircleDuLinkList
CFLAGS = -I ../utils -g -Wall

$(TARGET) : $(OBJS)
	gcc $(OBJS) -o $(TARGET)

clean:
	rm -rf ${OBJS} ${TARGET} tags
tags:
	ctags -R .

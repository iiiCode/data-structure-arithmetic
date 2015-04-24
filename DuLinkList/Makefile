OBJS = DuLinkList.o main.o
TARGET = DuLinkList
CFLAGS = -I ../utils -g -Wall

$(TARGET) : $(OBJS)
	gcc $(OBJS) -o $(TARGET) -lpthread

clean:
	rm -rf ${OBJS} ${TARGET} tags
tags:
	ctags -R .

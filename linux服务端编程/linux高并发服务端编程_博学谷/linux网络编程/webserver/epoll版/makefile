SRC=$(wildcard *.c)
OBJS=$(patsubst %.c, %.o, $(SRC))
TARGET = epoll_web

$(TARGET):$(OBJS)
	gcc $(OBJS) -o $(TARGET)

%.o:%.c
	gcc -c $< -o $@

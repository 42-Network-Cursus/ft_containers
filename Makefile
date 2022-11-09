#VECTOR_TEST =   tests/vector/basic.cpp tests/vector/basicRef.cpp tests/vector/iterators.cpp tests/vector/iteratorsRef.cpp tests/vector/operators.cpp tests/utility.cpp

SRCS		=	makefiletest.cpp


OBJS		=	$(SRCS:%.cpp=%.o) 

NAME		=	ft_containers

CC					=	c++
CFLAGS				=  -Wall -Wextra -Werror -fsanitize=address -std=c++98 -fsanitize=address -static-libasan\

all:		$(NAME)

$(NAME):		$(OBJS)
				${CC} ${CFLAGS} $(OBJS) -o ${NAME}

clean:
				@rm -f ${OBJS}

fclean:		clean
				@rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
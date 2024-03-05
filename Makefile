COMPILER	= cc
SOURCEFILES	=	main.c	\
				structs.c	\
				map.c	\
				gnl.c		\
				gnl_utils.c	\
				render.c	\
				hooks.c		\
				intro.c		\
				utils.c		\
				itoa.c		\
				levels.c
NAME	= eva_long
OBJ		= ${SOURCEFILES:.c=.o}
RM			= rm -f

all: $(NAME)

%.o: %.c
	$(COMPILER) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all

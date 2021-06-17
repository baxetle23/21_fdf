NAME	=	fdf

SRC		=	main.c get_next_line.c get_next_line_utils.c read_file.c draw.c color.c hot_key_1.c hot_key_2.c\
				utils.c gradient.c

HEDEAR	=	./includes/fdf.h

CFLAGS	=	-Wall -Werror -Wextra

OBJ		=	$(SRC:.c=.o)
%.o:		%.c ${HEADER}
				gcc $(CFLAGS) -c -o $@ $<

all		:	$(NAME)

$(NAME)	:	$(OBJ) $(HEDEAR)
	$(MAKE) -C ./libft
	gcc $(CFLAGS) $(OBJ) ./libft/libft.a -lmlx -framework OpenGL -framework AppKit -o $(NAME)

re		:	fclean all

clean	:
	$(MAKE) clean -C ./libft	
	rm -f $(OBJ)

fclean	:	clean
	$(MAKE) fclean -C ./libft	
	rm -f $(NAME)

.PHONY	:	all clean fclean re
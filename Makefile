NAME	=	fdf

SRC		=	main.c get_next_line.c get_next_line_utils.c read_file.c draw.c color.c hot_key_1.c hot_key_2.c\
				utils.c gradient.c

HEDEAR	=	./includes/fdf.h ./includes/get_next_line.h ./includes/libft.h

OBJ		=	$(SRC:.c=.o)

all		:	$(NAME)

$(NAME)	:	$(OBJ) $(HEDEAR)
	gcc $(OBJ) libft.a -lmlx -framework OpenGL -framework AppKit -o $(NAME)

re		:	fclean all

clean	:
	rm -f $(OBJ)

fclean	:	clean
	rm -f $(NAME)

.PHONY	:	all clean fclean remake
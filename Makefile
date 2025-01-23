NAME = push_swap
OBJ = ft_atoi.o ft_split.o main.o ft_substr.o ft_strlen.o ft_lstadd_front.o ft_lstadd_back.o ft_lstnew.o \
	ft_strchr.o ft_strlcpy.o ft_strlcat.o ft_strjoin.o ft_strdup.o ft_lstclear.o ft_strtrim.o
CFLAGS = -g -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $(NAME)

%.o: %.c push_swap.h libft.h
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
NAME = push_swap
BONUS_NAME = checker
OBJ = ft_atoi.o ft_split.o main.o ft_substr.o ft_strlen.o ft_lstadd_front.o ft_lstadd_back.o ft_lstnew.o \
	ft_strchr.o ft_strlcpy.o ft_strlcat.o ft_strjoin.o ft_strdup.o ft_lstclear.o ft_strtrim.o parser.o \
	parser_helper.o helper.o ft_lstsize.o operations.o ft_lstdelone.o ft_lstrev.o operations_extra.o sort.o \
	ft_strncmp.o sort_utils.o ft_printf.o ft_putaddress.o ft_putchar.o ft_putnbr.o ft_putstr.o ft_putunbr_base.o
CFLAGS = -g -Wall -Wextra -Werror

BONUS_OBJ = get_next_line.o checker_bonus.o ft_strncmp.o ft_atoi.o ft_split.o ft_substr.o ft_strlen.o ft_lstadd_front.o ft_lstadd_back.o ft_lstnew.o \
	ft_strchr.o ft_strlcpy.o ft_strlcat.o ft_strjoin.o ft_strdup.o ft_lstclear.o ft_strtrim.o parser.o \
	parser_helper.o helper.o ft_lstsize.o operations.o ft_lstdelone.o ft_lstrev.o operations_extra.o sort.o \
	ft_strncmp.o sort_utils.o ft_printf.o ft_putaddress.o ft_putchar.o ft_putnbr.o ft_putstr.o ft_putunbr_base.o

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $(NAME)

$(BONUS_NAME): $(BONUS_OBJ) 
	$(CC) $(CFLAGS) $^ -o $(BONUS_NAME)

bonus: $(BONUS_NAME)

%.o: %.c push_swap.h libft.h ft_printf
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f $(OBJ)
	rm -f $(BONUS_OBJ)
fclean : clean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)
re : fclean all
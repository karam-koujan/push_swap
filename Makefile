NAME = push_swap
BONUS_NAME = checker
OBJ = ft_atoi.o ft_split.o main.o ft_substr.o ft_strlen.o ft_lstadd_back.o ft_lstnew.o \
	ft_strchr.o ft_strlcpy.o ft_strlcat.o ft_strjoin.o ft_strdup.o ft_lstclear.o ft_strtrim.o parser.o \
	parser_helper.o helper.o ft_lstsize.o operations.o ft_lstrev.o operations_extra.o sort.o \
	sort_utils.o ft_printf.o ft_putaddress.o ft_putchar.o ft_putnbr.o ft_putstr.o ft_putunbr_base.o sort_extra.o
CFLAGS = -g -fsanitize=address -Wall -Wextra -Werror

BONUS_OBJ = ./bonus/checker_bonus.o ./bonus/get_next_line_bonus.o ./bonus/ft_strncmp_bonus.o ./bonus/ft_atoi_bonus.o ./bonus/ft_split_bonus.o ./bonus/ft_substr_bonus.o ./bonus/ft_strlen_bonus.o ./bonus/ft_lstadd_back_bonus.o ./bonus/ft_lstnew_bonus.o \
	./bonus/ft_strchr_bonus.o ./bonus/ft_strlcpy_bonus.o ./bonus/ft_strlcat_bonus.o ./bonus/ft_strjoin_bonus.o ./bonus/ft_strdup_bonus.o ./bonus/ft_lstclear_bonus.o ./bonus/ft_strtrim_bonus.o ./bonus/parser_bonus.o \
	./bonus/parser_helper_bonus.o ./bonus/helper_bonus.o ./bonus/ft_lstsize_bonus.o ./bonus/operations_bonus.o ./bonus/ft_lstrev_bonus.o ./bonus/operations_extra_bonus.o  \
	 ./bonus/ft_printf_bonus.o ./bonus/ft_putaddress_bonus.o ./bonus/ft_putchar_bonus.o ./bonus/ft_putnbr_bonus.o ./bonus/ft_putstr_bonus.o ./bonus/ft_putunbr_base_bonus.o ./bonus/check_extra_bonus.o


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $(NAME)

$(BONUS_NAME): $(BONUS_OBJ) 
	$(CC) $(CFLAGS) $^ -o $(BONUS_NAME)

bonus: $(BONUS_NAME)

./bonus/%.o: ./bonus/%.c ./bonus/push_swap_bonus.h ./bonus/libft_bonus.h ./bonus/ft_printf_bonus.h ./bonus/get_next_line_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@
%.o: %.c push_swap.h libft.h ft_printf.h
	$(CC)  $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	rm -f $(BONUS_OBJ)
fclean : clean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)
re : fclean all
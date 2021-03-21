NAME       = ft_containers

DIR_HPP    = srcs/
DIR_TESTS  = tests/
DIR_BIN    = bin/
DIR_OUT    = out/
CC         = clang++
CFLAGS     = -Wall -Wextra -Werror -I $(DIR_HPP) -std=c++98
RM         = rm -f

ORANGE     = \033[1;33m
COLOR      = \033[1;32m
NC         = \033[0m

LIST_SRC        = $(DIR_TESTS)test_list.cpp
VECTOR_SRC      = $(DIR_TESTS)test_vector.cpp
MAP_SRC         = $(DIR_TESTS)test_map.cpp
STACK_SRC       = $(DIR_TESTS)test_stack.cpp
QUEUE_SRC       = $(DIR_TESTS)test_queue.cpp
SET_SRC         = $(DIR_TESTS)test_set.cpp
MULTISET_SRC    = $(DIR_TESTS)test_multiset.cpp
MULTIMAP_SRC    = $(DIR_TESTS)test_multimap.cpp
INPUT_SRC       = $(DIR_TESTS)test_input.cpp

all : $(NAME)

$(NAME) : start_msg list vector map stack queue end_msg

bonus : start_msg set multiset multimap end_msg

input : $(INPUT_SRC)
	@echo "$(COLOR)Tests $@:$(NC)"
	$(CC) $(CFLAGS) $< -o $(DIR_BIN)$@_ft
	./$(DIR_BIN)$@_ft

start_msg :
	@echo "$(ORANGE)Starting Tests:$(NC)"

end_msg :
	@echo "$(ORANGE)End of Tests.$(NC)"

list : $(LIST_SRC)
	@echo "$(COLOR)Tests $@:$(NC)"
	$(CC) $(CFLAGS) $< -o $(DIR_BIN)$@_ft
	./$(DIR_BIN)$@_ft > $(DIR_OUT)$@_ft.out
	$(CC) $(CFLAGS) -D STD $< -o $(DIR_BIN)$@_std
	./$(DIR_BIN)$@_std > $(DIR_OUT)$@_std.out
	diff $(DIR_OUT)$@_ft.out $(DIR_OUT)$@_std.out

vector : $(VECTOR_SRC)
	@echo "$(COLOR)Tests $@:$(NC)"
	$(CC) $(CFLAGS) $< -o $(DIR_BIN)$@_ft
	./$(DIR_BIN)$@_ft > $(DIR_OUT)$@_ft.out
	$(CC) $(CFLAGS) -D STD $< -o $(DIR_BIN)$@_std
	./$(DIR_BIN)$@_std > $(DIR_OUT)$@_std.out
	diff $(DIR_OUT)$@_ft.out $(DIR_OUT)$@_std.out

map : $(MAP_SRC)
	@echo "$(COLOR)Tests $@:$(NC)"
	$(CC) $(CFLAGS) $< -o $(DIR_BIN)$@_ft
	./$(DIR_BIN)$@_ft > $(DIR_OUT)$@_ft.out
	$(CC) $(CFLAGS) -D STD $< -o $(DIR_BIN)$@_std
	./$(DIR_BIN)$@_std > $(DIR_OUT)$@_std.out
	diff $(DIR_OUT)$@_ft.out $(DIR_OUT)$@_std.out

stack : $(STACK_SRC)
	@echo "$(COLOR)Tests $@:$(NC)"
	$(CC) $(CFLAGS) $< -o $(DIR_BIN)$@_ft
	./$(DIR_BIN)$@_ft > $(DIR_OUT)$@_ft.out
	$(CC) $(CFLAGS) -D STD $< -o $(DIR_BIN)$@_std
	./$(DIR_BIN)$@_std > $(DIR_OUT)$@_std.out
	diff $(DIR_OUT)$@_ft.out $(DIR_OUT)$@_std.out

queue : $(QUEUE_SRC)
	@echo "$(COLOR)Tests $@:$(NC)"
	$(CC) $(CFLAGS) $< -o $(DIR_BIN)$@_ft
	./$(DIR_BIN)$@_ft > $(DIR_OUT)$@_ft.out
	$(CC) $(CFLAGS) -D STD $< -o $(DIR_BIN)$@_std
	./$(DIR_BIN)$@_std > $(DIR_OUT)$@_std.out
	diff $(DIR_OUT)$@_ft.out $(DIR_OUT)$@_std.out

set : $(SET_SRC)
	@echo "$(COLOR)Tests $@:$(NC)"
	$(CC) $(CFLAGS) $< -o $(DIR_BIN)$@_ft
	./$(DIR_BIN)$@_ft > $(DIR_OUT)$@_ft.out
	$(CC) $(CFLAGS) -D STD $< -o $(DIR_BIN)$@_std
	./$(DIR_BIN)$@_std > $(DIR_OUT)$@_std.out
	diff $(DIR_OUT)$@_ft.out $(DIR_OUT)$@_std.out

multiset : $(MULTISET_SRC)
	@echo "$(COLOR)Tests $@:$(NC)"
	$(CC) $(CFLAGS) $< -o $(DIR_BIN)$@_ft
	./$(DIR_BIN)$@_ft > $(DIR_OUT)$@_ft.out
	$(CC) $(CFLAGS) -D STD $< -o $(DIR_BIN)$@_std
	./$(DIR_BIN)$@_std > $(DIR_OUT)$@_std.out
	diff $(DIR_OUT)$@_ft.out $(DIR_OUT)$@_std.out

multimap : $(MULTIMAP_SRC)
	@echo "$(COLOR)Tests $@:$(NC)"
	$(CC) $(CFLAGS) $< -o $(DIR_BIN)$@_ft
	./$(DIR_BIN)$@_ft > $(DIR_OUT)$@_ft.out
	$(CC) $(CFLAGS) -D STD $< -o $(DIR_BIN)$@_std
	./$(DIR_BIN)$@_std > $(DIR_OUT)$@_std.out
	diff $(DIR_OUT)$@_ft.out $(DIR_OUT)$@_std.out

clean :
	$(RM) $(wildcard $(DIR_OUT)*)

fclean : clean
	$(RM) $(wildcard $(DIR_BIN)*)

re : fclean all

.PHONY: all start_msg end_msg input list vector map stack queue \
		set multiset multimap clean fclean re

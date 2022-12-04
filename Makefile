
SF			=	./TEST-LOG/set
STF			=	./TEST-LOG/stack
MF			=	./TEST-LOG/map
VF			=	./TEST-LOG/vector

FT			=	ft_test
STD			=	std_test
O			=	Unit-Tests/objects
S			=	Unit-Tests/srcs/
INCL		= 	Unit-Tests/incl/

FLAGS		=	-Wall -Wextra -Werror -std=c++98  -I$(INCL) \
# -fsanitize=address -static-libasan -g
RM			=	rm -rf

SRCS		=	main.cpp \
				vector_test.cpp \
				stack_test.cpp \
				set_test.cpp \
				map_test.cpp
SRCS 		:=	$(foreach file, $(SRCS), $S$(file))

FT_OBJ		=	$O/ft_objs/
FT_OBJS		=	$(SRCS:$S%=$(FT_OBJ)%.o)

STD_OBJ		=	$O/std_objs/
STD_OBJS	=	$(SRCS:$S%=$(STD_OBJ)%.o)

all			: $(FT) $(STD)

$(STD_OBJ)	:
				@mkdir -p $@
$(STD_OBJS)	:	| $(STD_OBJ)
$(STD_OBJS)	:	$(STD_OBJ)%.o: $S%
		 		@c++ $(FLAGS) -D USING_STD -c $< -o $@

$(STD)    	:	$(STD_OBJS)
				@echo "Compiling STD executable..."
				@c++ $(FLAGS) $^ -o $@

$(FT_OBJ)	:
				@mkdir -p $@
$(FT_OBJS)	:	| $(FT_OBJ)
$(FT_OBJS)	:	$(FT_OBJ)%.o: $S%
		 		@c++ $(FLAGS) -c $< -o $@

$(FT) 		:	$(FT_OBJS)
				@echo "Compiling FT executable..."
				@c++ $(FLAGS) -I$(INCL) $^ -o $@

clean		:
				@echo "Cleaning: $O"
				@rm -rf $O

fclean		: clean
				@echo "Cleaning: $(FT)"
				@$(RM) ./ft_test
				@echo "Cleaning: $(STD)"
				@$(RM) ./std_test
				@echo "Cleaning: $(VF)"
				@$(RM) $(VF)
				@echo "Cleaning: $(STF)"
				@$(RM) $(STF)
				@echo "Cleaning: $(SF)"
				@$(RM) $(SF)
				@echo "Cleaning: $(MF)"
				@$(RM) $(MF)
				@$(RM) ./TEST-LOG

re		:	fclean all

run		:
			@mkdir -p $(MF)
			@mkdir -p $(VF)
			@mkdir -p $(SF)
			@mkdir -p $(STF)
			@./$(FT)
			@./$(STD)
			@echo "Output redirected to TEST-LOG directory."

PHONY	:	all clean fclean re run diff
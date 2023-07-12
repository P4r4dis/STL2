G++						=	g++
###############################################
PART0_PATH 				= 	./Find
PART0_SRC_PATH			=	./Find/src
PART0_TST_PATH			=	./Find/tests
PART0_INC_PATH			=	./Find/include
NAME_FIND				=	Find
PART0_SRC				=	$(PART0_SRC_PATH)/Find.cpp

PART0_SRC_TEST			=	$(PART0_TST_PATH)/$(NAME_FIND)_test.cpp
TEST_NAME_FIND 			= 	test_$(NAME_FIND)

#################################################					
PART1_PATH 				= 	./Algorithm
PART1_SRC_PATH			=	./Algorithm/src
PART1_TST_PATH			=	./Algorithm/tests
PART1_INC_PATH			=	./Algorithm/include
NAME_MYALGORITHMS		=	MyAlgorithms
PART1_SRC				=	$(PART1_SRC_PATH)/MyAlgorithms.cpp

PART1_SRC_TEST			=	$(PART1_TST_PATH)/$(NAME_MYALGORITHMS)_test.cpp
TEST_NAME_MYALGORITHMS 	= 	test_$(NAME_MYALGORITHMS)

#################################################
PART2_PATH 				= 	./Caesar
PART2_SRC_PATH			=	./Caesar/src
PART2_TST_PATH			=	./Caesar/tests
PART2_INC_PATH			=	./Caesar/include
NAME_CAESAR				=	Caesar
PART2_SRC				=	$(PART2_SRC_PATH)/Caesar.cpp \
							$(PART2_SRC_PATH)/OneTime.cpp

PART2_SRC_TEST			=	$(PART2_TST_PATH)/$(NAME_CAESAR)_test.cpp
TEST_NAME_CAESAR	 	= 	test_$(NAME_CAESAR)

#################################################	
OBJS					=	$(SRCS:.cpp=.o)
CLEAN					=	clean
FCLEAN					=	fclean
RM						=	rm -rf

clean					:
							$(RM) $(OBJS)
							@$(MAKE) $(CLEAN) -C $(PART0_TST_PATH)
							@$(MAKE) $(CLEAN) -C $(PART1_TST_PATH)
							@$(MAKE) $(CLEAN) -C $(PART2_TST_PATH)
# @$(MAKE) $(CLEAN) -C $(PART3_TST_PATH)
# @$(MAKE) $(CLEAN) -C $(PART4_TST_PATH)
# @$(MAKE) $(CLEAN) -C $(PART5_TST_PATH)


fclean					:	clean
							$(RM) $(NAME) $(TEST_NAME)
							@$(MAKE) $(FCLEAN) -C $(PART0_TST_PATH)
							@$(MAKE) $(FCLEAN) -C $(PART0_PATH)
							@$(MAKE) $(FCLEAN) -C $(PART1_TST_PATH)
							@$(MAKE) $(FCLEAN) -C $(PART1_PATH)
							@$(MAKE) $(FCLEAN) -C $(PART2_TST_PATH)
							@$(MAKE) $(FCLEAN) -C $(PART2_PATH)
# @$(MAKE) $(FCLEAN) -C $(PART3_TST_PATH)
# @$(MAKE) $(FCLEAN) -C $(PART3_PATH)
# @$(MAKE) $(FCLEAN) -C $(PART4_TST_PATH)
# @$(MAKE) $(FCLEAN) -C $(PART4_PATH)
# @$(MAKE) $(FCLEAN) -C $(PART5_TST_PATH)
# @$(MAKE) $(FCLEAN) -C $(PART5_PATH)
re						: 	fclean all

find 					: 	fclean
							@$(MAKE) -C $(PART0_PATH)
							$(PART0_PATH)/$(NAME_FIND)

tests_run_find			:	fclean
							@$(MAKE) -C $(PART0_TST_PATH)
							$(PART0_TST_PATH)/$(TEST_NAME_FIND)

algorithm 					: 	fclean
							@$(MAKE) -C $(PART1_PATH)
							$(PART1_PATH)/$(NAME_MYALGORITHMS)

tests_run_algorithm			:	fclean
							@$(MAKE) -C $(PART1_TST_PATH)
							$(PART1_TST_PATH)/$(TEST_NAME_MYALGORITHMS)

caesar	 					: 	fclean
							@$(MAKE) -C $(PART2_PATH)
							$(PART2_PATH)/$(NAME_CAESAR)

tests_run_caesar			:	fclean
							@$(MAKE) -C $(PART2_TST_PATH)
							$(PART2_TST_PATH)/$(TEST_NAME_CAESAR)

tests_run				:	fclean
							@$(MAKE) tests_run_find

.PHONY					: 	all clean fclean re \
							tests_run \
							find tests_run_find \
							algorithm tests_run_algorithm \
							caesar tests_run_caesar

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
PART3_PATH 				= 	./Wrapper
PART3_SRC_PATH			=	./Wrapper/src
PART3_TST_PATH			=	./Wrapper/tests
PART3_INC_PATH			=	./Wrapper/include
NAME_WRAPPER			=	Wrapper
PART3_SRC				=	$(PART3_SRC_PATH)/Caesar.cpp \
							$(PART3_SRC_PATH)/OneTime.cpp \
							$(PART3_SRC_PATH)/Encryption.cpp

PART3_SRC_TEST			=	$(PART3_TST_PATH)/$(NAME_WRAPPER)_test.cpp
TEST_NAME_WRAPPER	 	= 	test_$(NAME_WRAPPER)

#################################################
PART4_PATH 				= 	./Container
PART4_SRC_PATH			=	./Container/src
PART4_TST_PATH			=	./Container/tests
PART4_INC_PATH			=	./Container/include
NAME_CONTAINER			=	Container
#PART4_SRC				=	

PART4_SRC_TEST			=	$(PART3_TST_PATH)/$(NAME_CONTAINER)_test.cpp
TEST_NAME_CONTAINER	 	= 	test_$(NAME_CONTAINER)

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
							@$(MAKE) $(CLEAN) -C $(PART3_TST_PATH)
							@$(MAKE) $(CLEAN) -C $(PART4_TST_PATH)
# @$(MAKE) $(CLEAN) -C $(PART5_TST_PATH)


fclean					:	clean
							$(RM) $(NAME) $(TEST_NAME)
							@$(MAKE) $(FCLEAN) -C $(PART0_TST_PATH)
							@$(MAKE) $(FCLEAN) -C $(PART0_PATH)
							@$(MAKE) $(FCLEAN) -C $(PART1_TST_PATH)
							@$(MAKE) $(FCLEAN) -C $(PART1_PATH)
							@$(MAKE) $(FCLEAN) -C $(PART2_TST_PATH)
							@$(MAKE) $(FCLEAN) -C $(PART2_PATH)
							@$(MAKE) $(FCLEAN) -C $(PART3_TST_PATH)
							@$(MAKE) $(FCLEAN) -C $(PART3_PATH)
							@$(MAKE) $(FCLEAN) -C $(PART4_TST_PATH)
							@$(MAKE) $(FCLEAN) -C $(PART4_PATH)

re						: 	fclean all

find 					: 	fclean
							@$(MAKE) -C $(PART0_PATH)
							$(PART0_PATH)/$(NAME_FIND)

tests_run_find			:	fclean
							@$(MAKE) -C $(PART0_TST_PATH)
							$(PART0_TST_PATH)/$(TEST_NAME_FIND)

algorithm 				: 	fclean
							@$(MAKE) -C $(PART1_PATH)
							$(PART1_PATH)/$(NAME_MYALGORITHMS)

tests_run_algorithm		:	fclean
							@$(MAKE) -C $(PART1_TST_PATH)
							$(PART1_TST_PATH)/$(TEST_NAME_MYALGORITHMS)

caesar	 				: 	fclean
							@$(MAKE) -C $(PART2_PATH)
							$(PART2_PATH)/$(NAME_CAESAR)

tests_run_caesar		:	fclean
							@$(MAKE) -C $(PART2_TST_PATH)
							$(PART2_TST_PATH)/$(TEST_NAME_CAESAR)

wrapper	 				: 	fclean
							@$(MAKE) -C $(PART3_PATH)
							$(PART3_PATH)/$(NAME_WRAPPER)

tests_run_wrapper		:	fclean
							@$(MAKE) -C $(PART3_TST_PATH)
							$(PART3_TST_PATH)/$(TEST_NAME_WRAPPER)

container	 			: 	fclean
							@$(MAKE) -C $(PART4_PATH)
							$(PART4_PATH)/$(NAME_CONTAINER)

tests_run_container		:	fclean
							@$(MAKE) -C $(PART4_TST_PATH)
							$(PART4_TST_PATH)/$(TEST_NAME_CONTAINER)

tests_run				:	fclean
							@$(MAKE) tests_run_find

.PHONY					: 	all clean fclean re \
							tests_run \
							find tests_run_find \
							algorithm tests_run_algorithm \
							caesar tests_run_caesar \
							wrapper tests_run_wrapper \
							container tests_run_container

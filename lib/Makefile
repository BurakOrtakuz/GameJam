NAME		=	graphic.a

INC_FLAGS	=	-I.
LDFLAGS		=	-lglfw -ldl -lGL -lz

OBJDIR		=	obj

CSRC		=	glad/glad.c \
				stb_images/stb_image.c

CXXSRC		=	graphic/Graphic.cpp

COBJ		=	$(CSRC:%.c=$(OBJDIR)/%.o)
CXXOBJ		=	$(CXXSRC:%.cpp=$(OBJDIR)/%.o)
OBJS		=	$(COBJ) $(CXXOBJ)

CC			=	clang
CXX			=	clang++

CFLAGS		=	-Wall -Wextra -Werror
CXXFLAGS	=	-Wall -Wextra -Werror

AR			=	ar rcs
RM			=	rm -rf
MKDIR		=	mkdir -p

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJDIR)

f: fclean
fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re f

$(OBJDIR)/%.o:%.c
	@$(MKDIR) $(dir $@)
	$(CC) $(CFLAGS) $(INC_FLAGS) -c $< -o $@

$(OBJDIR)/%.o:%.cpp
	@$(MKDIR) $(dir $@)
	$(CXX) $(CXXFLAGS) $(INC_FLAGS) -c $< -o $@


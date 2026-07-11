NAME = animals

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp \
      Animal.cpp \
      Brain.cpp \
      Cat.cpp \
      Dog.cpp \
      WrongAnimal.cpp \
      WrongCat.cpp

HEADERS = Animal.hpp \
          Brain.hpp \
          Cat.hpp \
          Dog.hpp \
          WrongAnimal.hpp \
          WrongCat.hpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
SRC_DIR = src
BIN_DIR = bin
OBJ = $(SRC_DIR)/to_roman.o $(SRC_DIR)/from_roman.o
BIN = $(subst $(SRC_DIR),$(BIN_DIR),$(patsubst %.o,%,$(OBJ)))

CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -Werror

all: $(BIN)

$(BIN_DIR)/%: $(SRC_DIR)/%.o
	$(LINK.c) $^ $(LOADLIBES) $(LDLIBS) -o $@

.PHONY: clean test

clean:
	-rm -f $(SRC_DIR)/*.o $(BIN_DIR)/*

test: all
	@{ printf '%d\n' {1..3999}; } | $(BIN_DIR)/to_roman | $(BIN_DIR)/from_roman | awk 'BEGIN{error=0}NR!=$$0{print "ERROR: value should be " NR " but is " $$0;error=1}END{exit error}'

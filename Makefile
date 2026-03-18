# ==============================================================
# Makefile — C Menu Calculator
# ==============================================================

CC      = gcc
CFLAGS  = -Wall -Wextra -Wpedantic -std=c11 -Iinclude
LDFLAGS = -lm

SRC_DIR = src
OBJ_DIR = build
BIN     = calculator

SRCS    = $(wildcard $(SRC_DIR)/*.c)
OBJS    = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# ── default target ─────────────────────────────────────────
.PHONY: all
all: $(OBJ_DIR) $(BIN)

$(BIN): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)
	@echo "  Build successful → ./$(BIN)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# ── debug build ────────────────────────────────────────────
.PHONY: debug
debug: CFLAGS += -g -DDEBUG -fsanitize=address
debug: LDFLAGS += -fsanitize=address
debug: all

# ── run ────────────────────────────────────────────────────
.PHONY: run
run: all
	./$(BIN)

# ── clean ──────────────────────────────────────────────────
.PHONY: clean
clean:
	rm -rf $(OBJ_DIR) $(BIN)
	@echo "  Cleaned build artifacts."

# ── help ───────────────────────────────────────────────────
.PHONY: help
help:
	@echo ""
	@echo "  make          Build the calculator (release)"
	@echo "  make debug    Build with debug symbols + AddressSanitizer"
	@echo "  make run      Build and run"
	@echo "  make clean    Remove build artifacts"
	@echo ""

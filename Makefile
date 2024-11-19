# Compiler and flags
CC = arm-none-eabi-gcc
CFLAGS = -mcpu=cortex-m0 -mthumb -O0 -g -Wall -ffunction-sections -fdata-sections -std=c99
LDFLAGS = -mcpu=cortex-m0 -mthumb -T linker_script.ld -nostartfiles -Wl,--gc-sections

# Source files
SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)

# Output file
OUTPUT = firmware.bin

# Linker script (you'll need to create this based on your memory map)
LINKER_SCRIPT = linker_script.ld

# Build rules
all: $(OUTPUT)

$(OUTPUT): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OUTPUT)

# Phony targets
.PHONY: all clean

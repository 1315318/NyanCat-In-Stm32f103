# 1. 交叉编译器设置
CC      = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy
SIZE    = arm-none-eabi-size

# 2. 项目名称与路径
TARGET  = project
BUILD_DIR = build

# 3. 搜索所有的源文件 (.c 和 .s)
# 显式指定启动文件路径
AS_SOURCES = startup/startup_stm32f103xb.s

# 自动搜集所有子目录的 C 文件
C_SOURCES =  $(wildcard app/*.c) \
             $(wildcard drivers/*.c) \
             $(wildcard include/*.c) \
             $(wildcard *.c)

# 4. 包含头文件路径 (让编译器能找到那些 .h)
C_INCLUDES =  -Iapp \
              -Idrivers \
              -Iinclude \
              -I.

# 5. 编译参数设置
CPU     = -mcpu=cortex-m3
MCU     = $(CPU) -mthumb
CFLAGS  = $(MCU) -ffreestanding -nostdlib -g -O0 -Wall $(C_INCLUDES)

# 6. 链接参数设置 (指定链接脚本)
LDSCRIPT = STM32F103XX_FLASH.ld
LDFLAGS  = $(MCU) -T$(LDSCRIPT) -nostdlib -Wl,-Map=$(TARGET).map

# 7. 对象文件列表
# 关键：手动提取 startup.o 并确保它在列表第一位
OBJECTS = startup.o $(C_SOURCES:.c=.o)

# ------------------------------------------------
# 构建规则
# ------------------------------------------------

all: $(TARGET).bin $(TARGET).elf
	@$(SIZE) $(TARGET).elf

# 最终生成二进制文件
$(TARGET).bin: $(TARGET).elf
	$(OBJCOPY) -O binary $< $@

# 链接阶段：这里 $(OBJECTS) 确保了 startup.o 是第一个参数
$(TARGET).elf: $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

# 编译 C 文件的通用规则
%.o: %.c
	@echo "Compiling $<..."
	@$(CC) -c $< $(CFLAGS) -o $@

# 编译汇编文件的规则
startup.o: $(AS_SOURCES)
	@echo "Assembling $<..."
	@$(CC) -c $< $(CFLAGS) -o $@

# 清理
clean:
	rm -f $(shell find . -name "*.o") *.elf *.bin *.map

# 烧录 (使用 st-flash)
flash: $(TARGET).bin
	st-flash write $(TARGET).bin 0x08000000

.PHONY: all clean flash
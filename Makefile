ARMGNU ?= arm-none-eabi
BUILD = build/
SOURCE = source/
TARGET = kernel.img
LIST = kernel.list
MAP = kernel.map
LINKER = kernel.ld

OBJECTS += $(patsubst $(SOURCE)%.s,$(BUILD)%.o,$(wildcard $(SOURCE)*.s)) $(patsubst $(SOURCE)%.c,$(BUILD)%.o,$(wildcard $(SOURCE)*.c))
OBJECTS += $(patsubst $(SOURCE)/Lib/%.s,$(BUILD)%.o,$(wildcard $(SOURCE)/Lib/*.s)) $(patsubst $(SOURCE)/Lib/%.c,$(BUILD)%.o,$(wildcard $(SOURCE)/Lib/*.c))
OBJECTS += $(patsubst $(SOURCE)/Misc/%.s,$(BUILD)%.o,$(wildcard $(SOURCE)/Misc/*.s)) $(patsubst $(SOURCE)/Misc/%.c,$(BUILD)%.o,$(wildcard $(SOURCE)/Misc/*.c))
OBJECTS += $(patsubst $(SOURCE)/Graphics/%.s,$(BUILD)%.o,$(wildcard $(SOURCE)/Graphics/*.s)) $(patsubst $(SOURCE)/Graphics/%.c,$(BUILD)%.o,$(wildcard $(SOURCE)/Graphics/*.c))

all: $(TARGET) $(LIST)

rebuild: all

# Rule to make the listing file.
$(LIST) : $(BUILD)output.elf
	$(ARMGNU)-objdump -d $(BUILD)output.elf > $(LIST)

# Rule to make the image file.
$(TARGET) : $(BUILD)output.elf
	$(ARMGNU)-objcopy $(BUILD)output.elf -O binary $(TARGET) 

# Rule to make the elf file.
$(BUILD)output.elf : $(OBJECTS) $(LINKER)
	$(ARMGNU)-ld --no-undefined $(OBJECTS) -Map $(MAP) -o $(BUILD)output.elf -T $(LINKER)

# source/
$(BUILD)%.o: $(SOURCE)%.s $(BUILD)
	$(ARMGNU)-as -I $(SOURCE) $< -o $@
$(BUILD)%.o: $(SOURCE)%.c $(BUILD)
	$(ARMGNU)-gcc -I $(SOURCE) $< -c -o $@
# source/Util	
$(BUILD)%.o: $(SOURCE)/Lib/%.s $(BUILD)
	$(ARMGNU)-as -I $(SOURCE) $< -o $@
$(BUILD)%.o: $(SOURCE)/Lib/%.c $(BUILD)
	$(ARMGNU)-gcc -I $(SOURCE) $< -c -o $@
# source/Misc	
$(BUILD)%.o: $(SOURCE)/Misc/%.s $(BUILD)
	$(ARMGNU)-as -I $(SOURCE) $< -o $@
$(BUILD)%.o: $(SOURCE)/Misc/%.c $(BUILD)
	$(ARMGNU)-gcc -I $(SOURCE) $< -c -o $@
# source/Graphics	
$(BUILD)%.o: $(SOURCE)/Graphics/%.s $(BUILD)
	$(ARMGNU)-as -I $(SOURCE) $< -o $@
$(BUILD)%.o: $(SOURCE)/Graphics/%.c $(BUILD)
	$(ARMGNU)-gcc -I $(SOURCE) $< -c -o $@

$(BUILD):
	mkdir $@

clean : 
	-rm -rf $(BUILD)
	-rm -f $(TARGET)
	-rm -f $(LIST)
	-rm -f $(MAP)


# REQUIRES: MODULE_NAME TARGET INSTALL_DIR
# WHAT CAN BE CHANGED: FLAGS COMPILE_FLAGS LINK_FLAGS LIBRARIES ADDITIONAL_OBJECTS

FLAGS = -ffreestanding -nostdlib
COMPILE_FLAGS = -I../../include

_CSOURCES = $(shell echo src/*.c)
_SSOURCES = $(shell echo src/*.s)

CSOURCES = $(subst src/*.c, ,$(_CSOURCES))
SSOURCES = $(subst src/*.s, ,$(_SSOURCES))

_OBJECTS = $(SSOURCES:.s=_s.o)
_OBJECTS += $(CSOURCES:.c=_c.o)

OBJECTS = $(subst src,../../obj/$(MODULE_NAME),$(_OBJECTS))

../../obj/$(MODULE_NAME)/%_c.o: src/%.c
	mkdir -p $(@D)
	gcc $(FLAGS) $(COMPILE_FLAGS) -c $< -o $@ $(LIBRARIES)
	
../../obj/$(MODULE_NAME)/%_s.o: src/%.s
	mkdir -p $(@D)
	gcc $(FLAGS) $(COMPILE_FLAGS) -c $< -o $@ $(LIBRARIES)
	
$(TARGET): $(OBJECTS)
	mkdir -p $(@D)
	gcc $(FLAGS) $(LINK_FLAGS) -o $(TARGET) $(ADDITIONAL_OBJECTS) $(OBJECTS) $(LIBRARIES)
	
install: $(TARGET)
	cp $(TARGET) $(INSTALL_DIR)
	
clean:
	-rm -rf ../../obj/$(MODULE_NAME)
	-rm -rf $(TARGET)
	
all: clean install
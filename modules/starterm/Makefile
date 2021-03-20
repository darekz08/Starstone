
include ../../drive.mk

MODULE_NAME = starterm
TARGET = ../../target/starterm
INSTALL_DIR = $(MOUNT_DIRECTORY)/bin/starterm
ADDITIONAL_OBJECTS = ../../crt0.o

include ../../base.mk

FLAGS += -L$(MOUNT_DIRECTORY)/lib
LIBRARIES += -lstar -lc

include ../../drive.mk

MODULE_NAME = init
TARGET = ../../target/init
INSTALL_DIR = $(MOUNT_DIRECTORY)/sbin/init
ADDITIONAL_OBJECTS = ../../crt0.o

include ../../base.mk

FLAGS += -L$(MOUNT_DIRECTORY)/lib
LIBRARIES += -lstar
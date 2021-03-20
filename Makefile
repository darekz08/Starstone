
modules = libstar.mod \
	  init.mod \
	  starterm.mod

install: $(modules)

%.mod: modules/%
	cd $< && make all
	
mnt:
	-mount $(MOUNT_PARTITION) $(MOUNT_DIRECTORY)

umnt:
	-umount $(MOUNT_PARTITION)

run:
	-qemu-system-x86_64 $(BOOT_DEVICE) -m 1536M
	
clean:
	-rm -r targets obj
	
all: clean mnt install umnt run
	
include drive.mk
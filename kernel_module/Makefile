
# obj-m instructs to build my_mod.c into kernel module (my_mod.ko)
# obj-y instructs to build source codes into embedded part of kernel binary
# obj-n instructs not to include source codes to build

# CONFIG_MYMOD should come from Kconfig.
CONFIG_MYMOD = m
obj-$(CONFIG_MYMOD) := my_mod.o

doxygen:
	doxygen *.c *.h


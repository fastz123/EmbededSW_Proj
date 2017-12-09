DIRS = lib anothergui/build-gui-Desktop_Qt_5_9_3_GCC_64bit-Debug anothergui/build-gui-Desktop_Qt_5_8_0_GCC_64bit-Debug

.PHONY: all clean

all:
	@for d in $(DIRS); \
	do \
		$(MAKE) -C $$d; \
	done

clean:
	@for d in $(DIRS); \
	do \
		$(MAKE) -C $$d clean; \
	done


UNAME_STRING := $(shell /bin/uname -a)
MY_VAR := UNAME_STRING2
all:
	@echo "(shell) -> $(UNAME_STRING)"
	$(eval $(MY_VAR) := $(UNAME_STRING))
	@echo "(eval) -> $(UNAME_STRING2)" 

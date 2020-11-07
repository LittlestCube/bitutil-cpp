all:
	@$(MAKE) -s --no-print-directory -f Makefile.unix

clean:
	@$(MAKE) -s --no-print-directory -f Makefile.unix clean
	
test:
	@$(MAKE) -s --no-print-directory -f Makefile.unix test

3ds:
	@$(MAKE) -s --no-print-directory -f Makefile.3ds
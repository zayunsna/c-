FORCE = root
CFLAGS = -W -Wall
#TARGET = gogo_exe
OBJECTS = data.cpp
INCLUDES = $(shell root-config --cflags)
SRCS = $(OBJECTS1:.o=.C) $(OBJECTS2:.o=.C)

all : DATA

DATA :$(OBJECTS)
	@echo
	@echo
	@echo
	@echo "*****************************************************************"
	@echo " "
	@echo "                           Data Reduction                       "
	@echo " "
	@echo "*****************************************************************"
	@echo
	@echo
	@echo
	$(FORCE) $(CFLAGS) $(INCLUDES) -o data $(OBJECTS)



clean :
	rm Dom_*.txt

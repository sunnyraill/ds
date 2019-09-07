#maintainer : sunny
prefix = /usr/local
prefix2 = /usr
# define any compile-time flags
CFLAGS := -g -Wall -std=c++11
# define the C compiler to use
CC := g++
RM := /bin/rm -f
# define any directories containing header files other than /usr/include# define any directories containing header files other than /usr/include#
INCLUDES := -Iinclude -I${prefix}/include -I${prefix}/include/opencv4 -I${prefix}/include/leptonica -I${prefix}/include/tesseract

# define library paths in addition to /usr/lib
#   if I wanted to include libraries not in /usr/lib I'd specify
#   their path using -Lpath, something like:
LFLAGS := -L${prefix}/lib -L${prefix}/lib64 -L${prefix2}/lib

# define any libraries to link into executable:
#   if I want to link in lib -lopencv_core -lopencv_highgui
#   option, something like (this will link in libmylib.so and libm.so:
#LIBS = -ltesseract -lpthread -lopencv_core -lopencv_highgui -lopencv_imgcodecs -lopencv_objdetect -lopencv_flann -lopencv_features2d -lopencv_imgproc

# define source files
AH_SRC := $(sort $(wildcard source/*.cpp))
# define the C object files
#
# This uses Suffix Replacement within a macro:
#   $(name:string1=string2)
#         For each word in 'name' replace 'string1' with 'string2'
# Below we are replacing the suffix .c of all words in the macro SRCS
# with the .o suffix
OBJS := $(AH_SRC:.cpp=.o)
#OBJS := $(AH_SRC:.cpp=.o)
#OBJS :
#	$(CC) $(CFLAGS) $(INCLUDES) -c $<

# define the executable file
MAIN = sunny.exe


#
# The following part of the makefile is generic; it can be used to
# build any executable just by changing the definitions above and by
# deleting dependencies appended to the file from 'make depend'
#

.PHONY: depend clean

all:    $(MAIN)
	@echo  Simple compiler named autohyperlink has been compiled

$(MAIN): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)

# this is a suffix replacement rule for building .o's from .c's
# it uses automatic variables $<: the name of the prerequisite of
# the rule(a .c file) and $@: the name of the target of the rule (a .o file)
# (see the gnu make manual section about automatic variables)
.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) source/*.o *~ $(MAIN)

depend: $(SRCS)
	makedepend $(INCLUDES) $^


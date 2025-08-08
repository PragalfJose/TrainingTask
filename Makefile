# Variables 
# Compiler
CC = gcc

# Cross compiler
CROSS_CC = aarch64-linux-gnu-${CC}

# List of all sub directories
SUBDIR = . appTimer appLed Console fileHandler possixHandler possixOperation
# List of all include directories with header file
INCDIR = .	\
		appTimer	\
		appLed	\
		Console	\
		fileHandler	\
		possixOperation	\
		possixHandler	\
		Common
# Dependency Flags
# DEPFLAGS = -MP -MD  $(DEPFLAGS)
# Flags with include path
CFLAGS = -Wall -Werror -Wextra $(foreach D,$(INCDIR),-I$(D))
MAPFLAG = -Wl,-Map=ProjectConsole.map
RPI_FLAGS = -I system -D_RPIBOARD
RPI_LIBS = -L system/lib -lgpiod

# Make a list of C source files in project
# foreach will iterate through SUBDIR and find all .c file
SOURCE = $(foreach D,$(SUBDIR),$(wildcard $(D)/*.c))
file_names = $(notdir $(SOURCE))

# OBJECTS list can be generated from SOURCE_FILES using patsubst
# OBJECTS = main.o appTimer/appTimer.o appLed/appLed.o Console/Console.o
OBJECTS = $(patsubst %.c,Release/%.o,$(file_names))

# Create dependency files incase headers changed
DEPND_FILES = $(patsubst %.c,%.d,$(SOURCE_FILES))

# Create assembly file List
ASSEMBLY_FILES = $(patsubst %.c,Release/%.s,$(file_names))

VPATH = .:appTimer:appLed:Console:Common:fileHandler:possixHandler:possixOperation

# Target : Dependencies
# Specify the rule for Dependencies
all : Linux Rpi

# Here Linux build depend on 4 different files
# So we need to define rules for each one of these
# Instead make a list of all these dependencis and use the list

# Linux : main.o appTimer/appTimer.o appLed/appLed.o Console/Console.o

# $@ will substitute output name with Target
# $^ will replaced with first dependency name 
# $< only use c Dependencies
#Linux : CreateRelease CreateDebug Assembly Executable Object Debug
Linux : CreateRelease CreateDebug Debug Assembly Object Executable

# Build Raspberry Pi output
# Build using cross compiler
# Store target in Release folder
# Rpi	: CreateRelease
#	$(CROSS_CC) 

# Need to define rules for OBJECTS
# $(CC) $(notdir $^) -o Release/LinuxOutput Need to explore
Object : $(OBJECTS)
	$(CC) $^ -o Release/LinuxObject

# OBJECTS or .o files depend on source or .c files
# Need a rule for every .o file
# Instead of wriring all of them use %
# % operator is a wildcard means any one in list 
# Expression means anyone with .o will have dependency on corresponding .c
# $(CC) $(CFLAGS) -g $< -o Debug/$(notdir $@)
Release/%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

# Need to define rules for ASSEMBLY
Assembly : $(ASSEMBLY_FILES)
	$(CC) $(CFLAGS) $^ -o Release/LinuxAssembly

# ASSEMBLY or .s files depend on source or .c files
# Need a rule for every .s file
# Expression means anyone with .o will have dependency on corresponding .c
Release/%.s : %.c
	$(CC) $(CFLAGS) -S $^ -o $@

# Need to define rules for Debug
Debug : CreateDebug
	$(CC) $(CFLAGS) -g $(SOURCE) -o Debug/LinuxDebug

# Need to define rules for Executable
Executable : $(SOURCE) CreateRelease
	$(CC) $(CFLAGS) $(SOURCE) $(MAPFLAG) -o Release/LinuxRelease
	size Release/LinuxRelease

# Create folder named Release using mkdir
CreateRelease :
	mkdir -p Release

# Create folder named Debug using mkdir
CreateDebug : 
	mkdir -p Debug

Rpi : CreateRelease
	$(CROSS_CC)	\
	$(CFLAGS)	\
	$(RPI_FLAGS)	\
	$(SOURCE)	\
	$(RPI_LIBS)	\
	-o Release/ProjectRpi

# Clean is needed to clean everything 
# Includes rules to remove and clear
.PHONY = clean
clean : 
	rm -f main
	find . -type f -name "*.o" -delete
	find . -type f -name "*.d" -delete
	find . -type f -name "*.s" -delete
	find . -type f -name "*.exe" -delete
	find . -type f -name "*.map" -delete
	rm -r Release
	rm -r Debug
	
# Include Dependencies
# -include $(DEPND_FILES)
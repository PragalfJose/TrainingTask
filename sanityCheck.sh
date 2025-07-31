# Sample bash file
# Commands included to clone or pull a repo given in source to the 
# target and build it.
# If repo doesn't exixt in target location it will clone repo
# If repo exist in target location it will pull latest repo
# Static analysis usinf cppcheck and log stored in Report folder
# Memory leak check using Valgrind. Log stored in Report
 
#!/usr/bin/bash

NumberOfArguments=2
RepoName="ProjectConsole"

# Check Arguments
if [[ $# -lt NumberOfArguments ]] ; then
    echo "Invalid command"
    echo "${0} <target> <repo_url>"
    exit 1
else
    echo "Target : ${1}"
    echo "Source : ${2}"
fi

# Get target address and source
Target=$1
Source=$2

# Change directory to previous directory
cd ${Target}

if  ls -l | grep "${RepoName}" ; then
    # pull if repo exist
    cd ${RepoName}
    git pull origin develop
else 
    # Clone repo from git
    git clone -b develop ${Source}
    # Move to project folder
    cd ProjectConsole
fi

# Make directory for error report
mkdir Report

# clean the project 
make clean
rm -r build

# cuild the project
# make all
cmake -B build && cmake --build build

# To static analysis
cppcheck --enable=all --output-file=Report/CppCheck_report.txt \
    main.c appTimer/appTimer.c appLed/appLed.c Console/Console.c \
    -I appTimer -I appLed -I Console -I Common

# Memory leak check
valgrind --leak-check=full \
    --show-leak-kinds=all \
    --track-origins=yes \
    --log-file=Report/Valgrind_report.txt \
    ./Debug/Project_Debug
# HENGEX Lib

High Enerdy Physics Tools 

# Building 
## Requirements
* cmake =< 3.7
* ROOT

## Compiling
* Load the any version of ROOT into the environmet from CMS env, $ROOTSYS/bin/thisroot.sh or cvmfs ex:
``` sh
. /cvmfs/sft.cern.ch/lcg/contrib/gcc/4.8/x86_64-centos7-gcc48-opt/setup.sh
. /cvmfs/sft.cern.ch/lcg/app/releases/ROOT/6.10.08/x86_64-centos7-gcc48-opt/root/bin/thisroot.sh
```
* create a directory build and run cmake:
``` sh
mkdir build
cd build
cmake ..
```
* compile it using make, where n is the number of jobs
``` sh
make -j n
```
* load the lib env 
``` sh
source thishlib.sh
```

## List of tools

### Harry Plotter
Tool to create plots from different files in multiples paths,
you can map the TTrees objects in chains and create histograms for multiples categories(Signal, Background0, etc..)
for the same branch.

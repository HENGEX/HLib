# HENGEX Lib

High Energy Physics Tools 

# Building 
## Requirements
* cmake 
* ROOT

## Compiling
* Load the any version of ROOT into the environmet from CMS env, $ROOTSYS/bin/thisroot.sh or cvmfs ex:

For lxplus 7
``` sh
. /cvmfs/sft.cern.ch/lcg/contrib/gcc/4.8/x86_64-centos7-gcc48-opt/setup.sh
. /cvmfs/sft.cern.ch/lcg/app/releases/ROOT/6.10.08/x86_64-centos7-gcc48-opt/root/bin/thisroot.sh
```
For lxplus 6
``` sh
. /afs/cern.ch/sw/lcg/external/gcc/4.9/x86_64-slc6-gcc49-opt/setup.sh
. /afs/cern.ch/sw/lcg/app/releases/ROOT/6.06.08/x86_64-slc6-gcc49-opt/root/bin/thisroot.sh
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

# Mounting EOS filesystem at HOME
``` sh
export EOS_MGM_URL=root://eoscms.cern.ch
export EOS_FUSE_MGM_ALIAS=eoscms.cern.ch
mkdir ~/eos
eos fuse mount ~/eos/

```
Wiki at [https://twiki.cern.ch/twiki/bin/view/EOS/AccessingEosNotUsingLxplus](https://twiki.cern.ch/twiki/bin/view/EOS/AccessingEosNotUsingLxplus)

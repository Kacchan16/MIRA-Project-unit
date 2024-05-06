
# MIRA Project

Welcome to readme file of this project. In this project, we are setting up the environemnt. In one unit, publishing the Fibonacci seqeunce on to integer channel.
In this Project, 


## Installation from source

The MIRA source code can be downloaded from here [ download. ]( https://www.mira-project.org/downloads/ )
Download the recent version of source archieve, unpack and compile it.

```bash
> tar xzvf MIRA-2023-12-15_r10375.tar.gz  #I used this version

> sudo apt-get install qt5-default libqwt-qt5-dev libqt5webkit5-dev libqwtmathml-qt5-dev libqt5opengl5-dev libqt5svg5-dev qt*5-dev qttools5-dev-tools git

> cd MIRA
> export MIRA_PATH=/home/venkata/MIRA
> export LD_LIBRARY_PATH=/home/venkata/MIRA/lib
> make release

```

By reaching this command, we completed installing Mira into our workspace.
To check Mira is setup or not type *mirawizard* in the terminal. GUI should open, if it didn't open few dependencies might be missing.

## Setting up the Workspace

To install some of the missing dependencies, follow these steps one by one.

```bash
> bash mira-installer-binary.sh 
> sudo apt update
> sudo apt-get --fix-missing
> sudo apt-get install g++ cmake subversion doxygen libxml2-dev libssl-dev libsqlite3-dev libboost-all-dev libogre-1.9-dev libsvn-dev libopencv-dev binutils-dev libiberty-dev libcurl4-gnutls-dev libprocps-dev
> sudo apt-get install qt4-dev-tools libqt4-dev libqt4-opengl-dev libqtwebkit-dev libqwt5-qt4-dev
> ./mira-installer-binary.sh SystemName
```
And finally source the workspace

```bash
export PATH=$PATH:/home/venkata/MIRA/bin
source /home/venkata/MIRA/scripts/mirabash

```

## Creating Project, Domain and a Unit

Type mirawizard in the terminal, GUI will open
```bash
mirawizard
```
In the GUI, Select the *Create a new External Project* and then Write the name and description of project and commit it.

We created our Project, now we have create one domain. For that type mirawizard in the terminal, GUI will open

Select the *Create a new Domain* and write the name, description, author, and tags and commit it.

Now we have to create a Unit, which will publish the message into the channel for every time interval.

Same thing again, type mirawizard in the terminal, GUI will open
Select the *Create a new component* and then select the type *unit* , give the name, namespace and the path.

The default code will be generates in C++ in the "domains/Fibonacci/src/FibonacciProducer.C"


Here we have to make some necessary changes required for our code and write the logic, here I wrote for the Fibonacci Sequence.

After writing the code, add few lines to CMakeLists.txt of our domain:
```bash
MIRA_ADD_LIBRARY(FibonacciProducer
    SHARED
    PACKAGE Fibonacci
    SOURCE
        src/FibonacciProducer.C
    LINK_LIBS
        MIRABase
        MIRAFramework
)
```

It will tell our build system to create a new shared library from our source file.

Then make

## Launching the Unit

To start our new unit, we need to create a launch configuration file, This xml file that specifies the Units that shall be instantiated and started.

The configuration file is located in *Fibonacci/etc/FibonacciProducer.xml*
```bash
<root>
    <unit id="MyFibonacciProducer" class="Sequence::FibonacciProducer"/>
</root>
```


we can start out unit by typing:
```bash
> mira domains/Fibonacci/etc/FibonacciProducer.xml

```
Our unit will ask the *how many number of Fibonacci Seqenece* is required, after that it will be publishing the Fibonacci Sequence into the channel for every time interval.

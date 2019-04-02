#!/bin/bash
mkdir make -p       # creation d'un repertoire de compilation
cd make
cmake ..            # configuration du rojet avec le CMakeLists.txt
make                # compilation du projet
cd ..



#to give rights to the file
#sudo chmod u+x build.sh

## compiler : ./build.sh
## executer : ./make/ex_platooning
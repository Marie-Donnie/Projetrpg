#!/bin/sh
mkdir obj
mkdir bin
sudo apt-get install libboost-dev
wget http://www.sfml-dev.org/files/SFML-2.3.2-sources.zip
unzip SFML-2.3.2-sources.zip
mv SFML-2.3.2 SFML
rm SFML-2.3.2-sources.zip
cd SFML
sudo apt-get build-dep libsfml
sudo apt-get install libxcb1-dev libx11-xcb-dev libxcb-randr0-dev libxcb-image0 libflac-dev libogg-dev libvorbis-dev libvorbisenc2 libvorbisfile3
mkdir build
cd build
cmake -G "Unix Makefiles" ..
make
cd ..
ln -s build/lib lib
cd ..
wget https://github.com/texus/TGUI/archive/v0.6.9.zip
unzip v0.6.9.zip
mv TGUI-0.6.9 TGUI
rm v0.6.9.zip
cd TGUI
mkdir build
cd build
cmake -D 'SFML_ROOT:PATH=../SFML' -G "Unix Makefiles" ..
make
cd ..
ln -s build/lib lib

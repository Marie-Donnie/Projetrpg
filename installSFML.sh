wget http://www.sfml-dev.org/files/SFML-2.3.2-sources.zip
unzip SFML-2.3.2-sources.zip
mv SFML-2.3.2 SFML
rm SFML-2.3.2-sources.zip
cd SFML
sudo apt-get build-dep libsfml
mkdir build
cd build
cmake .. -G "Unix Makefiles"
make

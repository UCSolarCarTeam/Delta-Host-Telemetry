git clone git://code.qt.io/qt/qtserialport.git
cd qtserialport
git checkout qt5.4.1
cd ..
mkdir qtserialport-build
cd qtserialport-build
qmake ../qtserialport/qtserialport.pro
make
sudo make install
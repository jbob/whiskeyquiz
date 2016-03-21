CC=g++
CCFLAGS=-Wall
INCL=-I/usr/include/qt4
LDFLAGS=-lxerces-c -lQtGui -lusb
OUT=-owhiskeyquiz
SRC=main.cpp questiondb.cpp questionhandler.cpp gui.cpp sound.cpp WGame.cpp


all:
	$(CC) $(CCFLAGS) -O2 $(INCL) $(LDFLAGS) $(SRC) k8055.o $(OUT) 

dummy:
	$(CC) $(CCFLAGS) -O0 -g $(INCL) $(LDFLAGS) $(SRC) k8055.cpp $(OUT)

install:
	install -d /opt/usr/bin
	install --mode=755 whiskeyquiz /opt/usr/bin/
	install -d /opt/usr/share/pixmaps
	install --mode=755 pixmaps/* /opt/usr/share/pixmaps
	install -d /opt/usr/share/sounds
	install --mode=755 sounds/* /opt/usr/share/sounds
	install -d /opt/usr/etc
	install --mode=755 questions.xml /opt/usr/etc/questions.xml

uninstall:
	rm /opt/usr/bin/whiskeyquiz
	rm /opt/usr/share/pixmaps/bottle.png
	rm /opt/usr/share/sounds/beam.wav
	rm /opt/usr/share/sounds/drama.wav
	rm /opt/usr/share/sounds/kongas.wav
	rm /opt/usr/share/sounds/laser.wav
	rm /opt/usr/share/soudns/left.wav
	rm /opt/usr/etc/questions.xml

package:
	checkinstall --pkgname "whiskeyquiz" --pkgversion "20081210" --pkgrelease "1" --pkglicense "GPL" --pkggroup "games" --pkgsource "http://kochmarkus.lima-city.de/wiki/doku.php?id=studium:rechnerperepherie:programm" --maintainer "Markus Koch \(koch_markus@gmx.de\)" --requires "libusb-0.1-4, alsa-utils, libxerces27 \| libxerces28, libqt4-gui" --nodoc

clean:
	rm whiskeyquiz 
	rm -r doc

doc: *.h *.cpp
	doxygen

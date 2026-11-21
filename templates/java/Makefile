JAVAC := javac
JAVA := java
JAVACFLAGS := --release 21 -encoding UTF-8
JAVAFLAGS := -Dfile.encoding=UTF-8

.PHONY: build run

build: Main.class

Main.class: Main.java
	$(JAVAC) $(JAVACFLAGS) $<

run: Main.class
	$(JAVA) $(JAVAFLAGS) -cp . Main

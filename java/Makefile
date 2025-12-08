SRC := src
OUT := out
JAVAC := javac
JAVA := java
SOURCES := $(shell find $(SRC) -name "*.java")

MAIN ?= pubsub.entities.Message

.PHONY: all build run clean

all: build

build:
	@mkdir -p $(OUT)
	$(JAVAC) -d $(OUT) $(SOURCES)

run: build
	$(JAVA) -cp $(OUT) $(MAIN)

clean:
	rm -rf $(OUT)

PYTHON := pypy3

.PHONY: build run

build: main.py
	$(PYTHON) -m py_compile $<

run: main.py
	$(PYTHON) $<

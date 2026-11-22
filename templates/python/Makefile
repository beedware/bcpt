PYTHON := pypy3
PROGRAM = $(PYTHON) main.py

.PHONY: build run

build: main.py
	$(PYTHON) -m py_compile $<

ifneq ($(filter run,$(MAKECMDGOALS)),)
TEST := $(filter-out build run,$(MAKECMDGOALS))
endif

ifeq ($(TEST),)
run: main.py
	$(PROGRAM)
else
NON_DIGITS := $(subst 0,,$(subst 1,,$(subst 2,,$(subst 3,,$(subst 4,,$(subst 5,,$(subst 6,,$(subst 7,,$(subst 8,,$(subst 9,,$(TEST)))))))))))
ifneq ($(words $(TEST)),1)
$(error Use make run N with one test number)
endif
ifneq ($(NON_DIGITS),)
$(error Test number must contain only digits)
endif

.PHONY: $(TEST) check-test
$(TEST): ; @:

RUN_TEST = $(PROGRAM) 2>>err/$(TEST) <in/$(TEST)

check-test:
	@test -f in/$(TEST) || { echo "Missing in/$(TEST)" >&2; exit 1; }
	@mkdir -p err
	@: >err/$(TEST)

run: main.py | check-test
	@if [ -f out/$(TEST) ]; then \
		actual=$$(mktemp) && trap 'rm -f "$$actual"' EXIT && \
			$(RUN_TEST) >"$$actual" && diff --color=auto -u out/$(TEST) "$$actual"; \
	else \
		$(RUN_TEST); \
	fi
endif

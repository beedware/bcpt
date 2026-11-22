JAVAC := javac
JAVA := java
JAVACFLAGS := --release 21 -encoding UTF-8
JAVAFLAGS := -Dfile.encoding=UTF-8
PROGRAM = $(JAVA) $(JAVAFLAGS) -cp . Main

.PHONY: build run

build: Main.class

Main.class: Main.java
	$(JAVAC) $(JAVACFLAGS) $< $(TEST_STDERR)

ifneq ($(filter run,$(MAKECMDGOALS)),)
TEST := $(filter-out build run,$(MAKECMDGOALS))
endif

ifeq ($(TEST),)
run: Main.class
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

TEST_STDERR := 2>>err/$(TEST)
RUN_TEST = $(PROGRAM) $(TEST_STDERR) <in/$(TEST)

check-test:
	@test -f in/$(TEST) || { echo "Missing in/$(TEST)" >&2; exit 1; }
	@mkdir -p err
	@: >err/$(TEST)

Main.class: | check-test
.SILENT: Main.class

run: Main.class
	@if [ -f out/$(TEST) ]; then \
		actual=$$(mktemp) && trap 'rm -f "$$actual"' EXIT && \
			$(RUN_TEST) >"$$actual" && diff --color=auto -u out/$(TEST) "$$actual"; \
	else \
		$(RUN_TEST); \
	fi
endif

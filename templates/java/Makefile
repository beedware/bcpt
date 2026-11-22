JAVAC := javac
JAVA := java
JAVACFLAGS := --release 21 -encoding UTF-8
JAVAFLAGS := -Dfile.encoding=UTF-8
PROGRAM = $(JAVA) $(JAVAFLAGS) -cp . Main

.PHONY: build run validate

build: Main.class

Main.class: Main.java
	$(JAVAC) $(JAVACFLAGS) $< $(TEST_STDERR)

TEST_ACTION := $(filter run validate,$(MAKECMDGOALS))
ifneq ($(TEST_ACTION),)
TEST := $(filter-out build run validate,$(MAKECMDGOALS))
endif

ifeq ($(TEST),)
ifeq ($(TEST_ACTION),validate)
$(error Usage: make validate N)
endif
run: Main.class
	$(PROGRAM)
else
NON_DIGITS := $(subst 0,,$(subst 1,,$(subst 2,,$(subst 3,,$(subst 4,,$(subst 5,,$(subst 6,,$(subst 7,,$(subst 8,,$(subst 9,,$(TEST)))))))))))
ifneq ($(words $(TEST_ACTION) $(TEST)),2)
$(error Use make run N or make validate N with one test number)
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
ifeq ($(TEST_ACTION),validate)
	@test -f out/$(TEST) || { echo "Missing out/$(TEST)" >&2; exit 1; }
endif
	@mkdir -p err
	@: >err/$(TEST)

Main.class: | check-test
.SILENT: Main.class

run: Main.class
	@$(RUN_TEST)

validate: Main.class
	@actual=$$(mktemp) && trap 'rm -f "$$actual"' EXIT && \
		$(RUN_TEST) >"$$actual" && diff -u out/$(TEST) "$$actual"
endif

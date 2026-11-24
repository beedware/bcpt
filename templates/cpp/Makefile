CXX := g++
CXXFLAGS := -O2 -g -Wall -Wextra -Wshadow -Wfatal-errors -std=gnu++23 -fsanitize=address,undefined -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC
PROGRAM := ./main.out

.PHONY: build run

build: main.out

main.out: main.cpp
	$(CXX) $(CXXFLAGS) $< -o $@ $(TEST_STDERR)

ifneq ($(filter run,$(MAKECMDGOALS)),)
TEST := $(filter-out build run,$(MAKECMDGOALS))
endif

ifeq ($(TEST),)
run: main.out
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

main.out: | check-test
.SILENT: main.out

run: main.out
	@if [ -f out/$(TEST) ]; then \
		actual=$$(mktemp) && trap 'rm -f "$$actual"' EXIT && \
			$(RUN_TEST) >"$$actual" && diff --color=auto -u out/$(TEST) "$$actual"; \
	else \
		$(RUN_TEST); \
	fi
endif

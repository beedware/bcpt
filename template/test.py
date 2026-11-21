"""Run every *.in in the current directory. Usage: pypy3 test.py [command ...]"""

import difflib
import subprocess
import sys
from pathlib import Path


def show(label, text):
    print(f"--- {label} ---")
    print(text, end="" if text.endswith("\n") else "\n")


def main():
    command = sys.argv[1:] or ["./build"]
    cases = sorted(Path(".").glob("*.in"))
    if not cases:
        print("No .in files found in the current directory.", file=sys.stderr)
        return 1

    failed = False
    for case in cases:
        print(f"\n=== {case.name} ===")
        data = case.read_text()
        show("Input", data)
        try:
            result = subprocess.run(command, input=data, capture_output=True, text=True)
        except OSError as error:
            print(f"Could not run {command[0]}: {error}", file=sys.stderr)
            return 1

        show("Output", result.stdout)
        if result.stderr:
            show("Stderr", result.stderr)
        if result.returncode:
            print(f"FAIL: program exited with status {result.returncode}")
            failed = True

        expected_file = case.with_suffix(".out")
        if not expected_file.is_file():
            if not result.returncode:
                print(f"UNCHECKED: no {expected_file.name}")
            continue

        expected = expected_file.read_text()
        if result.stdout == expected:
            if not result.returncode:
                print("PASS")
            continue

        print("FAIL: output differs")
        failed = True
        for line in difflib.unified_diff(
            expected.splitlines(keepends=True),
            result.stdout.splitlines(keepends=True),
            fromfile=expected_file.name,
            tofile="actual",
        ):
            if line.endswith("\n"):
                print(line, end="")
            else:
                print(f"{line}\n\\ No newline at end of file")

    return int(failed)


if __name__ == "__main__":
    sys.exit(main())

#!/bin/python3
import random
import sys
import subprocess

def generate_unique_numbers(n):
    """Generate a list of unique integers of size n."""
    if n > 1_000_000:  # Adjust the limit based on your requirements
        raise ValueError("n is too large. Please choose a smaller number.")
    range_limit = n * 2  # Ensure sufficient range for uniqueness
    numbers = random.sample(range(-range_limit, range_limit + 1), n)
    return numbers

def print_result(str, nlen, n):
    if (n <= 100 and nlen <= 700) or ((n > 100 and n <= 500) and nlen <= 5500):
        print(f"{str}: \033[32m{nlen}\033[0m")
    elif (n <= 100 and nlen <= 800) or ((n > 100 and n <= 500) and nlen <= 6000):
        print(f"{str}: \033[33m{nlen}\033[0m")
    else:
        print(f"{str}: \033[31m{nlen}\033[0m")

def execute(test_string, n):
    try:
        push_swap_output = subprocess.check_output(
            f'./push_swap {test_string}', shell=True, text=True
        ).strip()
        nlen = len(push_swap_output.split("\n"))
        print_result("push swap    ", nlen, n)
        if n == 500 and nlen < 5500:
            return 1
        elif n == 100 and nlen < 700:
            return 1
        return 0
    except subprocess.CalledProcessError as e:
        print(f"Error executing ./push_swap: {e}")

def execute_c(test_string, n):
    try:
        push_swap_output = subprocess.check_output(
            f'./push_swap {test_string} | ./checker {test_string}', shell=True, text=True
        ).strip()
        if (push_swap_output == "OK"):
            print(f"test {n}: \033[32m{push_swap_output}\033[0m")
            return 1
        else:
            print(f"test {n}: \033[31m{push_swap_output}\033[0m")
            return 0
    except subprocess.CalledProcessError as e:
        print(f"Error executing ./push_swap: {e}")

def test_all():
    n = 100
    for _ in range(100):
        unique_numbers = generate_unique_numbers(n)
        test_string = " ".join(map(str, unique_numbers))
        execute(test_string, n)
        print("----------------------------\n")


    n = 500
    for _ in range(100):
        unique_numbers = generate_unique_numbers(n)
        test_string = " ".join(map(str, unique_numbers))
        execute(test_string, n)
        print("----------------------------\n")


def main():
    if len(sys.argv) < 2:
        test_all()
        sys.exit(0)
    
    if sys.argv[1] == "-o":
        try:
            n = int(sys.argv[2])
            unique_numbers = generate_unique_numbers(n)
            test_string = " ".join(map(str, unique_numbers))
            print(test_string)
            sys.exit(0)
        except ValueError as e:
            print(f"Invalid input: {e}")
            sys.exit(1)

    if sys.argv[1] == "-c":
        try:
            n = int(sys.argv[2])
            unique_numbers = generate_unique_numbers(n)
            test_string = " ".join(map(str, unique_numbers))
            # execute(test_string, n)
            x = 0
            for i in range(1, 101):
                unique_numbers = generate_unique_numbers(n)
                test_string = " ".join(map(str, unique_numbers))
                x = x + execute_c(test_string, i)
                print("-------------------")

            print(f"Success rate: {x}%")
            sys.exit(0)
        except ValueError as e:
            print(f"Invalid input: {e}")
            sys.exit(1)


    try:
        n = int(sys.argv[1])
        if n <= 0:
            raise ValueError("n must be a positive integer.")
    except ValueError as e:
        print(f"Invalid input: {e}")
        sys.exit(1)
    m = 100
    if len(sys.argv) > 2:
        m = int (sys.argv[2])

    x = 0
    for _ in range(m):
        unique_numbers = generate_unique_numbers(n)
        test_string = " ".join(map(str, unique_numbers))
        x = x + execute(test_string, n)
        print("-------------------")

    print(f"Success rate: {x * 100 / m}%")

if __name__ == "__main__":
    main()

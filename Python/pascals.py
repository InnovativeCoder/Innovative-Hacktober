import time, functools

# Functions for finding pascals & centering strings
center = lambda string, length : ' ' * (length - (len(string) // 2))  + string
pascal = lambda x, y : 1 if (y == x or x == 1 or y == 1) else pascal(x - 1, y - 1) + pascal(x, y - 1)
pascal = functools.lru_cache(maxsize=None)(pascal) # caching performance magic

# Return a multi-line string depicting a properly centered Pascal Triangle
def triangle(layers):
    string = [' '.join(str(pascal(x, y)) for x in range(1, y + 1)) for y in range(1, layers + 1)]
    largest = len(string[-1]) // 2
    return '\n'.join(map(functools.partial(center, length=largest), string))

# Print & time a pascal triangle 25 layers deep
x1 = time.time();x = triangle(25);x2 = time.time();print(x)
print(f'Processed in {round(x2 - x1, 3)}s.')
import numpy as np

def get_min_max_vector(vector):
    minElement = np.amin(vector)
    maxElement = np.amax(vector)
    return minElement, maxElement

vector = [1, 10, 0, -3, 100]
min, max = get_min_max_vector(vector)

print('Vector: ', vector)
print('Minimum value: ', min)
print('Maximum value: ', max)

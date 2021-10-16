import random

def generate_list(size, minimum, maximum):

    array = []

    for _ in range(size):
        array.append(random.randint(minimum, maximum))

    return array

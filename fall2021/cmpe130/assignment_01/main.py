from datetime import datetime
import generate_list as gl
import sorts
import matplotlib
import matplotlib.pyplot as plt



input_size = [10, 50, 100, 300, 500, 1000, 2000, 5000, 10000, 50000]

def insertion_timing(input_size, minimum, maximum):
    timings = []
    
    for size in input_size:
        array = gl.generate_list(size, minimum, maximum)
        time_01 = datetime.now()
        sorts.insertion_sort(array, len(array))
        time_02 = datetime.now()
        time_diff = time_02 - time_01
        timings.append(time_diff)
    
    return timings

def merge_timing(input_size, minimum, maximum):
    timings = []

    for size in input_size:
        array = gl.generate_list(size, minimum, maximum)
        time_01 = datetime.now()
        sorts.merge_sort(array, 0, size - 1)
        time_02 = datetime.now()
        time_diff = time_02 - time_01
        timings.append(time_diff)

    return timings

merge_result = merge_timing(input_size, 0, 1000)
print (merge_result)
insertion_result = insertion_timing(input_size, 0, 1000)
print (insertion_result)

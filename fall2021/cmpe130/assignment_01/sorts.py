
def insertion_sort(array, size):

    for i in range(1, size):
        key = array[i]
        j = i
        while j > 0 and array[j - 1] > key:
            array[j] = array[j - 1]
            j -= 1
        array[j] = key


def merge(array, start, mid, end):
    array_left = array[start:mid + 1]
    array_right = array[mid + 1:end + 1]
    left = len(array_left)
    right = len(array_right)
    i = j = 0
    for k in range(end - start + 1):
        if i != left and j == right:            #if left array is exhausted but right is not
            array[start + k] = array_left[i]
            i += 1
        elif i == left and j != right:          #if right array is exhausted but left is not
            array[start + k] = array_right[j]
            j += 1
        elif array_left[i] <= array_right[j]:
            array[start + k] = array_left[i]
            i += 1
        else:
            array[start + k] = array_right[j]
            j += 1

def merge_sort(array, start, end):
    if start < end:
        mid = (end + start) // 2
        merge_sort(array, start, mid)
        merge_sort(array, mid + 1, end)
        merge(array, start, mid, end)



def qs(array):
  if len(array) < 2:
    return array
  else:
    pivot = array[0]
    less = [i for i in array[1:] if i <= pivot]
    greater = [i for i in array[1:] if i > pivot]
    return qs(less) + [pivot] + qs(greater)

print qs([1, 4, 66, 2, 99])

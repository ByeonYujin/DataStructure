import heapq


# 최소힙 (내림차순)
# Min Heap (Descending)
def min_heapsort(iterable):
    h = []  # 힙 heap
    result = []  # 결과값(리스트) result(list)

    # iterable의 모든 요소를 차례대로 힙에 삽입한다.
    # insert all elements of iterable into the heap in turn.
    for value in iterable:
        heapq.heappush(h, value)

    # heap의 모든 요소를 result에 차례대로 삽입한다.
    # insert all elements of heap into the result in turn.
    for _ in range(len(h)):
        result.append(heapq.heappop(h))
    return result


# 최대 힙 (오름차순)
# 요소를 힙에 삽입하기 전, 요소의 부호를 반대로 바꾼다.
# 요소를 힙에서 꺼낸 후, 요소의 부호를 다시 바꾼다.
# Max Heap (Ascending)
# Before inserting an element into the heap, reverse the sign of element.
# After taking out element from the heap, reverse the sign of element again.
def max_heapsort(iterable):
    h = []  # 힙 heap
    result = []  # 결과값(리스트) result(list)

    # iterable의 모든 요소를 차례대로 힙에 삽입한다.
    # insert all elements of iterable into the heap in turn.
    for value in iterable:
        heapq.heappush(h, -value)

    # heap의 모든 요소를 result에 차례대로 삽입한다.
    # insert all elements of heap into the result in turn.
    for _ in range(len(h)):
        result.append(-heapq.heappop(h))
    return result


result = min_heapsort([1, 3, 5, 7, 9, 2, 4, 6, 8, 0])
print(result)

result = max_heapsort([1, 3, 5, 7, 9, 2, 4, 6, 8, 0])
print(result)

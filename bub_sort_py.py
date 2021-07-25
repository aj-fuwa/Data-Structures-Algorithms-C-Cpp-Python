"""
Name: bub_sort_py.py
Aim: To implement Bubble sort in Python
Date: 25.July 2021
"""

class SortClass():
    def bubble_sort(self, a):
        temp = 0
        for i in range(0, len(a)):
            for j in range(0, len(a)-i-1):
                if(a[j]>a[j+1]):
                    temp = a[j]
                    a[j] = a[j+1]
                    a[j+1] = temp
        return a
 

sort = SortClass()
a = [12, 11, 90, 65, 3]
print("Before Bubble Sort: ",a)
print("After Bubble Sort: ",sort.bubble_sort(a))

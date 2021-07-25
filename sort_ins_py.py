"""
Name: sort_ins_py.py
Aim: To implement Insertion Sort algorithm in Python
Date: 25.July 2021
"""
class SortClass():    # other sort methods will be implemented in this class
    def insertion_sort(self, a):
        i, j, key = 0, 0, 0
        for i in range(1, len(a)):
            key = a[i]
            j = i - 1
            while(j > -1 and key < a[j]):
                a[j + 1] = a[j]
                j = j - 1
            a[j + 1] = key
        return a
        
sort = SortClass()
a = [12, 11, 90, 65, 3]
print("Before Insertion Sort: ",a)
print("After Insertion Sort: ",sort.insertion_sort(a))

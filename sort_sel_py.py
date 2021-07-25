"""
Name: sort_sel_py.py
Aim: To implement Selection sort in Python
Date: 23.July 2021
"""
class SortClass():    # other sort methods will be implemented in this class
    def selection_sort(self, a):
        i,j, temp = 0,0,0
        for i in range(0, len(a)):
            for j in range(i, len(a)):
                if(a[i] > a[j]):
                    temp = a[i]
                    a[i] = a[j]
                    a[j] = temp
        return a
    

sort = SortClass()
a = [12, 11, 90, 65, 3]
print("Before Selection Sort: ",a)
print("After Selection Sort: ",sort.selection_sort(a))

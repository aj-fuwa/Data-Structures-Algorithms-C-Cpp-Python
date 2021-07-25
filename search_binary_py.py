"""
Name: search_binary_py.py
Aim: To implement the Binary Search algorithm in Python
Date: 25.July 2021
"""
class SearchClass():    # other search algorithms will be combined in the class
    def binary_search(self, a, element, low, high):
        if(high >= low):
            mid = (low + high) // 2
            if (a[mid] == element):
                return True
            elif (a[mid] > element):
                return self.binary_search(a, element, low, mid)
            elif (a[mid] < element):
                return self.binary_search(a, element, mid+1, high)
        else:
            return False
          
srch = SearchClass()
a = [1, 2, 3, 45, 89, 100]
if(srch.binary_search(a, 45, 0, len(a))):
    print("Element found")
else:
    print("Element not found")

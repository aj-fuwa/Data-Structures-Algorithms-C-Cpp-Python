'''
# Name: searching_algorithms.py
# Aim: To practice searching algorithms (Linear Search and Binary Search)
# Date: 26.Dec 2020
'''


# Class for Searching (Linear and Binary Search)
class Searching():
    def __str__(self):
        return "Search in linear or binary-search way on the list"

    def create_list(self, count):
        print("INFO: List creating with {} elements".format(str(count)))
        list2search = []
        for item in range(count):
            item = int(input("\tEnter the element:"))
            list2search.append(item)
        print("\nINFO: List created.")
        return list2search

    def linear_search(self, item2search):
        count = int(input("INFO: Creating a list...\n\tEnter the no of elements of the list:"))
        list2search = self.create_list(count)
        for item in list2search:
            if (item2search == item):
                print("\tElement {} found in the given list".format(item2search))
                return True
            else:
                pass
        return False

    def binary_search(self, item2search):
        count = int(input("INFO: Creating a list...\n\tEnter the no of elements of the list:"))
        list2search = self.create_list(count)
        ret_val = self.rec_bin_search(list2search, item2search, len(list2search), 0)
        if (ret_val == True):
            print("\tBinary Search found the element")
        elif (ret_val == False):
            print("\tBinary Search could not find the element")
        else:
            print("INFO: Something went wrong in Binary Search")

    def rec_bin_search(self, list2search, element, high, low):
        mid = (high + low) // 2
        if (high >= low):
            if (element == list2search[mid]):
                print("\t{} found in the list at position:{}".format(element, mid + 1))
                return True
            elif (element < list2search[mid]):
                return self.rec_bin_search(list2search, element, mid, 0)
            elif (element > list2search[mid]):
                return self.rec_bin_search(list2search, element, len(list2search) - 1, mid + 1)
        else:
            print("\t{} not found in the list!".format(element))


# Main code
#search_obj = Searching()
#search_obj.linear_search(5)
#search_obj.binary_search(5)


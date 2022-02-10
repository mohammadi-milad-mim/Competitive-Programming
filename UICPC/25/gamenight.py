def sort012( a, arr_size, key1,key2,key3):
    lo = 0
    count = 0
    hi = arr_size - 1
    mid = 0
    while mid <= hi:
        if a[mid] == key1:
            if a[lo]!=a[mid]:
                a[lo], a[mid] = a[mid], a[lo]
                count+=1
            lo = lo + 1
            mid = mid + 1
        elif a[mid] == key2:
            mid = mid + 1
        elif a[mid] == key3:
            a[mid], a[hi] = a[hi], a[mid]
            count+=1
            hi = hi - 1
    return count

n = int(input())
st = list(input())
mi = 77777777777
mi = min(mi,sort012(st.copy(),n,'A','B','C'))
mi = min(mi,sort012(st.copy(),n,'A','C','B'))
mi = min(mi,sort012(st.copy(),n,'B','A','C'))
mi = min(mi,sort012(st.copy(),n,'B','C','A'))
mi = min(mi,sort012(st.copy(),n,'C','A','B'))
mi = min(mi,sort012(st.copy(),n,'C','B','A'))
print(mi)

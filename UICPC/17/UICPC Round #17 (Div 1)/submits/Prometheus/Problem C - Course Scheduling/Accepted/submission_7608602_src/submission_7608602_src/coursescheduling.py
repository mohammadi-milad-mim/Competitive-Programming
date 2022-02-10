
def ascii_value(key):
    sum =0
    for i in key:
        sum+=ord(i)

    return sum

n = int(input())
course = {}



for i in range(n):
    all = list(input().split(" "))

    if all[2] not in course:
        course[all[2]]=[]

    word = all[0] + all[1]
    # print(word)
    course[all[2]].append(word)

for k,v in course.items():
    course[k] = list(dict.fromkeys(v))


key_value = {}

# for k, v in course.items():
#     num_value = ascii_value(k)
#     key_value[num_value] = k

for k in sorted(course.keys(), ):
    # k = key_value[i]
    print(k, len(course[k]))




# print(course)

import sys


N = int(input())

Attendance = []
for _ in range(N):
    student = input().split()
    Attendance.append([student[0], int(student[1]), int(student[2]), int(student[3])])

Attendance.sort(key=lambda x: (-x[1], x[2], -x[3], x[0]))

for ordered_student in Attendance:
    print(ordered_student[0])

#!/usr/bin/python3
total, partial  = map(int, input().split())
jury_diff, team_diff = map(int, input().split())

rest = ((jury_diff * total) - (team_diff * partial)) / float(total - partial)
print('impossible' if rest < 0 or rest >= 100 else rest)

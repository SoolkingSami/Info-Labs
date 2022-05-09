class Show:
    def __init__(self, start, end):
        self.start = start
        self.end = end

    def __lt__(self, other):
        return self.end < other.end

    def __str__(self):
        return f"{self.start}-{self.end}"


activities = [Show(2, 4), Show(8, 11), Show(5, 6), Show(7, 8), Show(3, 7), Show(5, 8), Show(9, 12)]
activities.sort()

res = []
for activity in activities:
    if not res or res[-1].end <= activity.start:
        res.append(activity)

for activity in res:
    print(activity)

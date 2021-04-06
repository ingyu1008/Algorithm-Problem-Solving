import requests  # http 요청을 위한 모듈
import json  # json 파일을 다루기 위한 모듈

# 두 딕셔너리 병합

def getProblemId(problem):
    return json.loads(problem)["id"]

def merge(old, new):
    if len(old) == 0:
        return new

    for item in new["result"]["problems"]:
        old["result"]["problems"].append(item)

    return old


def calculateDiff(old, new):
    o = old["result"]["problems"]
    n = new["result"]["problems"]

    ptro = 0
    ptrn = 0

    diff = set()

    while ptro < len(o) or ptrn < len(n):
        a = 2147483647
        b = 2147483647

        if ptro < len(o) :
            a = getProblemId(o[ptro]) 
        if ptrn < len(n) :
            b = getProblemId(o[ptrn])

        if a >= b:
            ptrn += 1
        if a <= b:
            ptro += 1
        if a != b:
            diff.add(min(a,b))


# Database
class Database:
    DB = dict()

    # Read Old DB
    def readDB(self, file='database.json'):
        try:
            with open(file, 'r') as f:
                self.DB = json.load(f)
                f.close()
        except:
            print("No DB to read")

    # Write New DB
    def writeDB(self, file="database.json"):
        with open(file, 'w') as f:
            json.dump(self.DB, f, indent='\t')
            f.close()

    # Save All Solved Problems on DB
    def getSolvedProblems(self, userId="ingyu1008", page=1):
        total = 1

        while page <= total:
            URL = f"https://api.solved.ac/v2/search/problems.json?query=solved_by:{userId}&page={page}&sort=level&sort_direction=asc"
            res = requests.get(URL)

            if res.status_code == 200:
                self.DB = merge(self.DB, res.json())
                total = res.json()["result"]["total_page"]
                print(f"{page} pages out of {total} pages done")
                page += 1
            else:
                print(
                    f"Error occured while requesting {URL}, Error Code {res.status_code}")
                break


if __name__ == "__main__":
    oldDB = Database()
    oldDB.readDB()
    newDB = Database()
    newDB.getSolvedProblems()
    newDB.writeDB()

    calculateDiff(oldDB, newDB)

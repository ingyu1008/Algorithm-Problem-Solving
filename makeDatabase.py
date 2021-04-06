import requests  # http 요청을 위한 모듈
import json  # json 파일을 다루기 위한 모듈

# 두 딕셔너리 병합
def merge(old, new):
    if len(old) == 0:
        return new

    for item in new["result"]["problems"]:
        old["result"]["problems"].append(item)

    return old

# 문제 번호 반환 
def getProblemId(problem):
    return problem["id"]

# 새롭게 추가된 문제 확인
def calculateDiff(old, new):
    try:
        o = old.DB["result"]["problems"]
    except KeyError:
        o = []
    
    try:
        n = new.DB["result"]["problems"]
    except KeyError:
        n = []

    ptro = 0
    ptrn = 0

    diff = set()

    while ptro < len(o) or ptrn < len(n):
        a = 2147483647
        b = 2147483647

        if ptro < len(o):
            a = getProblemId(o[ptro])
        if ptrn < len(n):
            b = getProblemId(n[ptrn])

        if a >= b:
            ptrn += 1
        if a <= b:
            ptro += 1
        if a != b:
            diff.add(min(a, b))

    # diff.json 이라는 임시 파일로 저장
    with open("diff.json", "w") as out:
        tmp = dict()
        tmp["problems"] = list(diff)[:100]
        json.dump(tmp, out, indent='\t')
        out.close()

# 최근 Solve 업데이트
def updateRecent(recent, diff):
    if not "problems" in recent.DB.keys():
        recent.DB["problems"] = []

    for item in diff.DB["problems"]:
        if not item in recent.DB["problems"]:
            recent.DB["problems"].insert(0,item)

    while len(recent.DB["problems"]) > 100:
        recent.DB["problems"].pop()

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
            print(f"No DB to read : {file}")

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
    diff = Database()
    diff.readDB('diff.json')

    recent = Database()
    recent.readDB("recent.json")
    
    updateRecent(recent, diff)
    recent.writeDB("recent.json")




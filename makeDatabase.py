import requests  # http 요청을 위한 모듈
import json  # json 파일을 다루기 위한 모듈
from Database import Database

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

    diff = list()

    while ptro < len(o) or ptrn < len(n):
        a = 2147483647
        b = 2147483647

        if ptro < len(o):
            a = getProblemId(o[ptro])
        if ptrn < len(n):
            b = getProblemId(n[ptrn])

        if a == b:
            ptro += 1
            ptrn += 1
        if a < b:
            diff.append(o[ptro])
            ptro += 1
        if a > b:
            diff.append(n[ptrn])
            ptrn += 1

    # diff.json 이라는 임시 파일로 저장
    with open("diff.json", "w") as out:
        tmp = dict()
        tmp["problems"] = diff[:100]
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




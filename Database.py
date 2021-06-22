import requests
import json
from datetime import datetime

# 두 딕셔너리 병합
def merge(old, new):
    if len(old) == 0:
        return new

    for item in new["result"]["problems"]:
        old["result"]["problems"].append(item)

    return old

# 새로운 api에 적용
def newToOld(new, total=1, page=1):
    tmp = dict()
    tmp["success"] = True
    tmp["result"] = dict()
    tmp["result"]["total_problems"] = total
    tmp["result"]["total_page"] = page-1
    tmp["result"]["problems"] = list()
    for item in new["items"]:
        dct = dict()
        dct["id"] = item["problemId"]
        dct["level"] = item["level"]
        dct["level_locked"] = 1 if item["isLevelLocked"] else 0
        dct["solvable"] = 1 if item["isSolvable"] else 0
        dct["title"] = item["titleKo"]
        dct["solved_count"] = item["acceptedUserCount"]
        dct["average_try"] = item["averageTries"]
        tmp["result"]["problems"].append(dct)
        
    return tmp

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
        now = datetime.now()
        self.DB["last_updated"] = now.strftime("%c")

        with open(file, 'w') as f:
            json.dump(self.DB, f, indent='\t')
            f.close()

    # Save All Solved Problems on DB
    def getSolvedProblems(self, userId="ingyu1008", page=1):
        total = 1
        currentCount = 0

        while currentCount < total:
            URL = f"https://solved.ac/api/v3/search/problem?query=solved_by:{userId}&page={page}&sort=id&sort_direction=asc"
            res = requests.get(URL)

            if res.status_code == 200:
                total = res.json()["count"]
                currentCount += len(res.json()["items"])
                page += 1
                transformed = newToOld(res.json(), total, page)
                self.DB = merge(self.DB, transformed)
            else:
                print(
                    f"Error occured while requesting {URL}, Error Code {res.status_code}")
                break

        
    
    def getCFStats(self, handle):
        URL = f"https://codeforces.com/api/user.rating?handle={handle}"
        res = requests.get(URL)

        if res.status_code == 200:
            self.DB = res.json()
        else:
            print(f"Error occured while requesting {URL}, Error Code {res.status_code}")


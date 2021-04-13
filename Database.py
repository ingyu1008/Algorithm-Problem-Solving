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

        while page <= total:
            URL = f"https://api.solved.ac/v2/search/problems.json?query=solved_by:{userId}&page={page}&sort=id&sort_direction=asc"
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

import json  # json 파일을 다루기 위한 모듈
from Database import Database

if __name__ == "__main__":
    recent = Database()
    recent.readDB("recent.json")

    with open("recent.md", "w") as f:
        f.write("| 문제 번호 | 문제 이름 | 난이도 | 풀이 코드 |\n")
        for problem in recent.DB["problems"]:
            id = problem["id"]
            title = problem["title"]
            level = problem["level"]
            f.write(f"| {id} | {title} | {level} | NONE |\n")
        f.close()

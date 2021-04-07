import json  # json 파일을 다루기 위한 모듈
from Database import Database

if __name__ == "__main__":
    recent = Database()
    recent.readDB("recent.json")

    with open("recent.md", "w", encoding="utf-8") as f:
        f.write("| 문제 번호 | 문제 이름 | 난이도 | 풀이 코드 |\n")
        f.write("| --- | --- | --- | --- |\n")
        for problem in recent.DB["problems"]:
            id = problem["id"]
            title = problem["title"]
            level = problem["level"]
            f.write(f"| {id} | [{title}](https://www.acmicpc.net/problem/{id}) | <img height=\"25px\" width=\"25px=\" src=\"https://static.solved.ac/tier_small/{level}.svg\"/> | NONE |\n")
        f.close()

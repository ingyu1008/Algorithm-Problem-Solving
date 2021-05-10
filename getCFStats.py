import requests  # http 요청을 위한 모듈
import json  # json 파일을 다루기 위한 모듈
import plotly.express as px  # 데이터 시각화
from Database import Database

handle = "MatWhyTle"

if __name__ == "__main__":
    results = Database()
    results.getCFStats(handle)
    dct = results.DB

    status = dct["status"]

    if(status != "OK"):
        print(f"Error Occured\n status is {status}")
    else:
        x = []
        y = []
        for item in dct["result"]:
            x.append(item["ratingUpdateTimeSeconds"])
            y.append(item["newRating"])
        x = x[1:]
        y = y[1:]
        fig = px.line(x=x, y=y)
        fig.update_layout(xaxis_title="Time",
                          yaxis_title="Rating",)
        fig.write_image("cfStats.svg")
        fig.write_html("cfStats.html")
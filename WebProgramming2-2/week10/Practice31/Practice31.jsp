<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<%!
int[][]lectureType ={
{0, 1, 1, 0, 1}, 
{1, 0, 0, 0, 2}, 
{0, 0, 2, 0, 4}, 
{2, 3, 0, 3, 0},
{0 ,0, 0, 2, 0}, 
{0, 0, 0, 0, 0} 
};

int[][] consecutive = {
{1,2,1,1,1}, 
{2,0,1,1,1}, 
{0,1,1,1,4}, 
{2,1,1,1,0}, 
{0,1,1,2,0}, 
{1, 1, 1, 0, 0}
};

int[][] lectureTitle = {
{-1, 4, 5, -1, 5}, 
{3, -1, -1, -1, 1}, 
{-1, -1, 1, -1, 7}, 
{0, 6, -1, 6, -1}, 
{-1, -1, -1, 2, -1}, 
{-1, -1, -1, -1, -1}
};

String[] titleNames = {
"웹프로그래밍", "운영체제", "소프트웨어프로그래밍", "데이터베이스개론", "자료구조", "네트워크", "창의와감성", "사회봉사"
}; 
%>
<html>
<head>
<meta charset="UTF-8">
<title>Practice31</title>
  <style>
        table{
            border-collapse: collapse;
            text-align: center;
            width: 480px;
            height: 48px;
            font-size: 13px;
            font-family: "굴림", Gulim, Arial, sans-serif;
        }

        td {
            width: 480px;
            height: 48px;
       
        }
        
        h2 {
            text-align: center;
            font-family: "굴림", Gulim, Arial, sans-serif;
        }

        .day {
            font-size: 20px;
            font-weight: bold;
        }
        
        .yellow {
            background-color: #FFE08C;
            border: solid 1px #000000;
        }
        
        .blue {
            background-color: #B3CCFF;
            border: solid 1px #000000;
        }
        
        .gray {
            background-color: #BEBDBD;
            border: solid 1px #000000;
        }
    </style>
</head>
<body>
	  <div align = "center">
       <h2>강의 시간표</h2>
        <table border = "1">
            <tr>
                <td class = "day">2학년</td>
                <td class = "day">월</td>
                <td class = "day">화</td>
                <td class = "day">수</td>
                <td class = "day">목</td>
                <td class = "day">금</td>
            </tr>
            
            <tr>
                <td class = "day">1</td>
                <td></td>
                <td rowspan="2" class = "yellow">자료구조</td>
                <td class = "yellow">네크워크</td>
                <td></td>
                <td class = "yellow">네크워크</td>
            </tr>
            
            <tr>
                <td  class = "day">2</td>
                <td rowspan="2" class ="yellow">데이터베이스개론</td>
                <td></td>
                <td></td>
                <td class = "blue">운영체제</td>
            </tr>
            
            <tr>
                <td class = "day">3</td>
                <td></td>
                <td class = "blue">운영체제</td>
                <td></td>
                <td rowspan="4">사회봉사</td>  
            </tr>
            
            <tr>
                <td class = "day">4</td>
                <td rowspan="2" class = "blue">웹프로그래밍</td>
                <td class = "gray">창의와감성</td>
                <td></td>
                <td class = "gray">창의와감성</td>
            </tr>
            
            <tr>
                <td class = "day">5</td>
                <td></td>
                <td></td>
                <td rowspan="2" class = "blue">소프트웨어프로그래밍</td>
            </tr>
            
            <tr>
                <td class = "day">6</td>
                <td></td>
                <td></td>
            </tr>
            
        </table>
    </div>
</body>
</html>
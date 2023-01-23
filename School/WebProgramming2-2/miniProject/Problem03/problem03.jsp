   <%--20210815 컴퓨터학과 주현정 --%>

<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"  import="jspbook.pb03.*"%>
<!DOCTYPE html>
<jsp:useBean id="lecture" class="jspbook.pb03.LectureBean" />
<jsp:setProperty name="lecture" property="*" />
<jsp:useBean id="lm" class="jspbook.pb03.LectureManager" scope="application" />
<jsp:setProperty name="lm" property="*" />

<html>
<head>
<meta charset="UTF-8">
<title>Problem03</title>
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
        .class0 {
        }
        .class1 {
            background-color: #FFE08C;
        }
        
        .class2 {
            background-color: #B3CCFF;  
        }
        
        .class3 {
            background-color: #BEBDBD;
        }
    </style>
</head>
<body>
<div align="center">
<form method=post action="problem03.jsp">
	과목타입:
	<select name="type"> 
	<option value="0" selected>전공필수</option>
	<option value="1">전공선택</option>
	<option value="2">교양</option>
	<option value="3">자유선택</option>
	</select> 
	
	과목명:
	<select name="title"> 
	<option value="0" selected>웹프로그래밍</option>
	<option value="1">운영체제</option>
	<option value="2">소프트웨어프로그래밍</option>
	<option value="3">데이터베이스개론</option>
	<option value="4">자료구조</option>
	<option value="5">네트워크</option>
	<option value="6">창의와감성</option>
	<option value="7">사회봉사</option>
	</select> 
	
	요일:
	<select name="day"> 
	<option value="0" selected>월</option>
	<option value="1">화</option>
	<option value="2">수</option>
	<option value="3">목</option>
	<option value="4">금</option>
	</select> 
	
	시간:
	<select name="time"> 
	<option value="1" selected>1</option>
	<option value="2">2</option>
	<option value="3">3</option>
	<option value="4">4</option>
	<option value="5">5</option>
	<option value="6">6</option>
	<option value="7">7</option>
	</select> 
	
	연강여부:
	<select name="consecutive"> 
	<option value="1" selected>1</option>
	<option value="2">2</option>
	<option value="3">3</option>
	<option value="4">4</option>
	</select> 
	<input type="submit" value="등록">
</form>
<hr>
<%
	if(lecture.getType() != -1 && lecture.getTitle() != -1 && lecture.getDay() != -1 && lecture.getTime() != -1 && lecture.getConsecutive() != -1)
	{
		lm.add(lecture); 
		lm.buildMatrix();
	}
%>
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
<%
	int i, j;
	int type;
	String title;
	int title_num;
	int consecutive_num;
	for(i = 0; i < lm.getTimes(); i++) {
		out.println("<tr>");
		out.println("<td>" + (i + 1) + "</td>");
		for(j = 0; j < lm.getDays(); j++) {
			type = lm.getTypeMatrix()[i][j];
			title_num = lm.getTitleMatrix()[i][j];
			consecutive_num = lm.getSpanMatrix()[i][j];
			
			if(consecutive_num == 0)
				continue;
			else if(type == 0 && title_num == -1) {
				out.println("<td> </td>");
			}
			else {
				title = lecture.getTitleName(title_num);
				out.println("<td rowspan='" + consecutive_num + "' class='class" + type + "'>" + title);
				out.println("</td>");
			}
		}
		out.println("</tr>");
	}
%> 
        </table>
        <br><hr><br>
<%
		for(LectureBean lb : lm.getLectureList()) { 
			out.println(lb.toString() + "<br>");
		}
%>
</div>
</body>
</html>
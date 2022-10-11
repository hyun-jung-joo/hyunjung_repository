<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>news</title>
</head>
<body>
	<h2>오늘의 일정</h2>
	<hr>
	
<%
	String task1 = request.getParameter("TASK1");
	String task2 = request.getParameter("TASK2");
	
	if(task1 == null)
		task1 = "일정 없음";
	if(task2 == null)
		task2 = "일정 없음"; 
	
	out.println("1. " + task1 + "<br>");
	out.println("2. " + task2 );
%>
</body>
</html>
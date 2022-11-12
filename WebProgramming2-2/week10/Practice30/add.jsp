<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" import="java.util.ArrayList"%>
<!DOCTYPE html>
<%
	request.setCharacterEncoding("UTF-8");
	String[] typeNames = {"전공필수", "전공선택", "교양", "자유선택"};
	String[] titleNames = { "웹프로그래밍", "운영체제", "소프트웨어프로그래밍", "데이터베이스개론", "자료구조", "네트워크", "창의와감성", "사회봉사" };
	String[] days = {"월", "화", "수", "목", "금"};
	
	String lectureType = request.getParameter("lectureType");
	if(lectureType != null) {
		session.setAttribute("lectureType", lectureType);
	}
	
	String lectureTitle = request.getParameter("lectureTitle");
	if(lectureTitle != null){
		session.setAttribute("lectureTitle", lectureTitle);
	}
	
	String day = request.getParameter("day");
	if(day != null) {
		session.setAttribute("day", day);
	}
	
	String time = request.getParameter("time");
	if(time != null)
		session.setAttribute("time", time);
	
	String consecutive = request.getParameter("consecutive");
	if(consecutive != null)
		session.setAttribute("consecutive", consecutive);
%>
<html>
<head>
<meta charset="UTF-8">
<title>add</title>
</head>
<body>
<div align = "center">
<%
	lectureType = typeNames[Integer.parseInt((String)session.getAttribute("lectureType"))];	
	lectureTitle = titleNames[Integer.parseInt((String)session.getAttribute("lectureTitle"))];
	day = days[Integer.parseInt((String)session.getAttribute("day"))];
	time = (String)session.getAttribute("time");
	consecutive = (String)session.getAttribute("consecutive");
	
	
	ArrayList<String> timetable= (ArrayList<String>)application.getAttribute("timetable");
	if(timetable == null)
		timetable = new ArrayList<String>();
	timetable.add(lectureType + "/" + lectureTitle + "/" + day + "/" + time + "/" + consecutive);
	application.setAttribute("timetable", timetable);
	
	if(timetable != null) {
		for(String timetables : timetable)
			out.println(timetables + "<BR>");	
	}
%>
</div>
</body>
</html>
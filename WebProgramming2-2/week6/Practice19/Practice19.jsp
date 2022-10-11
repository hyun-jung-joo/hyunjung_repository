<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" import ="java.util.Calendar" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Calendar</title>
<style>
	h3 {
		text-align : right;
	}
</style>
</head>
<body>
	
<%
	Calendar cal = Calendar.getInstance();
	
	int year = cal.get(Calendar.YEAR);
	int month = cal.get(Calendar.MONTH);
	int date = cal.get(Calendar.DATE);
	int day = cal.get(Calendar.DAY_OF_WEEK);
	String[] days = {"일", "월", "화", "수", "목", "금", "토"};
	String day_name = days[day - 1];
	
	int startDay = cal.get(Calendar.DAY_OF_WEEK);
	int end = cal.getActualMaximum(Calendar.DAY_OF_MONTH);
	

	int i;
	int j = startDay;
	
	out.println("<h3>" + year + "-" + (month + 1) + "-" + day + "</h3>");
	
	for(i = 0; i < startDay - 1; i++) {
		out.print("<td>&nbsp;</td>");
	}
	
	for(i = 1; i <= end; i++) {
		out.print(i + "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;");
		if(j % 7 == 0) 
			out.print("<br>");
		
		j++;
	}
	
%>	
	
</body>
</html>
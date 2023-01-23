   <%--20210815 컴퓨터학과 주현정 --%>

<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" import ="java.util.Calendar" %>
    <%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>    
<%!
	public String parseDay(int cnt, String day)
	{
		if(cnt % 7 == 0)
			return "<font color = 'red'>" + day + "</font>";
		else if (cnt % 7 == 6)
			return "<font color = 'blue'>" + day + "</font>";
		else return day;
			
	}
%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Calendar</title>
<style>
	h3 {
		text-align : right;
	}
	
	table {
		border : solid 1px #000000;
		text-align : center;
		font-size : 18px;
		border-collapse : collapse;
	}
	
	.top {
		border : 0px;
	}	
	
	td {
		width : 70px;
	}
	
	.left {
		text-align : left;
	}
	.right {
		text-align : right;
	}
	.center {
		text-align : center;
	}
	
</style>
</head>
<body>
<div align = "center">
<%
	Calendar Today_cal = Calendar.getInstance();
	Calendar cal = Calendar.getInstance();
	
	int today_year = Today_cal.get(Calendar.YEAR);
	int today_month = Today_cal.get(Calendar.MONTH);
	int today_date = Today_cal.get(Calendar.DATE);
	pageContext.setAttribute("today_year", today_year);
	pageContext.setAttribute("today_month", today_month);
	pageContext.setAttribute("today_date", today_date);
	
	
	int year = today_year;
	int month = today_month;
	String sYear = request.getParameter("YEAR");
	String sMonth = request.getParameter("MONTH");
	if(sYear != null && sMonth != null) {
		year = Integer.parseInt(sYear);
		month = Integer.parseInt(sMonth);
	}
	cal.set(year, month, 1);
	pageContext.setAttribute("year", year);
	pageContext.setAttribute("month", month);
	
	int day = cal.get(Calendar.DAY_OF_WEEK);
	String[] days = {"일", "월", "화", "수", "목", "금", "토"};
	int startDay = cal.get(Calendar.DAY_OF_WEEK);
	int end = cal.getActualMaximum(Calendar.DAY_OF_MONTH);
	
	int i; 
	int j = startDay - 1;
%>
	<table class="top" border="0" width="100%" height="50px">
		<tr>
			<td class="left">
				<a href="calendar.jsp?YEAR=${year - 1 }&MONTH=${month }">◀</a>
				${year }년
				<a href="calendar.jsp?YEAR=${year + 1 }&MONTH=${month }">▶</a>
			</td>
			<td class="center">
				<c:choose>
					<c:when test="${month > 0 }">
						<a href="calendar.jsp?YEAR=${year }&MONTH=${month - 1 }">◀</a>
					</c:when>
					<c:otherwise>
						<a href>◀</a>
					</c:otherwise>
				</c:choose>
				${month + 1}월
				<c:choose>
					<c:when test="${month + 1 < 12 }">
						<a href="calendar.jsp?YEAR=${year }&MONTH=${month + 1 }">▶</a>
					</c:when>
					<c:otherwise>
						<a href>▶</a>
					</c:otherwise>
				</c:choose>
			</td>
			<td class="right">
				${today_year }-${today_month + 1 }-${today_date }
			</td>
		</tr>
	</table>
	<table border = "1" width = "100%" height ="300">
	<tr>
<%	
	for(i = 0; i < 7; i++)
		out.println("<td>" + parseDay(i, days[i]) +"</td>");		
	out.println("</tr>");
	
	out.println("<tr>");
	for(i = 0; i < startDay - 1; i++) {
		out.println("<td>&nbsp;</td>");
	}
	
	for(i = 1; i <= end; i++) {
		out.print("<td>" + parseDay(j, Integer.toString(i)) + "</td>");
		if(j % 7 == 6) {
			out.println("</tr>");
			out.println("<tr>");
		}
		j++;
	}
	
	while(j % 7 != 0) {
		out.println("<td>&nbsp;</td>");
		j++;
	}
%>	
	</tr>
	</table>
</div>	
</body>
</html>
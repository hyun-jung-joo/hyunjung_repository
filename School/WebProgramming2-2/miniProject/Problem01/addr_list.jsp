<%--20210815 컴퓨터학과 주현정 --%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" import="jspbook.pb01.*"%>
<!DOCTYPE html>
<jsp:useBean id="am" class="jspbook.pb01.AddrManager" scope="application" />

<html>
<head>
<meta charset="UTF-8">
<title>addr_list</title>
</head>
<body>
<div align="center">
<h2>주소록(전체보기)</h2>
<hr>
<a href="addr_form.jsp">주소추가</a><p>
<table border=1 width=500>
<tr><td>이름</td><td>전화번호</td><td>이메일</td><td>성별</td><td>그룹</td></tr>
<%
	int i, j;
	//rpp!! 
	int rpp = 3;
	int allpage;
	int size = am.getListSize();
	
	if(size <= rpp)
		allpage = 1;
	else if(size % rpp != 0)
		allpage = size / rpp + 1;
	else
		allpage = size / rpp;
	
	int currentPage;
	String sindex = request.getParameter("sindex");
	if(sindex == null)
		currentPage = 1;
	else
		currentPage = Integer.parseInt(sindex);

	AddrBean ab = null;
	int startIndex = rpp * (currentPage - 1);
	int lastIndex = startIndex + rpp;
	for(j = startIndex; j < lastIndex; j++) {
		if(j >= size)
			break;
		else if(j >= 0) {
			ab = am.getAddr2(j);
		}
%>
<tr>
	<td><%=ab.getUsername() %></td>
	<td><%=ab.getTel() %></td>
	<td><%=ab.getEmail() %></td>
	<td><%=ab.getGender() %></td>
	<td><%=ab.getGroupTitle() %></td>
</tr>
<%
	}
%>
</table>
<%	
	for(i = 1; i <= allpage; i++) {
		if(i == currentPage) {
			out.print(i);
		}
		else { 
			out.print("<a href=\"addr_list.jsp?sindex=" + i + "\">" + i + "</a>");
		}
		
		if(i != allpage) {
			out.print("|");
		}
	}
%>
</div>
</body>
</html>